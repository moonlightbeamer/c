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

bool check1D(const int Size, char puzzle[][Size], const int wordSize,
             char* word, int rowLoc, int colLoc, int dir);

void printDirection(int dir);

int main(void) {
  const int Size = 20;
  char puzzle[Size][Size];
  readWordPuzzle(Size, puzzle);
  int wordSize = 0;
  char* word = readWord(
      &wordSize);  // char*word is pointer to word that user wants to find
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
            char* word) {
  // keeps track of whether word was found or not

  // loops through row and columns; through every element
  for (int row = 0; row < Size; row++) {
    for (int col = 0; col < Size; col++) {
      // if found match for first character
      if (puzzle[row][col] == word[0]) {
        // loop to input all directions in check1D
        for (int dir = 1; dir <= 8; dir++) {
          // check1D checks for the entire word in one direction.
          if (check1D(Size, puzzle, wordSize, word, row, col, dir)) {
            // if whole word found in that direction
            printWord(word, wordSize);
            printf(" can be found at row , col = (%d, %d) in the ", row + 1,
                   col + 1);
            printDirection(dir);
            printf("direction.\n");

            // return to main
            return;
          }
        }
      }
    }
  }

  // after done looping through every element to check first letter
  // if word isn't found, if did not exit out of function...
  printWord(word, wordSize);
  printf(" cannot be found!\n");
}

bool check1D(const int Size, char puzzle[][Size], const int wordSize,
             char* word, int rowLoc, int colLoc, int dir) {
  // pass current row first letter was found to rowLoc, current col first letter
  // was found col to colLoc (row, col) char* word holds address to word that
  // user wants to find dir = assign each direction a number
  // 5 4 3
  // 6 * 2
  // 7 8 1

  bool charMatch = true;  // charMatch = true/1
  int index = 1;

  while (charMatch && index < wordSize) {
    // for some reason doesn't work. i bet inBounds doesn't work.
    // if (inBounds(rowLoc + index, colLoc + index, Size) &&
    //     inBounds(rowLoc - index, colLoc - index, Size)) {
    //   continue;
    // } else {
    //   charMatch = false;
    // }

    if (dir == 1 &&
        inBounds(rowLoc + index, colLoc + index, Size)) {  // south-east
      // if it matches, charMatch still == 1 and the loop will continue. if not,
      // charMatch == 0 and loop exits
      charMatch = (puzzle[rowLoc + index][colLoc + index] == word[index]);

    } else if (dir == 2 && inBounds(rowLoc, colLoc + index, Size)) {  // east
      charMatch = (puzzle[rowLoc][colLoc + index] == word[index]);

    } else if (dir == 3 &&
               inBounds(rowLoc - index, colLoc + index, Size)) {  // north-east
      charMatch = (puzzle[rowLoc - index][colLoc + index] == word[index]);

    } else if (dir == 4 && inBounds(rowLoc - index, colLoc, Size)) {  // north
      charMatch = (puzzle[rowLoc - index][colLoc] == word[index]);

    } else if (dir == 5 &&
               inBounds(rowLoc - index, colLoc - index, Size)) {  // north-west
      charMatch = (puzzle[rowLoc - index][colLoc - index] == word[index]);

    } else if (dir == 6 && inBounds(rowLoc, colLoc - index, Size)) {  // west
      charMatch = (puzzle[rowLoc][colLoc - index] == word[index]);

    } else if (dir == 7 &&
               inBounds(rowLoc + index, colLoc - index, Size)) {  // south-west
      charMatch = (puzzle[rowLoc + index][colLoc - index] == word[index]);

    } else if (dir == 8 && inBounds(rowLoc + index, colLoc, Size)) {  // south
      charMatch = (puzzle[rowLoc + index][colLoc] == word[index]);
    } else {
      charMatch = false;
    }
    index++;
  }

  return charMatch;
}

// checks if you're at the end of a word search
// if for example you're going east,
// inbounds makes sure the search doesn't "bleed" into the next column
// implement in check1D!
bool inBounds(int row, int col,
              const int Size) {  // passed from wherever in the word search the
                                 // search function currently is at
  bool isinBound = true;
  if (row >= Size || col >= Size || row < 0 || col < 0) {
    isinBound = false;
  }
  return isinBound;
}

// convert direction index to actual direction and prints it (last resulting
// line of output)
void printDirection(int dir) {  // prints space afterwards
  if (dir == 1) {
    printf("south-east ");

  } else if (dir == 2) {
    printf("east ");

  } else if (dir == 3) {
    printf("north-east ");

  } else if (dir == 4) {
    printf("north ");

  } else if (dir == 5) {
    printf("north-west ");

  } else if (dir == 6) {
    printf("west ");

  } else if (dir == 7) {
    printf("south-west ");

  } else if (dir == 8) {
    printf("south ");
  }
}

char* readWord(int* wordSize) {
  printf("How many characters are there in the word?\n");
  scanf(" %d", wordSize);
  char* wordToFind = (char*)malloc(
      *wordSize * sizeof(char));  // dynamically allocating an array
  printf("What is the word that you are looking for?\n");
  for (int index = 0; index < *wordSize; index++) {
    scanf(" %c", &wordToFind[index]);
  }
  return wordToFind;  // returns pointer to the dynamically allocated array
                      // storing the word user wants to find
}

void readWordPuzzle(const int Size, char puzzle[][Size]) {
  printf("Please enter the word puzzle:\n");
  for (int row = 0; row < Size; row++) {
    for (int col = 0; col < Size; col++) {
      scanf(" %c", &puzzle[row][col]);
    }
  }
}

void printWordPuzzle(const int Size, char puzzle[][Size]) {
  printf("The word puzzle entered is\n");
  for (int row = 0; row < Size; row++) {
    for (int col = 0; col < Size; col++) {
      printf("%c ", puzzle[row][col]);
    }
    printf("\n");
  }
}

void printWord(char* word,
               const int wordSize) {  // doesn't print space afterwards
  for (int index = 0; index < wordSize; index++) {
    printf("%c", word[index]);
  }
}