#include <stdio.h>

int main(void){
    double metres;
    printf("Please provide a distance in metres: ");
    scanf(" %lf", &metres);

    double inches = metres*100.0/2.54;
    int yards = inches/36;
    inches = inches - yards*36;
    int feet = inches/12;
    inches = inches - feet*12;
    int inch = inches;
    double remainder = inches - inch;

    printf("%d yards, %d feet, %d inches, %.2lf remainder", yards, feet, inch, remainder);

    return 0;
}