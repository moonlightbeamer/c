#include <math.h>
#include <stdio.h>

int main(void) {
  double F;
  const double k = 8.9875 * (pow(10, 9));  // Nm^2/C^2
  double q1, q2, r;
  char prefix1, C1, prefix2, C2;

  printf("Enter the value of the two charges separated by a space: ");
  scanf("%lf%c%c %lf%c%c", &q1, &prefix1, &C1, &q2, &prefix2, &C2);
  printf("Enter distance between charges in metres: ");
  scanf("%lf", &r);

  // nC or uC?
  // q1
  if (prefix1 == 'n') {
    q1 = fabs(q1 * (pow(10, -9)));  // convert to C
  } else if (prefix1 == 'u') {
    q1 = fabs(q1 * (pow(10, -6)));  // convert to C
  }
  // q2
  if (prefix2 == 'n') {
    q2 = fabs(q2 * (pow(10, -9)));  // convert to C
  } else if (prefix2 == 'u') {
    q2 = fabs(q2 * (pow(10, -6)));  // convert to C
  }

  // Calculations
  F = k * q1 * q2 / (pow(r, 2));

  printf("The force between charges is ");
  if (F < (pow(10, -6))) {  // if force is strictly less than 1 micro Newton
    F = F * (pow(10, 9));   // use nano Newtons units
    printf("%.2lfnN (less than 1uN)\n", F);
  } else if (F <
             (pow(10, -3))) {  // if force is strictly less than 1 milli Newton
    F = F * (pow(10, 6));      // use micro Newton units
    printf("%.2lfuN (less than 1mN)\n", F);
  } else if (F < 1) {      // if force is strictly less than 1 Newton
    F = F * (pow(10, 3));  // use milli Newton units
    printf("%.2lfmN (less than 1N)\n", F);
  } else {  // otherwise
    printf("%.2lfN (1N or greater)\n", F);
  }

  return 0;
}