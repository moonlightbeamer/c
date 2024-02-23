#include <stdio.h>
#include <math.h>

int medianfunc(int p, int q, int r);

// int main(void){
//   int p, q, r, median;
//   printf("Enter 3 numbers: ");
//   scanf(" %d %d %d", &p, &q, &r);
//   median = medianfunc(p, q, r);
//   printf("The median is %d", median);
// }

// int medianfunc(int p, int q, int r){
//   int largest, median, smallest;
//   if (p >= q) {
//     if (p >= r) {
//       largest = p;
//       if (q >= r){
//         median = q;
//         smallest = 4;
//       } else {
//         median = r;
//         smallest = q;
//       }
//     } else {
//       largest = r;
//       median = p;
//       smallest = q;
//     }
//   } else {
//     if (q >= r){
//       largest = q;
//       if (p >= r){
//         median = p;
//         smallest = 4;
//       } else {
//         median = r;
//         smallest = p;
//       }
//     } else {
//       largest = r;
//       median = q;
//       smallest = p;
//     }
//   }
//   return median;
// }

int main(void){
  double exchangeRate, USD, CAD;
  printf("Enter the exchange rate (1 CAD = ? USD): ");
  scanf(" %lf", &exchangeRate);
  printf("Enter the value in US dollars: ");
  scanf(" %lf", &USD);
  
  CAD = rint((USD/exchangeRate)*100.0)/100.0;
  printf("The value in Canadian Dollars is %.6lf", CAD);
}