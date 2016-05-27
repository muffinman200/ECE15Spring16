/******************************************************************************
*
* File name: connect4.c
*
* Author: ECE15 Instructors
*         ecefifteen@gmail.com
*
*     Lab #: 4
* Problem #: 1
*
******************************************************************************/


/*-----------------------------------------------------------------------------
   Include files
-----------------------------------------------------------------------------*/
#include "connect4_functions.h"


/*=============================================================================
  Constants and definitions: Given in connect4_functions.h
=============================================================================*/


/*=============================================================================
  Global variables: None
=============================================================================*/


/*=============================================================================
  Forward function declarations: Given in connect4_functions.h
=============================================================================*/


/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

 This program plays a game of Connect-4 between the user (herein called Alice)
 and the computer. The declarations of all the functions used in this program
 are in connect4_functions.h. The definitions of these functions are expected
 in connect4_functions.c.

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

int main()
{
   int board[BOARD_SIZE_HORIZ][BOARD_SIZE_VERT] = { {0} };
   int player_num, computer_num;
   int last_move; 


   /* Ask Alice if she wants to go first */
   player_num = print_welcome();
   if (player_num == 1) computer_num = 2;
   else computer_num = 1;

   /* If Alice wants to go first, let her make a move */
   if (player_num == 1)
   {
      display_board(board);
      last_move = player_move(board,player_num);
      display_board(board);
   }


   /* The main loop */
   
   while (1)
   {
      /* Make a computer move, then display the board */
      last_move = random_move(board,computer_num);
      printf("Computer moved in column: %d\n", last_move);
      display_board(board);

      /* Check whether the computer has won */
      if (check_win_or_tie(board,last_move)) return 0;


      /* Let Alice make a move, then display the board */
      last_move = player_move(board,player_num);
      display_board(board);

      /* Check whether Alice has won */
      if (check_win_or_tie(board,last_move)) return 0;


   } /* end of while (1) */

} /* end of main() */


/*=============================================================================
  Function definitions: Expected in connect4_functions.c
=============================================================================*/


/******************************************************************************
                                End of file
******************************************************************************/
