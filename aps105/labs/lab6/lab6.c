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
  scanf(" %d", *wordSize);
  char* wordToFind = (char*)malloc(
      *wordSize * sizeof(char));  // dynamically allocating an array
  printf("What is the word that you are looking for?\n");
  for (int index = 0; index < &wordSize; index++) {  // why is it skipping this?
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