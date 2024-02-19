#include <math.h>
#include <stdio.h>

int main(void) {
  double d = 0;
  double H = 0;
  double y, alpha, difference;
  double pi = 3.14159265;

  do {
    printf(
        "Please enter the horizontal distance from the wall between 3 and 30 "
        "m:\n");
    scanf(" %lf", &d);
  } while (d < 3 || d > 30);

  do {
    printf("Please enter the target height between 3 and 6 m:\n");
    scanf(" %lf", &H);
  } while (H < 3 || H > 6);

  do {
    for (int i = 0; i <= 90; i++) {
      y = 2 + d * tan(i * pi / 180) -
          4.905 * (pow((d / (20 * cos(i * pi / 180))), 2));
      difference = fabs(y - H);
      if (difference <= 0.3) {
        alpha = i;  // equating alpha to the i value (degree)
        break;
      } else {
        continue;
      }
    }
  } while (difference > 0.3);
  printf("The angle should be %.2lf\n", alpha);

  return 0;
}