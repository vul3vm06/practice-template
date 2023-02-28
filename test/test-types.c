#include <stdio.h>
#include <stdlib.h> // for calling exit(0);
#include <unistd.h> // for calling sleep(1);

void func(char *c) { printf("func %s\n", c); }

//  option 1: with typedef
/*
typedef void (*funPtr)(char*);
funPtr papf4() {
  printf("papf4\n");
  return &func;
}
*/

//  option 2: without typedef
void (*papf4())(char *) {
  printf("papf4\n");
  return &func;
}

int main() {
  int a[5] = {1, 2, 3, 4, 5};
  int *p = (int *)(&a + 1);
  // Both undefined, AddressSanitizer: stack-buffer-overflow
  // printf("*p %d\n", (*p));
  // printf("*p - 1 %d\n", *p - 1);
  printf("*(p - 1) %d\n", *(p - 1)); // 5

  void (*(*papf1)[3])(char *);

  typedef void (*pf)(char *);
  pf(*papf2)[3];

  // papf3 is a function pointer.
  void (*papf3)(char *);
  // void(*papf3)(char *); // cannot redeclare

  void (*papf4())(char *); // papf4 is not called.
  void (*papf4())(char *); // can repreat,
                           // only if the declarations are the same.
                           // this explains why
                           // void (*signal(int sig, void (*func)(int)))(int);
                           // can repeat too.
  char c[2] = {'!', '\0'};
  // If papf4 is not defined, ld error Undefined symbols.
  (*papf4())(c);

  return 0;
}
