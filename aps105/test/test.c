#include <stdio.h>
#include <stdbool.h>

int flippableScore(int board[][26], int n, char player, int row, int col){

  // checking legal for all 8 directions and counting flippable tiles
  // aka the position's "score"
  int flippableTiles = 0; //counts total flippable tiles if player were to place a tile there
  
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

int main(){
  
}