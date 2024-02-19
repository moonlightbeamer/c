#include <stdio.h>

// px = pointer for x; py = pointer for y;
void swap(int* px,
          int* py) {  // step 2: pointer (int*) accepts the address into swap
  int temp = *px;     // int temp = *(&x) = 9
  *px = *py;          // *(&x) = *(&y)    <=>     x = y
  *py = temp;  // *(py) = temp     <=>     *(&y) = temp    <=>     y = temp;
}  // cannot de-reference temp because we want to store the value of temp into
   // *(&y) = y temp is just a value, not a pointer don't need to return
   // anything because it's void void = not returning anything to the function
   // that called swap

int main(void) {
  int x = 9, y = 13;
  printf("Before swapping: x = %d, y = %d\n", x, y);
  swap(&x, &y);  // step 1: pass the address
  printf("After swapping: x = %d, y = %d\n", x, y);
  return 0;
}
