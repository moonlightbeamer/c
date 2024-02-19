#include <stdio.h>
#include <math.h>

int main(void){
    int number = 1234; 

    int first = number/1000; //stores first digit: 1234/1000 = 1 
    number = number%1000; //discards the first digit: the remainder of 1234/1000 is 234

    int second = number/100; //234/100 = 2
    number = number%100;

    int third = number/10;
    number = number%10;

    int fourth = number;

    return 0;
}