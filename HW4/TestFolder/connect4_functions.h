/******************************************************************************
*
* File name: connect4_functions.h
*
* Author: Tasha Vanesian (ee15fzz)
*         tcvanesi@ucsd.edu
*
*     Lab #: 4
* Problem #: 1
*
* Submission Date: Sunday, December 7, 2008
*
******************************************************************************/

#ifndef CONNECT4_FUNCTIONS
#define CONNECT4_FUNCTIONS


/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@                                                                             @
@                              Include Files                                  @
@                                                                             @
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@                                                                             @
@                            Symbolic Constants                               @
@                                                                             @
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

#define BOARD_SIZE_HORIZ 7
#define BOARD_SIZE_VERT 6



/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@                                                                             @
@                      Forward Function Declarations                          @
@                                                                             @
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/


/******************************************************************************
*                                                                             *
*                        Function print_welcome()                             *
*                                                                             *
*******************************************************************************
*                                                                             *
* This function does not take any input. It prints a welcome message for      *
* Alice, asks her if she would like to make the first move, reads the input   *
* from stdin, and clears the input buffer (in case Alice enters more than one *
* character). The function returns 2 if the (first) character typed by Alice  *
* is either n or N.  In all other cases, the function returns 1.              *
*                                                                             *
******************************************************************************/
int print_welcome(void);


/******************************************************************************
*                                                                             *
*                      Function display_board()                               *
*                                                                             *
*******************************************************************************
*                                                                             *
* This function receives the board array as input, and prints the current     *
* state of the board to stdout. The function expects the value of every cell  *
* in the board array to be either 0, 1, or 2, where 1 denotes stones of the   *
* first player (printed as X) while 2 denotes stones of the second player     *
* (printed as O). A cell whose value is 0 denotes a place on the board that   *
* is not occupied by a stone of either player.                                *
*                                                                             *
* The format of the print-out follows the example below. The width of every   *
* cell is three characters, and the stone occupying this cell (if any) is the *
* middle character. Vertical lines separate between cells in the same row,    *
* while the rows themselves are separated by a line of hyphens along with '+' *
* characters. Right under the board, the function prints the indices of the   *
* columns, with each such index centered in its column.                       *
*                                                                             *
* +---+---+---+---+---+---+---+                                               *
* |   |   |   |   |   |   |   |                                               *
* +---+---+---+---+---+---+---+                                               *
* | O |   |   |   |   |   |   |                                               *
* +---+---+---+---+---+---+---+                                               *
* | X |   |   |   |   |   |   |                                               *
* +---+---+---+---+---+---+---+                                               *
* | O |   |   |   |   |   |   |                                               *
* +---+---+---+---+---+---+---+                                               *
* | O |   |   |   |   |   |   |                                               *
* +---+---+---+---+---+---+---+                                               *
* | O | X |   | X |   |   | X |                                               *
* +---+---+---+---+---+---+---+                                               *
*   1   2   3   4   5   6   7                                                 *
*                                                                             *
******************************************************************************/
void display_board(int board[][BOARD_SIZE_VERT]);


/******************************************************************************
*                                                                             *
*                         Function random_move()                              *
*                                                                             *
*******************************************************************************
*                                                                             *
* This function receives the board array and player number as input. It then  *
* makes a valid random move. To this end, the function generates uniformly at * 
* random an integer m in the range 1,2, ..., BOARD_SIZE_HORIZ using a call to *
* the rand() standard library function. It then verifies that this integer m  *
* constitutes a valid move, by calling the function is_column_full(). If m is *
* a valid move, the function returns m. If not (that is, if the m-th column   *
* is full, the function repeat the process until a valid move is generated by *
* rand(). Note that the function assumes that at least one cell in the array  *
* board is 0; otherwise it enters into an infinite~loop!                      *
*                                                                             *
* Prior to returning m, the function also updates the state of the board by   *
* making the function call update_board(board,m,computer_num).                *
*                                                                             *
******************************************************************************/
int random_move(int board[][BOARD_SIZE_VERT], int computer_num);


/******************************************************************************
*                                                                             *
*                      Function player_move()                                 *
*                                                                             *
*******************************************************************************
*                                                                             *
* This function receives the board array and player number as input. It then  *
* prompts Alice to enter her move, reads her input from stdin, and clears the *
* input buffer. If Alice enters anything other than an integer in the range   *
* 1,2, ..., BOARD_SIZE_HORIZ, the function prints "Not a valid move. Enter a  *
* column number!" to stdout and prompts Alice again to enter a move. If Alice *
* enters an integer m in the appropriate range, the function verifies that    *
* the corresponding column is not full by calling is_column_full(). If the    *
* column is full, the function prints "This column is full. Try again!" and   *
* again prompt Alice to enter a move. When Alice does (eventually) enter      *
* a valid move m, the function updates the state of the board using the call  *
* update_board(board,m,player_num) and then returns m.                        *
*                                                                             *
******************************************************************************/
int player_move(int board[][BOARD_SIZE_VERT], int player_num);


/******************************************************************************
*                                                                             *
*                    Function check_winner_or_tie()                           *
*                                                                             *
*******************************************************************************
*                                                                             *
* This function receives as input the board array and an integer last_move,   *
* which is interpreted as the index of the column where the most recent stone *
* was played. The function calls check_winner() to determine whether the game *
* has been won by either player. If so, the function prints either "Player X  *
* won!" or "Player O won!" and returns true. If there is no winner, the func- *
* tion checks whether the game is drawn: no spaces left on the board. If so,  *
* the function prints "Tie game!" and returns true. Otherwise, the function   *
* returns false, indicating that the game is not yet over.                    *
*                                                                             *
******************************************************************************/
bool check_win_or_tie(int board[][BOARD_SIZE_VERT], int last_move);


/******************************************************************************
*                                                                             *
*                    Function is_column_full()                                *
*                                                                             *
*******************************************************************************
*                                                                             *
* This function receives as input the board array and an integer m, which is  *
* is expected to be in the range 1,2, ..., BOARD_SIZE_HORIZ.  The function    *
* returns true if the m-th column of the board is full, and false otherwise.  *
*                                                                             *
******************************************************************************/
bool is_column_full(int board[][BOARD_SIZE_VERT], int m);


/******************************************************************************
*                                                                             *
*                      Function update_board()                                *
*                                                                             *
*******************************************************************************
*                                                                             *
* This function receives as input the board array, an integer m which is      *
* expected to be in the range 1,2, ..., BOARD_SIZE_HORIZ, and an integer      *
* player_num which should be either 1 or 2. It then updates the board by      *
* changing the appropriate entry in the m-th column from 0 to player_num.     *
* Note that "the m-th column of the board" actually refers to board[m-1][].   *
*                                                                             *
* The function determine which row in the m-th column to update using the     *
* rule that a stone dropped into a given column always slides down to the     *
* lowest unoccupied row in that column.                                       *
*                                                                             *
******************************************************************************/
void update_board(int board[][BOARD_SIZE_VERT], int m, int player_num);


/******************************************************************************
*                                                                             *
*                      Function check_winner()                                *
*                                                                             *
*******************************************************************************
*                                                                             *
* This function receives as input the board array and an integer last_move,   *
* which is interpreted as the index of the column where the most recent stone *
* was played. The function checks whether the placement of this most recent   *
* stone results in a win (4 stones on the board forming a consecutive horiz-  *
* ontal, vertical, or diagonal sequence). If so, the function returns the     *
* player number (either 1 or 2) of the winning player. If there is no winner, *
* the function returns 0.                                                     *
*                                                                             *
******************************************************************************/
int check_winner(int board[][BOARD_SIZE_VERT], int last_move);


/******************************************************************************
*                                                                             *
*                        Function best_move()                                 *
*                                                                             *
*******************************************************************************
*                                                                             *
* This EXTRA-CREDIT function receives the board array and a player number as  *
* input. It returns the best (valid) move m for the given board position.     *
*                                                                             *
* Prior to returning m, the function also updates the state of the board by   *
* making the function call update_board(board,m,computer_num).                *
*                                                                             *
******************************************************************************/
int best_move(int board[][BOARD_SIZE_VERT], int computer_num);


#endif

