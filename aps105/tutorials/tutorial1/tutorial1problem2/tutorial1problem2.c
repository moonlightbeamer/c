#include <stdio.h>

int main(void) {
    const double cmPerInches = 2.54; //1 inch = 2.54 cm
    double metres;
    printf("Please provide a distance in metres: ");
    scanf("%lf", &metres);

    double distInches = metres*100/cmPerInches; //converts distance in metres to distance in inches
    int inches = (int) distInches; //(int) typecasts inches to integer, truncates down
    double remainder = distInches - inches; //finds remaining inches not converted to yards, feet, inches

    //find yards
    int yards = (int) inches/36; //1 yard = 36 inches
    
    //find feet
    inches = inches%36; //finds remaining inches not converted to yards
    int feet = (int) inches/12; //1 foot = 12 inches
    
    //find inches
    inches = inches%12; //finds remaining inches not converted to feet

    printf("%d yards, %d feet, %d inches, %lf remainder\n", yards, feet, inches, remainder);

}