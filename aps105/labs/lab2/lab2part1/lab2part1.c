#include <math.h>
#include <stdio.h>

int main(void) {
  double a;
  double b;
  double c;
  double alphaDegrees;
  double alphaRadians;
  double betaDegrees;
  double betaRadians;
  double gammaDegrees;
  double gammaRadians;
  const double pi = 3.14159265;
  const double radiansPerDegrees = pi / 180;

  // Prompt inputs
  printf("Enter the length of side A: ");
  scanf("%lf", &a);
  printf("Enter the length of side B: ");
  scanf("%lf", &b);
  printf("Enter the measure of angle alpha in degrees: ");
  scanf("%lf", &alphaDegrees);

  // Calculations
  alphaRadians = alphaDegrees * radiansPerDegrees;  // Convert alpha to radians

  betaRadians = asin(b / a * sin(alphaRadians));
  betaDegrees = betaRadians / radiansPerDegrees;  // convert beta to degrees

  gammaRadians = pi - alphaRadians - betaRadians;
  gammaDegrees = gammaRadians / radiansPerDegrees;  // convert gamma to degrees

  c = a * sin(gammaRadians) / sin(alphaRadians);

  // Outputs
  printf("\nResults:\n");
  printf("Side A: %.2lf\n", a);
  printf("Side B: %.2lf\n", b);
  printf("Side C: %.2lf\n", c);
  printf("Angle Alpha: %.2lf degrees\n", alphaDegrees);
  printf("Angle Beta: %.2lf degrees\n", betaDegrees);
  printf("Angle Gamma: %.2lf degrees\n", gammaDegrees);

  return 0;
}