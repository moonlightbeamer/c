#include <math.h>
#include <stdio.h>

int main(void) {
  int n;
  double a, b;
  double area;

  do {
    area = 0;
    printf("\nPlease enter the number of rectangles (n): ");
    scanf(" %d", &n);
    if (n < 1) {
      break;
    }

    do {
      printf("Please enter the interval of integration (a b): ");
      scanf(" %lf %lf", &a, &b);
      if (a > b) {
        printf("Invalid interval!\n\n");
      }
    } while (a > b);

    for (int k = 1; k <= n; k++) {
      double deltaX = (b - a) / n; //width of interval
      double xK = a + k * deltaX;  //Ln representative point
      double xKminus1 = a + (k - 1) * deltaX;   //Rn representative point
      double xKStar = (xK + xKminus1) / 2.0;    //Mn representative point
      double ePower = -(pow(xKStar, 2));    //exponent that e is raised to the power of 
      area += exp(ePower) * deltaX; //area of kth subinterval
    }

    printf("The integral of e^-x^2 on [%.5lf, %.5lf] with n = %d is: %.5lf\n",
           a, b, n, area);

  } while (n >= 1);

  printf("Exiting.\n");

  return 0;
}