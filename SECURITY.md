# Security Policy

## Scope

This repository contains educational material and example programs. It is not
intended to provide production-ready software or security-hardened reference
implementations.

A security issue may nevertheless exist if, for example:

- an example introduces a significant vulnerability when used as documented;
- a script executes untrusted input or commands unsafely;
- credentials, tokens, personal data, or other sensitive information have been
  committed;
- a dependency used by the repository has a vulnerability that materially
  affects users of the examples;
- the build, test, or GitHub Actions configuration creates a supply-chain risk.

Ordinary bugs, incorrect output, portability problems, and insecure use outside
the documented purpose should normally be reported through the public issue
tracker.

## Supported Versions

This repository is maintained as a collection of training materials rather
than as a versioned software product. Only the current state of the default
branch is maintained. Older commits, tags, workshop versions, and forks are not
supported.

## Reporting a Vulnerability

Please do not report suspected security vulnerabilities in a public issue,
discussion, or pull request.

Report them using GitHub's private vulnerability reporting facility:

https://github.com/gjbex/REPOSITORY/security/advisories/new

If private vulnerability reporting is unavailable, contact the maintainer at
[CONTACT ADDRESS].

Please include, where possible:

- the affected file, example, or workflow;
- a description of the vulnerability and its potential impact;
- the conditions required to exploit it;
- steps or minimal code needed to reproduce it;
- any suggested mitigation;
- whether the issue has already been disclosed elsewhere.

Do not include real credentials, personal data, or destructive proof-of-concept
code.

## Response

Receipt of a report will normally be acknowledged within seven days. The issue
will then be assessed to determine whether it is in scope and whether a change
to the repository is required.

No fixed resolution time can be guaranteed. If the issue is accepted, disclosure
will be coordinated with the reporter where practical. Credit will be given
unless the reporter prefers to remain anonymous.
