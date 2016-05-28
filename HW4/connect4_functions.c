/******************************************************************************
*
* File name: connect4_functions.c
*
* Author:  Adam Schermerhorn
*          A11058370
*          ascherme@ucsd.edu
*
*
*     Lab #: 4
* Problem #: 1
*
******************************************************************************/


/*-----------------------------------------------------------------------------
   Include files
-----------------------------------------------------------------------------*/
#include "connect4_functions.h"

// If you would like to use standard library functions other than those
// declared in <stdio.h>, <stdlib.h>, <time.h>, <stdbool.h> (for which
// the #include directives are already given in connect4_functions.h), 
// you may #include the corresponding header files here.
#include <string.h>


/*=============================================================================
  Constants and definitions
=============================================================================*/

// If you would like to define constants other than BOARD_SIZE_HORIZ and 
// BOARD_SIZE_VERT, or if you would like to define new types, you may put 
// the corresponding #defines and typedefs here.


/*=============================================================================
  Global variables
=============================================================================*/

// If you would like to use global variables, declare them here.


/*=============================================================================
  Forward function declarations
=============================================================================*/

// If you would like to use functions other than those already declared in
// connect4_functions.h, put the forward declarations of these functions here.

bool check_vert(int board[][BOARD_SIZE_VERT],int last_move,int player,int row);
bool check_horiz(int board[][BOARD_SIZE_VERT],int last_move,int player,int row);
bool check_diag(int board[][BOARD_SIZE_VERT],int last_move,int player,int row);
void update_col_height(int last_move);
int get_col_height(int last_move);

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

                Function Definitions of Required Functions

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/


/******************************************************************************
*                                                                             *
*                       Function print_welcome()                              *
*                                                                             *
******************************************************************************/
int print_welcome(void)
{
   /* Declare local variables for holding input char and one for return
    * value, return value players_turn_choice is set based on input char*/
   int players_turn_choice = 0;
   char input_char;

   /* Print Welome message and prompt user for choice of whether they
    * they would like to go first, N/n for going second, anything else
    * results in going 1st */
   printf("*** Welcome to the Connect-Four game!!! ***\n");
   printf("Would you like to make the first move [y/n]: \n");


   /* while loop to get input character. Stores input in input char var
    * and then if that value is equal to newline char does not enter loop
    * this will clear the input buffer in case user put anything else afer
    * their response. */
   while( (input_char = getchar()) != '\n') 
   {
      // only set players choice once so it will not be changed by extra
      // input. Does this by checking to see if it has been changed from 
      // its initialization value 0. If it is not then doesnt change it,
      // only proceeds to loop through input to clear buffer
      if(players_turn_choice == 0)
      {
         // if input is n or N then player goes second
         if(input_char == 'n' || input_char == 'N')
         {
            players_turn_choice = 2;
         }
         else // any other input results on going first
         {
            players_turn_choice = 1;
         }
      }
   } // End While(getchar() != '\n') loop
   return players_turn_choice; // return players choice as 1 or 2
}

/******************************************************************************
*                                                                             *
*                      Function display_board()                               *
*                                                                             *
******************************************************************************/
void display_board(int board[][BOARD_SIZE_VERT])
{
   /* print board from left to right  boottom to top*/
   printf("\n");
   for(int j = 0; j < BOARD_SIZE_VERT ; j++)
   {
      /* Prints the Top Boarder of each cell */
      for(int i = 0; i < BOARD_SIZE_HORIZ; i++)
      {
         printf("+");
         printf("---");
      } // end top of cells loop
      printf("+\n");

      /* Prints each cell with the corresponding stone*/
      for(int i = 0; i < BOARD_SIZE_HORIZ; i++)
      {
         printf("|");       // print left side of cell and a space
         switch(board[i][j]) // then print stone or space based on array val
         {
            case 1:
               printf(" X ");
               break;
            case 2:
               printf(" O ");
               break;
            case 0:
               printf("   ");
               break;
            default:
               printf("   ");
         }
      } // end cell loop
      printf("|\n");
   }// end outer for loop

   /* Prints the bottom of the board*/
   for(int i = 0; i < BOARD_SIZE_HORIZ; i++)
   {
      printf("+");
      printf("---");
   } // end bottom of boardloop
   printf("+\n");

   /* Print the collumn numbers beneath the board */
   for(int i = 1; i <= BOARD_SIZE_HORIZ; i++)
   {
      printf(" %*d ",2,i);
   } // end collumn numbering loop
   printf("\n\n"); 
}

/******************************************************************************
*                                                                             *
*                      Function random_move()                                 *
*                                                                             *
******************************************************************************/
int random_move(int board[][BOARD_SIZE_VERT], int computer_num)
{
   int move = 0;
   srand(time(0));
   move = (rand() % (BOARD_SIZE_HORIZ)) + 1;
   while(is_column_full(board,move))
   {
      move = (rand() % (BOARD_SIZE_HORIZ)) + 1;
   }
   update_board(board,move,computer_num);
   return move;
}

/******************************************************************************
*                                                                             *
*                      Function player_move()                                 *
*                                                                             *
******************************************************************************/
int player_move(int board[][BOARD_SIZE_VERT], int player_num)
{
   int move;
   int read;
   while(1)
   {
      printf("Please enter your move: ");
      read = scanf("%d",&move);
      
      while(getchar() != '\n') 
      {
      } // End While(getchar() != '\n') loop

      if( read == 0 || (move < 1) || (move > BOARD_SIZE_HORIZ) )
      {
         printf("Not a valid move. Enter a column number!\n");
      }
      else if(is_column_full(board,move))
      {
         printf("This column is full. Try again!.\n");
      }
      else
      {
         update_board(board,move,player_num);
         break;
      }
   }
   return move;
  
}

/******************************************************************************
*                                                                             *
*                      Function check_win_or_tie()                            *
*                                                                             *
******************************************************************************/
bool check_win_or_tie(int board[][BOARD_SIZE_VERT], int last_move)
{
   int winner = 0;
   winner = check_winner(board,last_move); // check if there was winner
   if(winner != 0)
   {
      printf("*****************************\n");
      printf("* Player %c won!!! Game over *\n",(winner == 1) ? 'X' : 'O');
      printf("*****************************\n");
      return true;
   }
   else
   {  // if there was no winner, check to see if the board is full
      // if any column is not full then return false
      for(int i = 1; i <= BOARD_SIZE_HORIZ; i++)
      {
          if(is_column_full(board,i) == false)
	        {
	           return false;
	        }
      }
   }
   //if not win and board is full then print tie game and return true
   printf("*****************************\n");
   printf("* Game is a tie!! No winner *\n");
   printf("*****************************\n");
   return true;
}
/******************************************************************************
*                                                                             *
*                     Function is_column_full()                               *
*                                                                             *
******************************************************************************/
bool is_column_full(int board[][BOARD_SIZE_VERT], int m)
{
   if(board[m-1][0] == 0)
   {
      return false;
   }
   else
      return true;
}

/******************************************************************************
*                                                                             *
*                      Function update_board()                                *
*                                                                             *
******************************************************************************/
void update_board(int board[][BOARD_SIZE_VERT], int m, int player_num)
{
   for(int i = BOARD_SIZE_VERT - 1; i >= 0; i--)
   {
       if(board[m-1][i] == 0)
       {
          board[m-1][i] = player_num;
          break;
       }
   }
}

/******************************************************************************
*                                                                             *
*                      Function check_winner()                                *
*                                                                             *
******************************************************************************/
int check_winner(int board[][BOARD_SIZE_VERT], int last_move)
{
   int winner = 0;
   int i;
   // see what the last stone was that was played
   // to determine who the winner.
   for(i = 0; i < BOARD_SIZE_VERT; i++)
   {
      if(board[last_move-1][i] != 0)
      {
          winner = board[last_move-1][i];
          break;
      }
   }
   if( (check_vert(board,last_move-1,winner,i)) ||
       (check_horiz(board,last_move-1,winner,i))||
       (check_diag(board,last_move-1,winner,i)))
   {
      winner = winner;
   }
   else
   {
      winner = 0;
   }
   return winner;
}

/******************************************************************************
*                                                                             *
*                       Function best_move()                                  *
*                                                                             *
*******************************************************************************
*                                                                             *
*  This is the EXTRA-CREDIT function to be used for the student competition.  *
*                                                                             *
******************************************************************************/
int best_move(int board[][BOARD_SIZE_VERT], int computer_num)
{
return 0;
}






/*=============================================================================
  Function definitions of other functions
=============================================================================*/

// If you would like to use functions other than those declared in
// connect4_functions.h and implemented above, put the definitions
// of these functions here.


/******************************************************************************
*                                                                             *
*                      Function check_verticle()                                *
*                                                                             *
******************************************************************************/

bool check_vert(int board[][BOARD_SIZE_VERT],int last_move,int player,int row)
{
   int num = 0;
   for(int i = row; i < BOARD_SIZE_VERT ; i++)
   {
      if(board[last_move][i] == player)
      {
         num++;
      }
      else
      {
         break;
      }
   }
   if(num >=4)
   {
   //   printf("won by verticle from [%d][%d] :\n",cur_col,row);
      return true;
   }
   return false;
}

/******************************************************************************
*                                                                             *
*                      Function check_horizontal()                            *
*                                                                             *
******************************************************************************/

bool check_horiz(int board[][BOARD_SIZE_VERT],int last_move,int player,int row)
{
   int num = 1;
   for(int i = last_move-1; i >= 0; i--)
   {
      if(  i < 0)
      {
         break;
      }
      if(board[i][row] == player)
      {
         num++;
      }
      else
      {
         break;
      }
   }
   for(int i = last_move+1; i < BOARD_SIZE_HORIZ; i++)
   {
      if( i >= BOARD_SIZE_HORIZ)
      {
         break;
      }
      if(board[i][row] == player)
      {
         num++;
      }
      else
      {
         break;
      }
   }
   if(num >= 4)
   {
   //   printf("won by horizontal from [%d][%d] :\n",cur_col,row);
      return true;
   }
   return false;
}

/******************************************************************************
*                                                                             *
*                      Function check_diagonal()                                *
*                                                                             *
******************************************************************************/

bool check_diag(int board[][BOARD_SIZE_VERT],int last_move,int player,int row)
{
   return false;
}




/******************************************************************************
                                End of file
******************************************************************************/


