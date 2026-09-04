#!/usr/bin/env bash
#
# validation/build.sh
#
# Reproducible out-of-tree build of LSSEFT_analytic. Requires only a C++17 compiler and
# `pkg-config ginac` on PATH -- no Boost, no package-manager step. Idempotent: re-running
# reconfigures and rebuilds the same build directory in place.
#
# Usage:
#   validation/build.sh [build-dir]
#
# build-dir defaults to <repo-root>/build-validation. Nothing outside build-dir is written.

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"
BUILD_DIR="${1:-${REPO_ROOT}/build-validation}"

if ! pkg-config --exists ginac; then
  echo "validation/build.sh: pkg-config could not find 'ginac' -- is it installed?" >&2
  exit 1
fi

mkdir -p "${BUILD_DIR}"

cmake -S "${REPO_ROOT}" -B "${BUILD_DIR}" -DCMAKE_BUILD_TYPE=Release
cmake --build "${BUILD_DIR}" --target LSSEFT_analytic -j"$(getconf _NPROCESSORS_ONLN 2>/dev/null || echo 4)"

echo "validation/build.sh: built ${BUILD_DIR}/LSSEFT_analytic"
