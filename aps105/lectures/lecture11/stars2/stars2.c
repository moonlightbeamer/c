
#include <stdio.h>

//Function declaration: involves writing the function prototype/function header 
void printStars(int numStars); //the header of the function
void printLines(int numLines);

//Function implementations
void printStars(int numStars){ //4) outputs a star
    for(int star = 1; star <= numStars; star++){
        printf("*");
    }
}

//order matters! printLines cannot be before printStars
void printLines(int numLines) { //2) pass 5 to numlines
    for(int line = 1; line <= numLines; line++){
        printStars(line); //3) call printStars function: input is 1
                          //5) return back to where you originally called the function
                          //6) execute & finish the for loops until lines is incremented till 6
    }
}

//Main Function
int main(void){
    printLines(5); //1) call printLines function: input is 5
                   //7) return to main function after both for loops ithin functions are done executing
}