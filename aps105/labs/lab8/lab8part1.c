//
// Author: Angelina Zhu
//

#include "lab8part1.h"

#include <stdio.h>

bool moveIsLegal(char board[][26], int n, char player, int row, int col);

void flipTiles(char board[][26], int n, char player, int row, int col);

int flippableScore(char board[][26], int n, char player, int row, int col);

char opponentColour(char player);

bool moveAvailable(char board[][26], int n, char player);

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

  // variables
  // turn will be given to corresponding player (BWBWBW unless only one player
  // can go)
  char user, computer, turn = 'B';
  char rowLetter, colLetter;
  int row, col;
  bool gameOver = false;

  // tell user to input what colour computer plays
  printf("Computer plays (B/W): ");
  scanf(" %c", &computer);

  // assigns user colour
  user = opponentColour(computer);

  // print board
  printBoard(board, n);

  // repetition:
  // while game is not over
  while (!gameOver) {
    if (turn == computer) {
      // computer makes any legal move
      int bestScore = 0, bestRow, bestCol;

      // looping through all positions; i = row, j = col (since row and col
      // variables are already being used above)
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (moveIsLegal(board, n, computer, i, j) &&
              (flippableScore(board, n, computer, i, j) > bestScore)) {
            // if the current position is legal AND if the current flippable
            // score is larger than the best score so far change the score
            bestScore = flippableScore(board, n, computer, i, j);
            bestRow = i;
            bestCol = j;
          }
        }
      }

      // converting numbers to abcd
      rowLetter = bestRow + 97;
      colLetter = bestCol + 97;

      // flipping computer choice of best position
      printf("Computer places %c at %c%c.\n", computer, rowLetter, colLetter);
      flipTiles(board, n, computer, bestRow, bestCol);

      // print board
      printBoard(board, n);

    } else {
      // human makes move
      //  prompt user to enter move to make
      printf("Enter move for colour %c (RowCol): ", user);
      scanf(" %c%c", &rowLetter, &colLetter);

      // changing abcd to numbers
      row = rowLetter - 97;
      col = colLetter - 97;

      // checking user input validity
      if (moveIsLegal(board, n, user, row, col)) {
        // if valid, flip
        flipTiles(board, n, user, row, col);

        // print board
        printBoard(board, n);

      } else {
        // if invalid, don't flip and opposite player wins
        printf("Invalid move.\n");

        // game ends and opponent(computer) wins
        gameOver = true;
        printf("%c player wins.\n", computer);

        return 0;
      }
    }
    // checking that game is not over after above, because it's possible that
    // user entered invalid move and game is now over
    if (!gameOver) {
      if (moveAvailable(board, n, opponentColour(turn))) {
        // if the opponent to the current turn's player can go, change turn to
        // opponent
        turn = opponentColour(turn);
      } else if (moveAvailable(board, n, turn)) {
        // if opponent can't go, turn remains in the hands of current player
        printf("%c player has no valid move.\n", opponentColour(turn));
        turn = turn;
      } else {
        // neither player has a move available -> board is full

        // game is over
        gameOver = true;

        // find the winner
        int whiteScore = 0;
        int blackScore = 0;
        // loops through all positions, i = row, j = col
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            if (board[i][j] == 'W') {
              whiteScore++;
            } else if (board[i][j] == 'B') {
              blackScore++;
            }
          }
        }
        // after looping, winner is one with highest score
        if (whiteScore > blackScore) {
          printf("W player wins.\n");
        } else if (blackScore > whiteScore) {
          printf("B player wins.\n");
        }

        return 0;
      }
    }
  }
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
    // ISSUE: checklegal in direction only passes the next value and check if in
    // bounds. doesn't check current value for in bounds?
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

bool moveIsLegal(char board[][26], int n, char player, int row, int col) {
  // if the position is unoccupied or if move legal
  //(1) if space is filled with B or W, not legal
  if (board[row][col] == 'B' || board[row][col] == 'W' ||
      !positionInBounds(n, row, col)) {
    // FIX: checked position in bounds for current ORIGIN
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
  // flipping first tile
  board[row][col] = player;

  // checking legal for all 8 directions and flipping
  // south-east
  int deltaRow = 1;
  int deltaCol = 1;
  // if the move is legal in this direction
  if (checkLegalInDirection(board, n, row, col, player, deltaRow, deltaCol)) {
    int i = 1;
    while (board[row + i * deltaRow][col + i * deltaCol] != player) {
      board[row + i * deltaRow][col + i * deltaCol] = player;
      i++;
    }
  }

  // east
  deltaRow = 0;
  deltaCol = 1;
  if (checkLegalInDirection(board, n, row, col, player, deltaRow, deltaCol)) {
    int i = 1;
    while (board[row + i * deltaRow][col + i * deltaCol] != player) {
      board[row + i * deltaRow][col + i * deltaCol] = player;
      i++;
    }
  }

  // north-east
  deltaRow = -1;
  deltaCol = 1;
  if (checkLegalInDirection(board, n, row, col, player, deltaRow, deltaCol)) {
    int i = 1;
    while (board[row + i * deltaRow][col + i * deltaCol] != player) {
      board[row + i * deltaRow][col + i * deltaCol] = player;
      i++;
    }
  }

  // north
  deltaRow = -1;
  deltaCol = 0;
  if (checkLegalInDirection(board, n, row, col, player, deltaRow, deltaCol)) {
    int i = 1;
    while (board[row + i * deltaRow][col + i * deltaCol] != player) {
      board[row + i * deltaRow][col + i * deltaCol] = player;
      i++;
    }
  }

  // north-west
  deltaRow = -1;
  deltaCol = -1;
  if (checkLegalInDirection(board, n, row, col, player, deltaRow, deltaCol)) {
    int i = 1;
    while (board[row + i * deltaRow][col + i * deltaCol] != player) {
      board[row + i * deltaRow][col + i * deltaCol] = player;
      i++;
    }
  }

  // west
  deltaRow = 0;
  deltaCol = -1;
  if (checkLegalInDirection(board, n, row, col, player, deltaRow, deltaCol)) {
    int i = 1;
    while (board[row + i * deltaRow][col + i * deltaCol] != player) {
      board[row + i * deltaRow][col + i * deltaCol] = player;
      i++;
    }
  }

  // south-west
  deltaRow = 1;
  deltaCol = -1;
  if (checkLegalInDirection(board, n, row, col, player, deltaRow, deltaCol)) {
    int i = 1;
    while (board[row + i * deltaRow][col + i * deltaCol] != player) {
      board[row + i * deltaRow][col + i * deltaCol] = player;
      i++;
    }
  }

  // south
  deltaRow = 1;
  deltaCol = 0;
  if (checkLegalInDirection(board, n, row, col, player, deltaRow, deltaCol)) {
    int i = 1;
    while (board[row + i * deltaRow][col + i * deltaCol] != player) {
      board[row + i * deltaRow][col + i * deltaCol] = player;
      i++;
    }
  }
}

int flippableScore(char board[][26], int n, char player, int row, int col) {
  // checking legal for all 8 directions and counting flippable tiles
  // aka the position's "score"
  int flippableTiles =
      0;  // counts total flippable tiles if player were to place a tile there

  // south-east
  int deltaRow = 1;
  int deltaCol = 1;
  // if the move is legal in this direction
  if (checkLegalInDirection(board, n, row, col, player, deltaRow, deltaCol)) {
    int i = 1;
    while (board[row + i * deltaRow][col + i * deltaCol] != player) {
      flippableTiles++;
      i++;
    }
  }

  // east
  deltaRow = 0;
  deltaCol = 1;
  if (checkLegalInDirection(board, n, row, col, player, deltaRow, deltaCol)) {
    int i = 1;
    while (board[row + i * deltaRow][col + i * deltaCol] != player) {
      flippableTiles++;
      i++;
    }
  }

  // north-east
  deltaRow = -1;
  deltaCol = 1;
  if (checkLegalInDirection(board, n, row, col, player, deltaRow, deltaCol)) {
    int i = 1;
    while (board[row + i * deltaRow][col + i * deltaCol] != player) {
      flippableTiles++;
      i++;
    }
  }

  // north
  deltaRow = -1;
  deltaCol = 0;
  if (checkLegalInDirection(board, n, row, col, player, deltaRow, deltaCol)) {
    int i = 1;
    while (board[row + i * deltaRow][col + i * deltaCol] != player) {
      flippableTiles++;
      i++;
    }
  }

  // north-west
  deltaRow = -1;
  deltaCol = -1;
  if (checkLegalInDirection(board, n, row, col, player, deltaRow, deltaCol)) {
    int i = 1;
    while (board[row + i * deltaRow][col + i * deltaCol] != player) {
      flippableTiles++;
      i++;
    }
  }

  // west
  deltaRow = 0;
  deltaCol = -1;
  if (checkLegalInDirection(board, n, row, col, player, deltaRow, deltaCol)) {
    int i = 1;
    while (board[row + i * deltaRow][col + i * deltaCol] != player) {
      flippableTiles++;
      i++;
    }
  }

  // south-west
  deltaRow = 1;
  deltaCol = -1;
  if (checkLegalInDirection(board, n, row, col, player, deltaRow, deltaCol)) {
    int i = 1;
    while (board[row + i * deltaRow][col + i * deltaCol] != player) {
      flippableTiles++;
      i++;
    }
  }

  // south
  deltaRow = 1;
  deltaCol = 0;
  if (checkLegalInDirection(board, n, row, col, player, deltaRow, deltaCol)) {
    int i = 1;
    while (board[row + i * deltaRow][col + i * deltaCol] != player) {
      flippableTiles++;
      i++;
    }
  }

  return flippableTiles;
}

char opponentColour(char player) {
  if (player == 'B') {
    return 'W';
  } else if (player == 'W') {
    return 'B';
  }
}

bool moveAvailable(char board[][26], int n, char player) {
  // looping through all positions
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      // if move is legal
      if (moveIsLegal(board, n, player, row, col)) {
        return true;
      }
    }
  }
  // if looped through all positions and no move is legal
  return false;
}