// test cases FAILED!!!
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// #include <time.h>

double randDouble();
bool inBounds(double x, double y);

int main(void) {
  // declaring counters & variables
  srand(42);
  int inSquare = 0, inCircle = 0, numIterations;

  // prompting & accepting user input
  printf("Number of monte carlo iterations: ");
  scanf(" %d", &numIterations);

  // generating random numbers <numIterations> number of times
  for (int i = 0; i < numIterations; i++) {
    // giving x and y a random decimal value from 0 to 1
    double x =
        randDouble();  // QUESTION: if you use srand(42) with same seed 42 every
                       // time, won't it give you the same random number (first
                       // one out of the seed's "list")? then how would there be
                       // a ratio? ANSWER: if you put the srand(42) inside the
                       // for loop, the above will happen
                       //  but if you put it at the beginning of the main
                       //  function, it will give new values every time because
                       //  it resets OUTSIDE the for loop
    double y = randDouble();  // empty because there is no input
    if (inBounds(x, y) == true) {
      inCircle++;
      inSquare++;
    } else if (inBounds(x, y) == false) {
      inSquare++;
    }
  }

  // calculating pi
  double ratio = ((double)inCircle) / ((double)inSquare);
  double pi = 4.0 * ratio;  // why is it returning 4.0000 instead of 3.6000

  printf("Pi: %.4lf", pi);
}

double randDouble() {                          // no input
  return (double)rand() / ((double)RAND_MAX);  // returns value from 0 to 1
}

bool inBounds(double x, double y) {
  double isCircle = (pow(x, 2)) + (pow(y, 2));
  // if x is greater than 0 and y is greater than 0, the coordinate is in the
  // top right quadrant if isCircle is lesser or equal to 1, that means the
  // circle it makes has radius 1 or smaller, meaning the point is inside the
  // circle
  if (x >= 0 && y >= 0 && isCircle <= 1) {
    return true;
    // if isCircle is greater than one, that means the circle it makes has
    // radius larger than 1, meaning the point is outside the circle (but still
    // in the top right quadrant)
  } else if (x >= 0 && y >= 0 && isCircle > 1) {
    return false;
  }
}
