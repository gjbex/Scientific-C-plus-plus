#!/usr/bin/env bash
set -uo pipefail

usage() {
  cat <<'EOF'
Usage: build_all.sh [options]

Build all independent CMake projects below this repository root while
excluding CMake artifact directories such as build/.

Options:
  --build-root <dir>   Root directory for generated build trees.
                       Default: <repo>/_build_all
  --build-type <type>  CMake build type. Default: Release
  --jobs <N>           Parallel build jobs. Default: auto-detected
  --no-test            Skip running ctest after each build
  --help               Show this help message
EOF
}

repo_root="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
build_root="${repo_root}/_build_all"
build_type='Release'
run_tests=1

if command -v nproc >/dev/null 2>&1; then
  jobs="$(nproc)"
else
  jobs=4
fi

while (($#)); do
  case "$1" in
    --build-root)
      build_root="$2"
      shift 2
      ;;
    --build-type)
      build_type="$2"
      shift 2
      ;;
    --jobs)
      jobs="$2"
      shift 2
      ;;
    --no-test)
      run_tests=0
      shift
      ;;
    --help)
      usage
      exit 0
      ;;
    *)
      printf 'Unknown option: %s\n\n' "$1" >&2
      usage >&2
      exit 2
      ;;
  esac
done

mkdir -p "$build_root"

mapfile -t project_dirs < <(
  find "$repo_root" \
    \( -type d \
      \( -name '.git' -o -name 'build' -o -name '_build' \
         -o -name '_build_all' -o -name 'CMakeFiles' \) \
      -prune \) \
    -o \( -type f -name 'CMakeLists.txt' -print \) \
  | sed 's|/CMakeLists.txt$||' \
  | awk -v root="$repo_root" '$0 != root' \
  | sort -u
)

if ((${#project_dirs[@]} == 0)); then
  printf 'No CMake subprojects found below %s\n' "$repo_root" >&2
  exit 1
fi

failures=()

printf 'Found %d CMake subproject(s).\n' "${#project_dirs[@]}"

for src_dir in "${project_dirs[@]}"; do
  rel="${src_dir#"${repo_root}/"}"
  bld_dir="${build_root}/${rel}"

  printf '\n==> [%s] configure\n' "$rel"
  if ! cmake -S "$src_dir" -B "$bld_dir" -DCMAKE_BUILD_TYPE="$build_type"; then
    failures+=("${rel}: configure")
    continue
  fi

  printf '==> [%s] build\n' "$rel"
  if ! cmake --build "$bld_dir" -j "$jobs"; then
    failures+=("${rel}: build")
    continue
  fi

  if ((run_tests)); then
    printf '==> [%s] test\n' "$rel"
    if ! ctest --test-dir "$bld_dir" --output-on-failure; then
      failures+=("${rel}: test")
    fi
  fi
done

if ((${#failures[@]} > 0)); then
  printf '\nCompleted with %d failure(s):\n' "${#failures[@]}" >&2
  printf '  - %s\n' "${failures[@]}" >&2
  exit 1
fi

printf '\nAll projects completed successfully.\n'
