// https://graphics.stanford.edu/~seander/bithacks.html

#include <stdio.h>
#include <stdlib.h> // fix warning: implicit declaration of function 'atoi' is invalid in C99

// CHAR_BIT is the number of bits per byte (normally 8).
int const CHAR_BIT = 8;

int main(int argc, char **argv) {
  int v; // we want to find the absolute value of v
  int shift;
  int mask;
  unsigned int r; // the result goes here

  for (int i = 1; i < argc; i++) {
    v = atoi(argv[i]);

    shift = sizeof(int) * CHAR_BIT - 1;
    mask = v >> shift;

    // patent variation: r = (v ^ mask) - mask;
    r = (v + mask) ^ mask;

    printf("v: %d\n", v);
    printf("shift: %d\n", shift);
    printf("mask: %d\n", mask);
    printf("r: %u\n\n", r);
  }

  return 0;
}
