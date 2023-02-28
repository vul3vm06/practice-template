# Handy template for c++ practice.

## Use llvm on Mac to detect memory leak by -fsanitize=address.
  1. brew install llvm
  2. PATH="/usr/local/opt/llvm/bin:$PATH"
  3. Assing CC and CXX in Makefile
  4. Execute with ASAN_OPTIONS=detect_leaks=1
