#!/usr/bin/env python3
"""Benchmark runtime and static quadrature dispatch implementations."""

from __future__ import annotations

import argparse
import importlib.util
import json
import logging
import math
import os
import platform
import shlex
import shutil
import subprocess
import sys
import tempfile
from dataclasses import dataclass
from datetime import datetime
from pathlib import Path


ROOT_DIR = Path(__file__).resolve().parent
SKILL_BENCHMARK_HELPER = Path(
    "/home/gjb/conf/config_files/codex/.codex/skills/"
    "scientific-cli-benchmark/scripts/simple_benchmark.py"
)
EXECUTABLES = {
    "runtime_virtual": "bench_runtime.exe",
    "crtp_static": "bench_crtp.exe",
    "duck_typing_static": "bench_duck_typing.exe",
    "duck_typing_template_static": "bench_duck_typing_template.exe",
}


@dataclass(frozen=True)
class BenchmarkSummary:
    """Store one benchmark result row."""

    dispatch: str
    mean_seconds: float
    stddev_seconds: float
    ns_per_integral: float
    checksum: str
    command: list[str]


def parse_arguments() -> argparse.Namespace:
    """Parse command-line options."""

    parser = argparse.ArgumentParser(
        description="Benchmark quadrature dispatch variants.",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter,
    )
    parser.add_argument(
        "--build-dir",
        type=Path,
        default=ROOT_DIR / "build",
        help="Directory containing the benchmark executables.",
    )
    parser.add_argument(
        "--repetitions",
        type=int,
        default=100_000,
        help="Number of workload repetitions per timed process.",
    )
    parser.add_argument(
        "--warmup-runs",
        type=int,
        default=2,
        help="Number of process-level warmup runs before timing.",
    )
    parser.add_argument(
        "--runs",
        type=int,
        default=7,
        help="Number of measured process-level timing runs.",
    )
    parser.add_argument(
        "--simpson-panels",
        type=int,
        default=100,
        help="Number of Simpson panels passed to Simpson benchmarks.",
    )
    parser.add_argument(
        "--sanity-repetitions",
        type=int,
        default=100,
        help="Repetitions used for checksum sanity checks.",
    )
    parser.add_argument(
        "--backend",
        choices=("auto", "hyperfine", "skill-helper"),
        default="auto",
        help=(
            "Timing backend. 'skill-helper' uses the scientific-cli-benchmark "
            "simple_benchmark.py helper."
        ),
    )
    parser.add_argument(
        "--log-level",
        default="INFO",
        help="Python logging level for benchmark progress messages.",
    )
    parser.add_argument(
        "--json-output",
        type=Path,
        help="Optional path for JSON output with the benchmark table.",
    )
    return parser.parse_args()


def validate_arguments(args: argparse.Namespace) -> None:
    """Reject invalid benchmark parameters."""

    if args.repetitions < 1:
        raise ValueError("--repetitions must be at least 1.")
    if args.warmup_runs < 0:
        raise ValueError("--warmup-runs must be non-negative.")
    if args.runs < 1:
        raise ValueError("--runs must be at least 1.")
    if args.simpson_panels < 2 or args.simpson_panels % 2 != 0:
        raise ValueError("--simpson-panels must be a positive even integer.")
    if args.sanity_repetitions < 1:
        raise ValueError("--sanity-repetitions must be at least 1.")


def configure_logging(level_name: str) -> None:
    """Configure progress logging."""

    logging.basicConfig(
        level=getattr(logging, level_name.upper(), logging.INFO),
        format="%(levelname)s: %(message)s",
    )


def load_skill_benchmark_helper():
    """Load the benchmark helper shipped with the benchmark skill."""

    if not SKILL_BENCHMARK_HELPER.is_file():
        msg = f"Missing skill helper: {SKILL_BENCHMARK_HELPER}"
        raise FileNotFoundError(msg)

    spec = importlib.util.spec_from_file_location(
        "scientific_cli_simple_benchmark",
        SKILL_BENCHMARK_HELPER,
    )
    if spec is None or spec.loader is None:
        msg = f"Failed to load helper from {SKILL_BENCHMARK_HELPER}"
        raise ImportError(msg)

    module = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = module
    spec.loader.exec_module(module)
    return module


def choose_backend(requested_backend: str) -> str:
    """Resolve backend='auto' to a concrete timing backend."""

    if requested_backend != "auto":
        return requested_backend
    if shutil.which("hyperfine") is not None:
        return "hyperfine"
    return "skill-helper"


def run_case(command: list[str]) -> str:
    """Execute one benchmark command and return stdout."""

    completed = subprocess.run(
        command,
        check=True,
        capture_output=True,
        text=True,
    )
    return completed.stdout.strip()


def parse_key_value_output(output: str) -> dict[str, str]:
    """Parse key=value benchmark executable output."""

    result = {}
    for field in output.split():
        if "=" not in field:
            continue
        key, value = field.split("=", maxsplit=1)
        result[key] = value
    return result


def benchmark_command(
    executable: Path,
    repetitions: int,
    simpson_panels: int,
) -> list[str]:
    """Build a benchmark executable command."""

    return [
        str(executable),
        str(repetitions),
        str(simpson_panels),
    ]


def print_context(args: argparse.Namespace, backend: str) -> None:
    """Print benchmark and machine context."""

    print("# Benchmark context")
    print(f"date={datetime.now().astimezone().isoformat(timespec='seconds')}")
    print(f"hostname={platform.node()}")
    print(f"working_directory={Path.cwd()}")
    print(f"build_dir={args.build_dir}")
    print(f"repetitions={args.repetitions}")
    print(f"warmup_runs={args.warmup_runs}")
    print(f"runs={args.runs}")
    print(f"simpson_panels={args.simpson_panels}")
    print(f"timing_backend={backend}")
    print(f"OMP_NUM_THREADS={os.environ.get('OMP_NUM_THREADS', 'unset')}")
    print(f"OMP_PROC_BIND={os.environ.get('OMP_PROC_BIND', 'unset')}")
    print(f"OMP_PLACES={os.environ.get('OMP_PLACES', 'unset')}")

    compiler = subprocess.run(
        ["c++", "--version"],
        check=False,
        capture_output=True,
        text=True,
    )
    print(f"compiler={compiler.stdout.splitlines()[0] if compiler.stdout else 'unknown'}")

    git_commit = subprocess.run(
        ["git", "rev-parse", "--short", "HEAD"],
        check=False,
        capture_output=True,
        text=True,
        cwd=ROOT_DIR,
    )
    print(f"git_commit={git_commit.stdout.strip() or 'unknown'}")

    git_status = subprocess.run(
        ["git", "status", "--short", "--untracked-files=normal"],
        check=False,
        capture_output=True,
        text=True,
        cwd=ROOT_DIR,
    )
    print(f"git_tree={'clean' if not git_status.stdout.strip() else 'dirty'}")
    print(f"nproc={os.cpu_count() or 'unknown'}")

    lscpu = subprocess.run(
        ["lscpu"],
        check=False,
        capture_output=True,
        text=True,
    )
    if lscpu.stdout:
        print("\n".join(lscpu.stdout.splitlines()[:20]))
    print()


def run_sanity_checks(args: argparse.Namespace) -> dict[str, str]:
    """Verify matching checksums across dispatch variants."""

    print("# Sanity checks")
    reference_checksum = ""
    for dispatch, executable_name in EXECUTABLES.items():
        command = benchmark_command(
            args.build_dir / executable_name,
            args.sanity_repetitions,
            args.simpson_panels,
        )
        logging.info("sanity check dispatch=%s", dispatch)
        output = parse_key_value_output(run_case(command))
        checksum = output["checksum"]
        if not reference_checksum:
            reference_checksum = checksum
        if not math.isclose(
            float(checksum),
            float(reference_checksum),
            rel_tol=1.0e-14,
            abs_tol=1.0e-12,
        ):
            msg = (
                f"Checksum mismatch for dispatch={dispatch}: "
                f"{checksum} != {reference_checksum}"
            )
            raise RuntimeError(msg)
        print(f"sanity_ok dispatch={dispatch} checksum={checksum}")
    print()
    return {"simpson": reference_checksum}


def time_with_hyperfine(command: list[str], warmup_runs: int, runs: int) -> tuple[float, float]:
    """Benchmark one command with hyperfine and parse the JSON summary."""

    with tempfile.NamedTemporaryFile(suffix=".json", delete=False) as json_file:
        json_path = Path(json_file.name)

    try:
        subprocess.run(
            [
                "hyperfine",
                "--warmup",
                str(warmup_runs),
                "--runs",
                str(runs),
                "--export-json",
                str(json_path),
                shlex.join(command),
            ],
            check=True,
            stdout=subprocess.DEVNULL,
        )
        payload = json.loads(json_path.read_text(encoding="utf-8"))
    finally:
        json_path.unlink(missing_ok=True)

    result = payload["results"][0]
    return float(result["mean"]), float(result["stddev"])


def time_with_skill_helper(
    helper_module,
    command: list[str],
    warmup_runs: int,
    runs: int,
) -> tuple[float, float]:
    """Benchmark one command with the skill helper fallback."""

    result = helper_module.run_benchmark(
        command=command,
        base_environment={},
        cwd=None,
        threads=None,
        warmup_runs=warmup_runs,
        runs=runs,
    )
    return result.mean_seconds, result.stddev_seconds


def run_benchmark_table(
    args: argparse.Namespace,
    backend: str,
) -> list[BenchmarkSummary]:
    """Run all benchmark variants and print a compact summary table."""

    helper_module = None
    if backend == "skill-helper":
        helper_module = load_skill_benchmark_helper()

    print("# Timing results")
    print(
        f"{'dispatch':<28} {'mean_s':>14} {'stddev_s':>14} "
        f"{'ns/integral':>14} {'checksum':>24}  command"
    )

    summaries: list[BenchmarkSummary] = []
    for dispatch, executable_name in EXECUTABLES.items():
        command = benchmark_command(
            args.build_dir / executable_name,
            args.repetitions,
            args.simpson_panels,
        )
        logging.info("timing dispatch=%s", dispatch)
        output = parse_key_value_output(run_case(command))
        if backend == "hyperfine":
            mean_seconds, stddev_seconds = time_with_hyperfine(
                command,
                args.warmup_runs,
                args.runs,
            )
        else:
            mean_seconds, stddev_seconds = time_with_skill_helper(
                helper_module,
                command,
                args.warmup_runs,
                args.runs,
            )
        ns_per_integral = 1.0e9*mean_seconds/(5.0*args.repetitions)
        summary = BenchmarkSummary(
            dispatch=output["dispatch"],
            mean_seconds=mean_seconds,
            stddev_seconds=stddev_seconds,
            ns_per_integral=ns_per_integral,
            checksum=output["checksum"],
            command=command,
        )
        summaries.append(summary)
        print(
            f"{summary.dispatch:<28} "
            f"{summary.mean_seconds:14.9f} {summary.stddev_seconds:14.9f} "
            f"{summary.ns_per_integral:14.6f} {summary.checksum:>24}  "
            f"{' '.join(summary.command)}"
        )
    return summaries


def write_json_output(
    summaries: list[BenchmarkSummary],
    json_output: Path,
) -> None:
    """Write benchmark summaries to JSON."""

    payload = [
        {
            "dispatch": summary.dispatch,
            "mean_seconds": summary.mean_seconds,
            "stddev_seconds": summary.stddev_seconds,
            "ns_per_integral": summary.ns_per_integral,
            "checksum": summary.checksum,
            "command": summary.command,
        }
        for summary in summaries
    ]
    json_output.write_text(json.dumps(payload, indent=2) + "\n", encoding="utf-8")


def main() -> int:
    """Run the benchmark driver."""

    args = parse_arguments()
    validate_arguments(args)
    configure_logging(args.log_level)
    backend = choose_backend(args.backend)

    print_context(args, backend)
    run_sanity_checks(args)
    summaries = run_benchmark_table(args, backend)

    if args.json_output is not None:
        write_json_output(summaries, args.json_output)
        logging.info("wrote JSON output to %s", args.json_output)

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
