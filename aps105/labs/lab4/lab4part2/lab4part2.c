//test cases PASSED
#include <math.h>
#include <stdio.h>

int main(void) {
  int num, sevens, luckyNums = 0, remaining, digit, iterations = 0;

  do {
    sevens = 0;  // resetting seven count every time a new number is entered
    if (iterations == 0) {
      printf("Input an integer: ");
    } else if (iterations > 0) {
      printf(
          "Input an integer (0 to stop): ");  // accounts for different prompt
                                              // vocab after first prompt
    }
    scanf(" %d", &num);

    remaining = num;
    do {
      digit = abs(remaining % 10);
      if (digit == 7) {
        sevens++;
      }
      remaining = remaining / 10;
    } while (remaining != 0);

    if (sevens == 3) {
      luckyNums++;
    }
    iterations++;
  } while (num != 0);

  printf("You entered %d lucky number(s)!\n", luckyNums);
  return 0;
}