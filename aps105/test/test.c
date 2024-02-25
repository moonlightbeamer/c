// #include <math.h>
// #include <stdio.h>

// // int medianfunc(int p, int q, int r);

// // int main(void){
// //   int p, q, r, median;
// //   printf("Enter 3 numbers: ");
// //   scanf(" %d %d %d", &p, &q, &r);
// //   median = medianfunc(p, q, r);
// //   printf("The median is %d", median);
// // }

// // int medianfunc(int p, int q, int r){
// //   int largest, median, smallest;
// //   if (p >= q) {
// //     if (p >= r) {
// //       largest = p;
// //       if (q >= r){
// //         median = q;
// //         smallest = 4;
// //       } else {
// //         median = r;
// //         smallest = q;
// //       }
// //     } else {
// //       largest = r;
// //       median = p;
// //       smallest = q;
// //     }
// //   } else {
// //     if (q >= r){
// //       largest = q;
// //       if (p >= r){
// //         median = p;
// //         smallest = 4;
// //       } else {
// //         median = r;
// //         smallest = p;
// //       }
// //     } else {
// //       largest = r;
// //       median = q;
// //       smallest = p;
// //     }
// //   }
// //   return median;
// // }

// // int main(void){
// //   double exchangeRate, USD, CAD;
// //   printf("Enter the exchange rate (1 CAD = ? USD): ");
// //   scanf(" %lf", &exchangeRate);
// //   printf("Enter the value in US dollars: ");
// //   scanf(" %lf", &USD);

// //   CAD = rint((USD/exchangeRate)*100.0)/100.0;
// //   printf("The value in Canadian Dollars is %.6lf", CAD);
// // }

// // #include <stdio.h>

// // void getInput(int *outFeet, int *outInches);
// // void printOutput(int feet, int inches, int metres, int centimetres);
// // void convert(int feet, int inches, int *outMetres, int *outCentimetres);

// // int main(void){
// //   int feet, inches, metres, centimetres;
// //   int *outFeet = &feet;
// //   int *outInches = &inches;
// //   getInput (outFeet, outInches);
// //   int *outMetres = &metres;
// //   int *outCentimetres = &centimetres;
// //   convert(feet, inches, outMetres, outCentimetres);
// //   printOutput(feet, inches, metres, centimetres);
// // }

// // void getInput(int *outFeet, int *outInches){
// //   printf("Please enter the feet and inches to convert: ");
// //   scanf(" %d %d", outFeet, outInches);
// // }

// // void convert(int feet, int inches, int *outMetres, int *outCentimetres){
// //   *outCentimetres =
// //   (int)(((double)feet)*0.3048*100.0+((double)inches)/12.0*0.3048*100.0);
// //   *outMetres = (int)(*outCentimetres/100);
// //   *outCentimetres = (int)(*outCentimetres%100);
// // }

// // void printOutput(int feet, int inches, int metres, int centimetres){
// //   printf("%d feet %d inches is %d metres and %d centimetres.\n", feet,
// //   inches, metres, centimetres);
// // }

// int removeNegatives(int array[], int SIZE);

// int main(void) {
//   const int SIZE = 8;

//   int alternatingNegatives[] = {3, -1, 5, -9, 10, -6, 7, -3};

//   int *array = alternatingNegatives;

//   int numRemoved = removeNegatives(array, SIZE);
//   printf("%d negatives removed.\n", numRemoved);

//   for (int i = 0; i < SIZE; i++) {
//     printf("array[%d]: %d\n", i, array[i]);
//   }
// }

// int removeNegatives(int array[], int SIZE) {
//   int temp, counter = 0, end = SIZE - 1;
//   for (int index = 0; index < SIZE; index++) {
//     if (array[index] < 0) {
//       array[index] = 0;
//       counter++;
//       temp = array[end];
//       array[end] = array[index];
//       array[index] = temp;
//       end--;
//       index--;
//     }
//   }
// }

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void readWordPuzzle(const int Size, char puzzle[][Size]);
char* readWord(int* wordSize);
void printWordPuzzle(const int Size, char puzzle[][Size]);
void printWord(char* word, const int wordSize);

void search(const int Size, char puzzle[][Size], const int wordSize,
            char* word);

bool inBounds(int row, int col, const int Size);

int main(void) {
  const int Size = 20;
  char puzzle[Size][Size];
  readWordPuzzle(Size, puzzle);
  int wordSize = 0;
  char* word = readWord(&wordSize);
  printWordPuzzle(Size, puzzle);
  printf("The word you are looking for is\n");
  printWord(word, wordSize);
  printf("\n");
  printf("Do you want to search? (Y or N)\n");
  char isSearch;
  scanf(" %c", &isSearch);
  if (isSearch == 'Y' || isSearch == 'y') {
    search(Size, puzzle, wordSize, word);
  }
  free(word);
  return 0;
}

void search(const int Size, char puzzle[][Size], const int wordSize,
            char* word) {}

char* readWord(int* wordSize) {
  printf("How many characters are there in the word?\n");
  scanf(" %d", wordSize);
  char* wordToFind = (char*)malloc(*wordSize * sizeof(char));  // dynamically allocating an array
  printf("What is the word that you are looking for?\n");
  for (int index = 0; index < *wordSize; index++) {  // why is it skipping this?
    scanf(" %c", wordToFind[index]);
  }
  return wordToFind;
}

void readWordPuzzle(const int Size, char puzzle[][Size]) {
  printf("Please enter the word puzzle:\n");
  for (int row = 0; row < Size; row++) {
    for (int col = 0; col < Size; col++) {
      scanf(" %c", &puzzle[row][col]);
    }
  }
}

bool inBounds(int row, int col, const int Size) {}

void printWordPuzzle(const int Size, char puzzle[][Size]) {
  for (int row = 0; row < Size; row++) {
    for (int col = 0; col < Size; col++) {
      printf("%c ", puzzle[row][col]);
    }
    printf("\n");
  }
}

void printWord(char* word, const int wordSize) {
  for (int index = 0; index < wordSize; index++) {
    printf("%c", word[index]);
  }
}
