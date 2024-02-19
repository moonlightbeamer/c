#include <stdlib.h>
#include <stdio.h>

int main(void) {
    srand(time(NULL));      //sets the seed
                            //number inside the brackets determines the seed
    printf("%d\n", rand());
    printf("%d\n", rand());
    //srand(2);     //resets the seed (first number in seed 2 appears again)
    printf("%d\n", rand());

    return 0;
}