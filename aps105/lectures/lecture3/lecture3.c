
// (1)
#include <stdio.h>  //gives us access to input and output devices

// comments aren't part of the code, help you explain the code for others

// Main is a function
int main(void) {  // int is a whole number           //void means main function
                  // doesn't receive anything
  printf("Hello world!\n");  //; terminates the line of code   // \n prints a
                             //new line
  return 0;  // means reached end of program, main function executed everything
             // with no error
}

// (2) Write a program that takes input from the user the number of pizzas and
// prints how many slices there are
int main(void) {
  // Enter number of pizzas
  printf("Enter number of pizzas: \n");
  int pizzas;  // create a variable that stores user input        // * =
               // multiplication
  scanf("%d", &pizzas);  // scanf takes input from user and stores it somewhere
                   // takes 2 things:
                   // d% tells scanf we are reading an int
                   //&[variable]    why do we need &? (read chapter 5) scanf
                   //uses & to go to the "pizzas" address and change it
                   //& = address of
  int slices = pizzas * 8;  // slices hold a number = pizzas * 8
  printf("You have %d slices and %d pizzas\n", slices, pizzas);  //%d tells us
  return 0;
}

// (3) Write a program that converts inches to cm
#include <stdio.h>
int main(void) {
  double inputInches,
      outputCM;  // double = data type that stores # with decimal places
                 // comma , separates different variables created
  const double InchesToCM =
      2.54;  // set value as you’re creating it
             // const locks the value so user can't change it
  printf("Enter inches: \n");
  scanf("%lf", &inputInches);  //"between quotes": format specifier   //%d -->
                               //input is int %lf --> input is a double
  outputCM = inputInches * InchesToCM;
  printf("Number of cm is %5.2lf \n",
         outputCM);  //%.2 --> round output to 2 decimal places
                     // the number itself is kept as the whole decimal, only
                     // rounded when printing
                     //%5.2 prints 5 spaces before printing the #

  // escape sequences: sequence of characters that doesn't represent itself
  // can't print without altering

  // how to print the characters % " \ without using the escape sequences?
  printf("The grade is 99\%");  // backslash \ requires the character that comes
                                // after it to be printed

  // printf("%%") prints %
  printf("The grade is 99%%");

  // conventions
  // (1) indentation
  // (2) comment your code to explain it to your future self
  // (3) naming variables:    DON'T START WITH A NUMBER (but a number can be
  // anywhere in the middle) use camelCase: ex) inputPizzas or inputInches

  return 0;
}