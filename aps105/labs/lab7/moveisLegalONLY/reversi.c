//
// Author: Angelina Zhu
//

#include "reversi.h"

#include <stdio.h>

void printAvailableMoves(char board[][26], int n, char player);

bool moveIsLegal(char board[][26], int n, char player, int row, int col);

void flipTiles(char board[][26], int n, char player, int row, int col);

int main(void) {
  int n;
  char board[26][26];

  // asking for user input
  printf("Enter the board dimension: ");
  scanf(" %d", &n);

  // initializing board
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      if ((row == n / 2 && col == n / 2) ||
          (row == n / 2 - 1 && col == n / 2 - 1)) {
        board[row][col] = 'W';  // white
      } else if ((row == n / 2 - 1 && col == n / 2) ||
                 (row == n / 2 && col == n / 2 - 1)) {
        board[row][col] = 'B';  // black
      } else {
        board[row][col] = 'U';
      }
    }
  }

  // printing board
  printBoard(board, n);

  // prompt user to enter board configuration
  char player, rowLetter, colLetter;
  int row, col;
  printf("Enter board configuration:\n");
  scanf(" %c%c%c", &player, &rowLetter, &colLetter);
  while (player != '!' && rowLetter != '!' && colLetter != '!') {
    row = rowLetter - 97;
    col = colLetter - 97;
    board[row][col] = player;
    scanf(" %c%c%c", &player, &rowLetter, &colLetter);
  }

  // printing board
  printBoard(board, n);

  // print available moves
  // white
  player = 'W';
  printAvailableMoves(board, n, player);

  // black
  player = 'B';
  printAvailableMoves(board, n, player);

  // prompt user to enter move to make
  printf("Enter a move:\n");
  scanf(" %c%c%c", &player, &rowLetter, &colLetter);

  // changing abcd to numbers
  row = rowLetter - 97;
  col = colLetter - 97;

  // checking move is legal
  if (moveIsLegal(board, n, player, row, col)) {
    printf("Valid move.\n");
    flipTiles(board, n, player, row, col);
  } else {
    printf("Invalid move.\n");
  }

  // print final board configuration
  printBoard(board, n);

  return 0;
}

void printBoard(char board[][26], int n) {
  // printing abcd column identifier
  printf("  ");
  for (char colLetter = 'a'; ((int)colLetter - (int)'a' + 1) <= n;
       colLetter++) {
    printf("%c", colLetter);
  }
  printf("\n");

  // printing rows
  char rowLetter = 'a';
  for (int row = 0; row < n /*, ((int)rowLetter - (int)'a' + 1) <= n*/;
       row++, rowLetter++) {
    printf("%c ", rowLetter);
    for (int col = 0; col < n; col++) {
      printf("%c", board[row][col]);
    }
    printf("\n");
  }
}

bool positionInBounds(int n, int row, int col) {
  // true if:
  //(1) row is smaller than dim of board
  // or
  //(2) col is smaller than dim of board
  // or
  //(3) row is larger than or equal to 0
  // or
  //(4) col is larger than or equal to 0
  // false if none of those are true

  // return (row < n || col < n || row >= 0 || col >= 0);

  bool isinBound = true;
  if (row >= n || col >= n || row < 0 || col < 0) {
    isinBound = false;
  }
  return isinBound;
}

bool checkLegalInDirection(char board[][26], int n, int row, int col,
                           char colour, int deltaRow, int deltaCol) {
  // false if...
  // (1) not in bounds or
  // (2) not the opposite colour
  // for example:
  // if the colour we are is WHITE --> if the neighbour is NOT BLACK means...
  // (a) the neighbour is white or (b) the neighbour is U
  if (!positionInBounds(n, row + deltaRow, col + deltaCol) ||
      board[row + deltaRow][col + deltaCol] == colour ||
      board[row + deltaRow][col + deltaCol] == 'U') {
    return false;  // exits this direction, returns to moveIsLegal, moves onto
                   // next direction
  } else {
    int i = 2;  // starts at 2 because we already checked the 0th neighbour
                // (itself) and the 1st neighbour (adjacent)

    // the neighbour is the opposite colour --> want to keep checking in that
    // direction

    // want to loop until
    //(1) hit edge of board
    //(2) hit unoccupied position
    // if (1) or (2) return false
    //(3) hit our colour
    // if (3) return true;

    // this means while loop continues while
    //(A) position in bound
    // AND
    //(B) position is NOT unoccupied

    while (positionInBounds(n, row + i * deltaRow, col + i * deltaCol) &&
           board[row + i * deltaRow][col + i * deltaCol] != 'U') {
      // if (3) is met, then true
      if (board[row + i * deltaRow][col + i * deltaCol] == colour) {
        return true;
      }
      i++;
    }
    // if loop exits without hitting our colour (without returning true)
    // that means one of the conditions weren't met anymore
    // (1) or (2) is met, false
    return false;
  }
}

void printAvailableMoves(char board[][26], int n, char player) {
  printf("Available moves for %c:\n", player);
  // looping through all positions
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      // if move is legal
      if (moveIsLegal(board, n, player, row, col)) {
        char rowLetter = row + 97;
        char colLetter = col + 97;
        printf("%c%c\n", rowLetter, colLetter);
      }
      // else don't print
    }
  }
}

bool moveIsLegal(char board[][26], int n, char player, int row, int col) {
  // if the position is unoccupied or if move legal
  //(1) if space is filled with B or W, not legal
  if (board[row][col] == 'B' || board[row][col] == 'W') {
    // printf("Position (%d, %d) is occupied. Returning false.\n", row, col);
    return false;
  }

  //(2) if space is a legal move for player, legal

  // checking legal for all 8 directions

  // south-east
  int deltaRow = 1;
  int deltaCol = 1;
  // if the move is legal in this direction
  if (checkLegalInDirection(board, n, row, col, player, deltaRow, deltaCol)) {
    // printf(
    //     "Legal move at position (%d, %d) found in south-east direction (%d, "
    //     "%d).\n",
    //     row, col, deltaRow, deltaCol);
    return true;
  }

  // east
  deltaRow = 0;
  deltaCol = 1;
  if (checkLegalInDirection(board, n, row, col, player, deltaRow, deltaCol)) {
    // printf(
    //     "Legal move found at position (%d, %d) in east direction (%d,
    //     %d).\n", row, col, deltaRow, deltaCol);
    return true;
  }

  // north-east
  deltaRow = -1;
  deltaCol = 1;
  if (checkLegalInDirection(board, n, row, col, player, deltaRow, deltaCol)) {
    // printf(
    //     "Legal move found at position (%d, %d) in north-east direction (%d, "
    //     "%d).\n",
    // row, col, deltaRow, deltaCol);
    return true;
  }

  // north
  deltaRow = -1;
  deltaCol = 0;
  if (checkLegalInDirection(board, n, row, col, player, deltaRow, deltaCol)) {
    // printf(
    //     "Legal move found at position (%d, %d) in north direction (%d,
    //     %d).\n", row, col, deltaRow, deltaCol);
    return true;
  }

  // north-west
  deltaRow = -1;
  deltaCol = -1;
  if (checkLegalInDirection(board, n, row, col, player, deltaRow, deltaCol)) {
    // printf(
    //     "Legal move found at position (%d, %d) in north-west direction (%d, "
    //     "%d).\n",
    //     row, col, deltaRow, deltaCol);
    return true;
  }

  // west
  deltaRow = 0;
  deltaCol = -1;
  if (checkLegalInDirection(board, n, row, col, player, deltaRow, deltaCol)) {
    // printf(
    //     "Legal move found at position (%d, %d) in west direction (%d,
    //     %d).\n", row, col, deltaRow, deltaCol);
    return true;
  }

  // south-west
  deltaRow = 1;
  deltaCol = -1;
  if (checkLegalInDirection(board, n, row, col, player, deltaRow, deltaCol)) {
    // printf("Legal move found at position (%d, %d) in south-west direction
    // (%d, %d).\n", row, col, deltaRow, deltaCol);
    return true;
  }

  // south
  deltaRow = 1;
  deltaCol = 0;
  if (checkLegalInDirection(board, n, row, col, player, deltaRow, deltaCol)) {
    // printf(
    //     "Legal move found at position (%d, %d) in south direction (%d,
    //     %d).\n", row, col, deltaRow, deltaCol);
    return true;
  }

  // if nothing has been returned yet
  // if position is unoccupied, but not legal in any 8 directions
  // printf(
  //     "Position (%d, %d) is unoccupied, but not legal in any 8
  //     directions.\n", row, col);
  return false;
}

void flipTiles(char board[][26], int n, char player, int row, int col) {
  if (moveIsLegal(board, n, player, row, col)) {
    board[row][col] = player;
    // how to flip the rest of them in the same direction?? :(
  }
}
