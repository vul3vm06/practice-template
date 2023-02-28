// Execute with ASAN_OPTIONS=detect_leaks=1

#include <stdlib.h>
void *p;
int main() {
  p = malloc(7);
  p = 0; // The memory is leaked here.
  return 0;
}
