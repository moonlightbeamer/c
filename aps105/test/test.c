#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {
  int a = -6, b = 18;
  int result = ((a%b)+b)%b;
  printf("-6 modulo 18 is %d", result);
}

