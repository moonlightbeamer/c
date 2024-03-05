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
  for (int row = 0; row < Size; row++) {
    for (int col = 0; col < Size; col++) {
      if (puzzle[row][col] == word[0]) {
        // 5 4 3
        // 6 * 2
        // 7 8 1
        for (int dir = 1; dir <= 8; dir++) {
          // check1D checks for the entire word in one direction.
          if (check1D(Size, puzzle, wordSize, word, row, col,
                      dir)) {  // if check1D returns true = if entire word is
                               // found in that direction...
            // problem: why is it printing it out every single fucking time
            printWord(word, wordSize);
            printf(" can be found at row , col = (%d, %d) in the ", row + 1,
                   col + 1);
            printDirection(dir);
            printf("direction.\n");
          }
        }
      }
    }
  }
}

bool check1D(const int Size, char puzzle[][Size], const int wordSize,
             char* word, int rowLoc, int colLoc, int dir) {
  // pass current row first letter was found to rowLoc, current col first letter
  // was found col to colLoc (row, col) char* word holds address to word that
  // user wants to find dir = assign each direction a number 5 4 3 6   2 7 8 1
  bool charMatch = true;  // charMatch = true/1
  int index = 1;
  while (charMatch && index < wordSize) {
    // checking: if you add (# of letters in word) to current index (r,c), will
    // it go over the dimensions of the word search? flawed because what if
    // you're going backwards. if (inBounds(rowLoc+wordSize-1,
    // colLoc+wordSize-1, Size)){
    if (dir == 1) {  // south-east
      // if it matches, charMatch still == 1 and the loop will continue. if not,
      // charMatch == 0 and loop exits
      charMatch = (puzzle[rowLoc + index][colLoc + index] == word[index]);

    } else if (dir == 2) {  // east
      charMatch = (puzzle[rowLoc][colLoc + index] == word[index]);

    } else if (dir == 3) {  // north-east
      charMatch = (puzzle[rowLoc - index][colLoc + index] == word[index]);

    } else if (dir == 4) {  // north
      charMatch = (puzzle[rowLoc - index][colLoc] == word[index]);

    } else if (dir == 5) {  // north-west
      charMatch = (puzzle[rowLoc - index][colLoc - index] == word[index]);

    } else if (dir == 6) {  // west
      charMatch = (puzzle[rowLoc][colLoc - index] == word[index]);

    } else if (dir == 7) {  // south-west
      charMatch = (puzzle[rowLoc + index][colLoc - index] == word[index]);

    } else if (dir == 7) {  // south
      charMatch = (puzzle[rowLoc + index][colLoc] == word[index]);
    }
    index++;
    //}
  }
  return charMatch;
}

// figure out how to implement this
bool inBounds(int row, int col,
              const int Size) {  // passed from wherever in the word search the
                                 // search function currently is at
  bool isinBound = true;
  while (isinBound) {  // ininBound = true until otherwise
    // logic behind this function: checks if the current (r,c) index is valid
    // within the word search
    if (row >= Size || col >= Size || row < 0 || col < 0) {
      isinBound = false;
    }
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
    printf("west");

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