#include <stdio.h>

int main() {
  char prompt[44] = "The answer to life, universe, and everything";
  int answer = 42;
  printf("%s is %i.\n", prompt, answer);
  return 0;
}