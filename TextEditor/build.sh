#!/usr/bin/env bash
set -e

echo "=== Building Text Editor ==="
cmake -S . -B build
cmake --build build

echo ""
echo "=== Build complete! ==="
echo "Run with: ./build/text_editor"