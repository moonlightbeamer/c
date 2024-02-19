#include <stdio.h>
#include <math.h>

int main(void) {
  double dollars;
  double rounded;

  printf("Enter amount in dollars: ");
  scanf("%lf", dollars);

  rounded = rint(dollars * 100 / 5) * 5 / 100;
  printf("Rounded to the nearest nickel: %lf", rounded);
}