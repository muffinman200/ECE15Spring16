/******************************************************************************
 *
 * File name: connect4ShellTest.c
 *
 * Author: Daniel Heineck, adapted from Tasha Frankie
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
void copy_board(int copyMe[][BOARD_SIZE_VERT], 
      int the_copy[][BOARD_SIZE_VERT]);

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  This program tests the functions submitted by students.

  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

int main()
{
   int empty_board[BOARD_SIZE_HORIZ][BOARD_SIZE_VERT] = { {0} };
   int mycopy_board[BOARD_SIZE_HORIZ][BOARD_SIZE_VERT] = { {0} };
   int win1_board[BOARD_SIZE_HORIZ][BOARD_SIZE_VERT] = 
   { 
      {2, 1, 2, 1, 2, 1}, 
      {1, 1, 1, 1, 2, 1}, 
      {2, 2, 2, 1, 2, 1}, 
      {0, 1, 1, 2, 1, 2}, 
      {2, 1, 2, 1, 2, 1}, 
      {2, 2, 2, 1, 2, 1}, 
      {2, 1, 2, 1, 2, 1} 
   };
   int win2_board[BOARD_SIZE_HORIZ][BOARD_SIZE_VERT] = 
   { 
      {2, 1, 2, 2, 1, 1}, 
      {2, 2, 2, 1, 2, 1}, 
      {2, 1, 1, 1, 2, 1}, 
      {2, 2, 1, 2, 1, 2}, 
      {1, 1, 2, 1, 2, 1}, 
      {0, 1, 2, 1, 2, 1}, 
      {1, 1, 2, 1, 2, 1} 
   };
   int tie_board[BOARD_SIZE_HORIZ][BOARD_SIZE_VERT] = 
   { 
      {2, 1, 2, 1, 2, 1}, 
      {2, 1, 2, 1, 2, 1}, 
      {2, 1, 2, 1, 2, 1}, 
      {1, 2, 1, 2, 1, 2}, 
      {2, 1, 2, 1, 2, 1}, 
      {2, 1, 2, 1, 2, 1}, 
      {2, 1, 2, 1, 2, 1} 
   };
   int player_num;
   int last_move; 
   int i;


   printf("Testing display_board().\n\n");

   printf("Empty board:\n");
   display_board(empty_board);

   printf("Player 1 winner board :\n");
   display_board(win1_board);

   printf("**********\n\n");

   printf("Testing print_welcome().\n\n");
   for (i = 0; i < 5; i++){
       player_num = print_welcome();
       printf("Round %d, player_num = %d\n\n",i+1,player_num);
   }
   printf("**********\n\n");
   
   player_num = 1;

   printf("Testing check_winner()\n");

   if (check_winner(win1_board, 2) == 1)
       printf("Player 1 rightfully won board 1\n");
   else 
       printf("Well, that went badly. Check winner should have said player 1 won\n");

   if (check_winner(win2_board, 3) == 2)
       printf("Player 2 rightfully won board 2\n");
   else
       printf("Well, that went badly. Check winner should have said player 2 won\n");

   if (check_winner(tie_board, 4) == 0)
       printf("Sweet. Didn't accidentally find a win\n");
   else
       printf("Well, that went badly. Check winner should have said zero\n");
   
   printf("**********\n\n");

   printf("Testing check_win_or_tie()\n");
   if (check_win_or_tie(win1_board, 2))
       printf("Player 1 rightfully won board 1\n");
   else 
       printf("Well, that went badly. Check winner should have said player 1 won\n");

   if (check_win_or_tie(win2_board, 3))
       printf("Player 2 rightfully won board 2\n");
   else
       printf("Well, that went badly. Check winner should have said player 2 won\n");

   if (check_win_or_tie(tie_board, 4))
       printf("Sweet. Didn't accidentally find a win\n");
   else
       printf("Well, that went badly. Check winner should have said zero\n");
 
   printf("**********\n\n");

   printf("Testing is_column_full()\n");

   printf("Empty board:\n");
   for (i = 1; i<=7; i++)
   {
      if(is_column_full(empty_board, i))
      {
         printf("That's not right: found a full on an empty board\n");
      }
   }
   printf("\nWin1_Board (better report only one empty):\n");
   for (i = 1; i<=7; i++)
   {
      if(!is_column_full(win1_board, i))
      {
         printf("Column %d isn't full, nor should it be.\n", i);
      }
   }

   printf("**********\n\n");

   printf("Testing update_board()\n");
   printf("\nWin1_board\n");
   copy_board(win1_board, mycopy_board);
   update_board(mycopy_board, 4, 2);
   display_board(mycopy_board);

   printf("\nWin2_board\n");
   copy_board(win2_board, mycopy_board);
   update_board(mycopy_board, 6, 1);
   display_board(mycopy_board);


   printf("**********\n\n");


   /* Testing random_move() may be a bit challenging.  It should be tested 
    * after is_column_full() */
   printf("\n\n**********\n");
   printf("Testing random_move()\n");


   printf("\nOne move left, in column 4\n");
   copy_board(win1_board, mycopy_board);
   //display_board(mycopy_board);
   last_move = random_move(mycopy_board, 2);
   if (last_move == 4)
   {
        printf("Correctly made last possible move\n");
        display_board(mycopy_board);
   }
   else
      printf("Failed to find correct last move, moved %d instead.\n", last_move);

   printf("**********\n\n");

   printf("Testing player_move()\n");

   copy_board(empty_board, mycopy_board);
   for (i=0; i<10; i++)
   {

      last_move = player_move(mycopy_board, 1);
      printf("Last Move = %d\n",last_move);
   }
   display_board(mycopy_board);
   

   printf("**********\n\n");

   return 0;
} /* end of main() */


/*=============================================================================
  Function definitions: Expected in connect4_functions.c
  =============================================================================*/


void copy_board(int copyMe[][BOARD_SIZE_VERT], 
      int the_copy[][BOARD_SIZE_VERT])
{
   int i, j;
   for ( i = 0; i < BOARD_SIZE_HORIZ; i++)
      for ( j = 0; j < BOARD_SIZE_VERT; j++)
         the_copy[i][j] = copyMe[i][j];

}

/******************************************************************************
  End of file
 ******************************************************************************/

