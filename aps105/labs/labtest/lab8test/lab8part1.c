//
// Author: Angelina Zhu
//

#include <stdio.h>

#include "reversi.h"

void printAvailableMoves(char board[][26], int n, char player);

int checkValidandFlip(char board[][26], int n, char player, int row, int col, bool flip);

void flipTiles(char board[][26], char player, int row, int col, int deltaRow, int deltaCol, int flippable);

char opponentColour(char player);

bool moveAvailable(int player, char board[][26], int n);

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
  char player, computer, turn = 'B', rowLetter, colLetter;
  int row, col;

  // tell user to input what colour computer plays
  printf("Computer plays (B/W): ");
  scanf(" %c", &computer);

  // assigns user colour
  player = opponentColour(computer);

  // printing board
  printBoard(board, n);

  while (true/*game is not over*/){
    if (turn == computer){
      //computer makes any legal move
    } else {
      //human makes move
      // prompt user to enter move to make
      printf("Enter a move for colour %c (RowCol): ", player);
      scanf(" %c%c", &rowLetter, &colLetter);
      // changing abcd to numbers
      row = rowLetter - 97;
      col = colLetter - 97;
    }

    if (true/*game is not over*/){
      if(true/*moveAvailable(opponentColour(turn))*/){
        turn = opponentColour(turn);
      } else if (true/*moveAvailable(turn)*/){
        turn = turn;
      } else /*neither player has a move available*/{
        //game is over
        //find the winner
        //exit game
      }
    }
  }
  // // checking move is legal and flipping if legal
  // if (checkValidandFlip(board, n, player, row, col)) {
  //   flipTiles(board, n, player, row, col);
  // } else {
  //   printf("Invalid move.\n");
  //   printf("B");
  // }

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
    // ISSUE: checklegal in direction only passes the next value (col+i*deltaCol) and check if in
    // bounds. doesn't check current value (col) for in bounds when called by checkValidandFlip
    isinBound = false;
  }
  return isinBound;
}

//returns true if the neighbour we are checking in a direction is in bounds & is the opposite colour
bool checkLegalInDirection(char board[][26], int n, int row, int col,
                           char colour, int deltaRow, int deltaCol) {

  //true if...
  // (1) in bounds or
  // (2) is the opposite colour

  if (positionInBounds(n, row + deltaRow, col + deltaCol) ||
      board[row + deltaRow][col + deltaCol] == opponentColour(colour)) {
    return true;
  } else {
      return false;
  }
}

void printAvailableMoves(char board[][26], int n, char player) {
  printf("Available moves for %c:\n", player);
  // looping through all positions
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      // if move is legal
      if (checkValidandFlip(board, n, player, row, col, false)) {
        char rowLetter = row + 97;
        char colLetter = col + 97;
        printf("%c%c\n", rowLetter, colLetter);
      }
      // else don't print
    }
  }
}

//checks that tiles can be flipped in each direction (and flipping if prompted)
int checkValidandFlip(char board[][26], int n, char player, int row, int col, bool flip) {

  //(1) if space is filled with B or W, not legal
  if (board[row][col] == player || board[row][col] == opponentColour(player) || !positionInBounds(n, row, col)) {
    return 0;
  }

  //(2) if space is a legal move for player, legal

  // checking legal for all 8 directions

    //keeps track of how many tiles forward in a direction the checklegalindirection has checked
    int i = 0;

    //keeps track of how many tiles can be flipped
    int score = 0;

    //keeps track of if this direction can be flipped
    bool canFlip = true;

    // south-east
    int deltaRow = 1;
    int deltaCol = 1;
    
    //checking for the first neighbour first (it must be opposite colour to proceed)
    if (board[row+deltaRow][col+deltaCol] == opponentColour(player)){
      
      //increment to second neighbour
      i++;
      
      //condition to keep checking in direction: ????
      while (true){
        // if the move is legal in this direction at the ith neighbour
        if (checkLegalInDirection(board, n, row, col, player, i*deltaRow, i*deltaCol)){
          score++;
          i++;
        } else {
          canFlip = false;
          break;
        }
      }

      //if prompted to flip AND entire direction is legal --> flip
      if (flip && canFlip){
        flipTiles(board, player, row, col, deltaRow, deltaCol, score);
      }
    }

  

    // resetting i and canflip
    i = 0;
    canFlip = true;
    // east 
    deltaRow = 0;
    deltaCol = 1;


    // north-east
    deltaRow = -1;
    deltaCol = 1;
    if (checkLegalInDirection(board, n, row, col, player, i*deltaRow, i*deltaCol)) {
      return true;
    }

    // north
    deltaRow = -1;
    deltaCol = 0;
    if (checkLegalInDirection(board, n, row, col, player, i*deltaRow, i*deltaCol)) {
      return true;
    }

    // north-west
    deltaRow = -1;
    deltaCol = -1;
    if (checkLegalInDirection(board, n, row, col, player, i*deltaRow, i*deltaCol)) {
      return true;
    }

    // west
    deltaRow = 0;
    deltaCol = -1;
    if (checkLegalInDirection(board, n, row, col, player, i*deltaRow, i*deltaCol)) {
      return true;
    }

    // south-west
    deltaRow = 1;
    deltaCol = -1;
    if (checkLegalInDirection(board, n, row, col, player, i*deltaRow, i*deltaCol)) {
      return true;
    }

    // south
    deltaRow = 1;
    deltaCol = 0;
    if (checkLegalInDirection(board, n, row, col, player, i*deltaRow, i*deltaCol)) {
      return true;
    }

  // if nothing has been returned yet
  // if position is unoccupied, but not legal in any 8 directions
  return false;
}

void flipTiles(char board[][26], char player, int row, int col, int deltaRow, int deltaCol, int flippable) {
  int flipped = 1;
  while (flipped<=flippable){
    board[row + flipped*deltaRow][col + flipped*deltaCol] = player;
  }
}

char opponentColour(char player) {
  if (player == 'B') {
    return 'W';
  } else if (player == 'W') {
    return 'B';
  }
}

bool moveAvailable(int player, char board[][26], int n){
  for (int row = 0; row < n; row++){
    for (int col = 0; col < n; col++){
      if (checkValidandFlip(board, n, player, row, col, false)){
        // at least 1 location on the board has an available move for that colour
        return true;
      }
    }
  }
  //no locations on board has available move for that colour
  return false;
}