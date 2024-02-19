#include <stdio.h>
// write a function that returns a pointer to the largest double value

//returns type double*
double* largestValLoc(double*a, double*b){
    double*largest;
    if (*a > *b){ //compares the values stored in the address of a and b
        largest = a;
    } else {
        largest = b;
    }
    return largest;
}

int main(void){
    double x = 2.6, y = 7.3;
    double*p = largestValLoc(&x,&y); //largestValLoc is a function
                                     //double*p = &y
    printf("Largest value is %lf", *p);
}