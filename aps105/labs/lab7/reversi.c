//
// Author: Angelina Zhu
//

#include "reversi.h"

void printBoard(char board[][26], int n) {
    //printing abcd column identifier
    printf("  ");
    for(char colLetter = 'a'; ((int)colLetter - (int)'a' + 1) <= n; colLetter++){
        printf("%c", colLetter);
    }
    printf("\n");
    //printing rows
    for(char rowLetter = 'a'; ((int)rowLetter - (int)'a' + 1) <= n; rowLetter++){
        printf("%c ", rowLetter);


        printf("\n");
    }
}

bool positionInBounds(int n, int row, int col) {}

bool checkLegalInDirection(char board[][26], int n, int row, int col,
                           char colour, int deltaRow, int deltaCol) {}

int main(void) {
    int n;
    char board[26][26];

    //asking for user input
    printf("Enter the board dimension: ");
    scanf(" %d", &n);


    printBoard(board, n);

    return 0;
}

// peseudocode

// declare 26x26 2d array
// initialize the board

// print the board                                            1 function

// enter board configurations Bac

// print available moves for white                            1 function
// go through all positions and check if move is valid
// MOVE IS VALID                                           CHECKVALIDANDFLIP
// if position is occupied - invalid
// if position is not occupied
// is the move legal? (should flip some tiles)     1 function
// move legal for a particular position
// for each of the 8 directions            CHECKLEGALINDIRECTION
// check if the neighbouring piece is opposite of the current colour
// neighbouring position:
//(1) must be within bounds of the array
// if not --> not legal direction, return false
//(2) must be an opposite colour
// if not --> not legal direction, return false
// if in bounds && opposite color
// let's walk further in this direction
// row + i*deltaRow
// col + i*deltaCOl
// till:
//(1) hit edge of the board --> return false
//(2) hit unoccupied position --> return false
//(3) hit your colour --> this amke direction and position an available move -->
//return true
// CHECKLEGALINDIRECTIOn returns true
// move is legal

// print available moves for black                            1 function

// ask user to enter a move
// if move is valid                                            POSITIONINBOUND
// (check if row, col are within bounds ) print "valid move" flip tiles along 8
// direction through checking LEGALINDIRECTION flip tiles only when the
// direction is legal implement function can flip if we want to flip can check
// only if we want to check            CHECKVALIDANDFLIP
// else
// print invalid move
// print the board                                               1 function
