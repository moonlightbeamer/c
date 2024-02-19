#include <stdio.h>

int main(void){
    int x = 9, y = 13;
    printf("Before swapping x = %d, y= %d", x, y);
    swap(x, y);
    printf("After swapping: x = %d, y = %d", x, y);
    return 0;
}

void swap(int x, int y){ 
    int temp  = y;
    y = x;
    x = temp;
    //PROBLEM: x and y were only changed in swap (as x and y here has a variable scope)
}