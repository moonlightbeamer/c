#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPerfectSquare(int num){
    return (sqrt(num) == (int) sqrt(num));  //will return true if the equation holds, will return false if not
}       //return evaluates the statement, tells function that it should stop, and reutrn back to where isPerfectSquare was originally called in main

int main(void) {
    bool sq = isPerfectSquare(25);
}