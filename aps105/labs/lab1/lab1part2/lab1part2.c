#include <stdio.h>

int main(void) {
    double tempinFahrenheit;

    //Enter temperature in F
    printf("Enter the thermostat temperature: ");
    scanf("%lf", &tempinFahrenheit);

    //Convert temperature from F to C
    double tempinCelsius = (tempinFahrenheit-32)/(1.8);

    //Convert from 22C to F
    double twentytwoCtoF = 22*1.8+32;
    
    //Find difference in F
    double differenceinFahrenheit = tempinFahrenheit-twentytwoCtoF;

    //Print output
    printf("The temperature in Celsius is: %.1lf\n\nYou are %.1lf degrees Fahrenheit away from a nice 22 degrees Celsius.\n", tempinCelsius, differenceinFahrenheit);
    return 0;
}