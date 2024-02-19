#include <math.h>
#include <stdio.h>

int main(void) {
  int currentHour;
  int currentMinute;
  double tripTimeinHours;

  int travelHours;    // hours spent travelling
  int travelMinutes;  // minutes spent travelling

  int arrivalHour;    // hour of arrival
  int arrivalMinute;  // minute of arrival

  // Prompt input
  printf("Enter current time: ");
  scanf("%d %d", &currentHour, &currentMinute);  // enter 2 integers
  printf("Enter trip time: ");
  scanf("%lf", &tripTimeinHours);  // enter 1 decimal number

  // Calculations
  travelHours =
      (int)(tripTimeinHours);  // finds number of whole hours spent travelling

  // the remaining trip time (in minutes) NOT converted to whole hours is?
  travelMinutes = (int)(floor((tripTimeinHours - travelHours) *
                              60));  // converts remaining trip time to minutes
                                     // rounds it to the lowest minute
                                     // stores travelMinutes as an integer

  // arrival time
  arrivalHour = currentHour + travelHours;
  arrivalMinute = currentMinute + travelMinutes;
  if (arrivalMinute > 59) {  // this only needs to be done once as arrivalMinute
                             // will never exceed 59+59
    arrivalMinute = arrivalMinute - 60;
    arrivalHour = arrivalHour + 1;
  }

  // Print current time
  printf("\nCurrent time is %d:%d\n", currentHour, currentMinute);

  // Print arrival time (accounting for same day vs next day)
  if (arrivalHour * 60 + arrivalMinute > 1439) {
    arrivalHour = arrivalHour - 24;  // day resets
    printf("Arrival Time is next day ");
  } else {
    printf("Arrival Time is same day ");
  }

  // if hour has 1 digit, there should be an extra 0 in front of the hour
  if (arrivalHour >= 0 && arrivalHour <= 9) {
    printf("0%d:", arrivalHour);  // printing extra 0 in front of time
  } else {                        // if hour has 2 digits
    printf("%d:", arrivalHour);
  }

  // if minute has 1 digit, there should be an extra 0 in front of the minute
  if (arrivalMinute >= 0 && arrivalMinute <= 9) {
    printf("0%d\n", arrivalMinute);
  } else {  // if minute has 2 digits
    printf("%d\n", arrivalMinute);
  }

  return 0;
}