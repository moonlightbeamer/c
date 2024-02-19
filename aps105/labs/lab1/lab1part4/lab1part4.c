#include <stdio.h>

int main(void) {
  double dailyRate;
  int numDays;
  int freeDays;        // changed freeDays from double to integer
  double totalCharge;  // changed int to double

  const double HST = 0.13;  // changed 13 to 0.13 (percentage to fraction)

  // Get the daily rate
  printf("Enter the daily rate: ");
  scanf("%lf", &dailyRate);  // changed %d to %lf to get double

  // Get the number of rental days
  printf("Enter the rental period (in days): ");
  scanf("%d", &numDays);

  // Compute the free days
  freeDays = numDays / 4;  // finding how many WHOLE 4-day blocks there are;
  printf("\nYour total free day(s) in this rental is: %d", freeDays);

  // Compute the total charge tax inclusive
  totalCharge = (1 + HST) * (numDays - freeDays) * dailyRate;
  printf("\nThe total charge including taxes is: %.2f\n", totalCharge);
  return 0;
}