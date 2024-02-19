#include <stdio.h>

int main(void) {
  char userSign;
  int userNum;  // changed to int
  int sum = 0;
  printf("Enter sequence of numbers to add: ");
  do {
    scanf(" %c%d", &userSign, &userNum);  // put a space in front of the %c%d
    if (userSign == '+') {                // if sign is positive
      sum += userNum;
      printf("Sum is updated to %d\n", sum);
    } else {
      sum -= userNum;
      printf("Sum is updated to %d\n", sum);
    }
  } while (sum >= 0);  // changed to while sum>=0 since it only exits if sum
                       // falls BELOW 0  (can equal to)
  printf("Sum fell below zero.\n");
  return 0;
}


// int main(void) {
//   char userNum, userSign;
//   int sum = 0;
//   printf("Enter sequence of numbers to add: ");
//   do {
//     scanf(" %c%c", &userSign, &userNum);
//     if (userNum >= '0' && userNum <= '9') {
//       if (userSign == '-') {
//         sum -= (int)userNum - 48; //converting userNum from char to int and accounting for the difference (48) between actual integer value and ascii code
//       } else if (userSign == '+') {
//         sum += (int)userNum - 48;
//       }
//       printf("Sum is updated to %d\n", sum);
//     }
//   } while (sum >= 0);
//   printf("Sum fell below zero.\n");
//   return 0;
// }
