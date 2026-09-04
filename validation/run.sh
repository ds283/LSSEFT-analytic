#!/usr/bin/env bash
#
# validation/run.sh
#
# Runs LSSEFT_analytic in the canonical published-output configuration -- the invocation that
# matches the 2018 published reference output -- and nothing else by default:
#
#   ./LSSEFT_analytic --no-auto-symmetrize --symmetrize-22 --counterterms --output <dir>
#
# Note this is *not* the tool's own default (--auto-symmetrize is on by default and costs 26x
# for identical results).
#
# Usage:
#   validation/run.sh [output-dir] [build-dir]
#
# output-dir defaults to <repo-root>/validation/out/<UTC timestamp>; build-dir defaults to
# <repo-root>/build-validation (the default produced by validation/build.sh). Stdout and stderr
# are captured to run.log alongside the output directory. Nothing outside output-dir and
# build-dir is written.

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"
BUILD_DIR="${2:-${REPO_ROOT}/build-validation}"
OUTPUT_DIR="${1:-${REPO_ROOT}/validation/out/$(date -u +%Y%m%dT%H%M%SZ)}"

BINARY="${BUILD_DIR}/LSSEFT_analytic"

if [[ ! -x "${BINARY}" ]]; then
  echo "validation/run.sh: no binary at ${BINARY} -- run validation/build.sh first" >&2
  exit 1
fi

mkdir -p "${OUTPUT_DIR}"
LOG_FILE="${OUTPUT_DIR}.log"

"${BINARY}" --no-auto-symmetrize --symmetrize-22 --counterterms --output "${OUTPUT_DIR}" \
  > "${LOG_FILE}" 2>&1

echo "validation/run.sh: output in ${OUTPUT_DIR}, log in ${LOG_FILE}"
