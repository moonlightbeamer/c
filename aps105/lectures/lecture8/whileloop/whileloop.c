#include <stdio.h>

int main(void) {
  /*int sum = 0;  // declare and initialize (if uninitialized, it could store a
                // "garbage" arbitrary number and output incorrect sum)
  int num;

  printf("Enter a number: ");
  scanf("%d", &num);  // take input

  // repeat below until negative number is entered
  while (num >= 0) {    // 0 is not negative, so include 0 in the sum
    sum += num;         // add input number to sum
    scanf("%d", &num);  // scan again
  }

  printf("Sum is %d", sum);
  */

  int num;
  do {
    printf("Enter a num: ");
    scanf("%d", &num);
  } while (num < 10);  // repeating condition
                       //  as long as num<10, I want the user to enter a number

  return 0;
}