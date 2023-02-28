#include <stdio.h>

int main(void) {
  char *str[] = {"ThisIsAnOnlineTesting", "WelcomeToHere", "Hello",
                 "EverydayGenius", "HopeEverythingGood"};
  char *m = str[4] + 4;
  char *n = str[1];
  char *p = *(str + 2) + 4;
  printf("1. %s\n", *(str + 1));
  printf("2. %s\n", (str[3] + 8));
  printf("3. %c\n", *m);
  printf("4. %c\n", *(n + 3));
  printf("5. %c\n", *p + 1);
  // 1. WelcomeToHere
  // 2. Genius
  // 3. E
  // 4. c
  // 5. p
  return 0;
}
