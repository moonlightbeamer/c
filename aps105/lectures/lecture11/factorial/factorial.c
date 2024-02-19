
#include <stdio.h>

    factorial (int n){
        int product = 1;
        for (int term = 1; term <= n; term++) {
            product = term * product;
        }
        return product; //return (key word): allows communicating with the calling function
    }

/*
int main(void){
    printf("%d", factorial(4)); //"factorial(4)" gets replaced with 24
    return 0;
}
*/

//OR

int main(void){
    int value = 4;
    int factValue;
    factValue = factorial(value); //"factorial(value)" turns into 24, and factValue stores 24
}

/*
note: when factorial(value) -- call by value
    value doesn't change if n changes in factorial function
*/
