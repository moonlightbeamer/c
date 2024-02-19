#include <math.h>
#include <stdio.h>

int main(void) {
  double circumference;
  double gravity;
  const double pi = 3.1415926;
  const double Gmetres = 6.6726E-11;               // units m^3/kg*s^2
  const double Gkm = 6.6726E-11 / (pow(1000, 3));  // convert G to units km^3/kg*s^2

  // Enter circumference & gravity
  printf("Circumference (km) of planet? ");
  scanf("%lf", &circumference);  // circumference units km
  printf("Acceleration due to gravity (m/s^2) on planet? ");
  scanf("%lf", &gravity);  // gravity units m/s^2

  // Calculations
  printf("\nCalculating the escape velocity...\n");
  double radiusKM = circumference / (2*pi);             // units km
  double radiusM = radiusKM * 1000;                       // convert radius to units m
  double mass = gravity * (pow(radiusM, 2)) / (Gmetres);  // units kg
  double massScientific = mass/(pow(10, 21)); //convert mass to scientific notation units x10^(21) kg
  double escapeVelocity = sqrt((2*Gkm*mass)/radiusKM);  // units km/s

  // Output
  printf("Planet radius: %.1lf km\n", radiusKM);
  printf("Planet mass: %.1lf x 10^21 kg\n", massScientific);
  printf("Escape velocity: %.1lf km/s\n", escapeVelocity);

  return 0;
}