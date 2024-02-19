/*
#include <stdio.h>

int main() {
  for (int row = 1; row <= 5; row++) { //only when this is false, the outer loop is exited
    for (int stars = 1; stars <= row; stars++) {
      printf("*");
    }
    printf("\n");
  }
}


#include <stdio.h>

int main() {
  for (int row = 1; row <= 4; row++) { //outer loop responsible for rows
    for(int col = 1; col <= 4; col++) {    //inner loop responsible for spaces and stars
        // if statement:
        // for first row:
             // if we are in the first three columns, print a space
             // else, print a star
        if (col <= 4-row) { 
            //if column number is less than
            //4-row = #spaces we need
            printf(" "); 
        } else {
            printf("*");
        }
    }
    printf("\n");
  }
}
*/

#include <stdio.h>