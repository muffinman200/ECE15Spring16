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



/*=============================================================================
  Constants and definitions
=============================================================================*/

// If you would like to define constants other than BOARD_SIZE_HORIZ and 
// BOARD_SIZE_VERT, or if you would like to define new types, you may put 
// the corresponding #defines and typedefs here.

#define CELL_SIZE 3

/*=============================================================================
  Global variables
=============================================================================*/

// If you would like to use global variables, declare them here.

int currH0=0,currH1=0,currH2=0,currH3=0,currH4=0,currH5=0,currH6=0;

/*=============================================================================
  Forward function declarations
=============================================================================*/

// If you would like to use functions other than those already declared in
// connect4_functions.h, put the forward declarations of these functions here.

bool check_verticle(int board[][BOARD_SIZE_VERT],int last_move);
bool check_horizontal(int board[][BOARD_SIZE_VERT],int last_move);
bool check_diagonal(int board[][BOARD_SIZE_VERT],int last_move);
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
   char input_char = NULL;

   /* Print Welome message and prompt user for choice of whether they
    * they would like to go first, N/n for going second, anything else
    * results in going 1st */
   printf("*** Welcome to the Connect Four game!!! ***\n");
   printf("Would you like to make the first move [y/n]: ");


   /* while loop to get input character. Stores input in input char var
    * and then if that value is equal to newline char does not enter loop
    * this will clear the input buffer in case user put anything else afer
    * their response. */
   while((input_char = getchar()) != '\n') 
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
   for(int j = BOARD_SIZE_VERT - 1; j >= 0 ; j--)
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
//      printf("  ");
      printf(" %*d ",2,i);
  //    printf(" ");
   } // end collumn numbering loop
   printf("\n"); 
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
   move = rand() % (BOARD_SIZE_HORIZ);
   while(is_column_full(board,move))
   {
      move = rand() % (BOARD_SIZE_HORIZ);
   }
   update_board(board,move,computer_num);
   update_col_height(move);
   return move + 1;
}

/******************************************************************************
*                                                                             *
*                      Function player_move()                                 *
*                                                                             *
******************************************************************************/
int player_move(int board[][BOARD_SIZE_VERT], int player_num)
{
   int move = 0;
   while(1)
   {
      printf("Please enter your move: ");
      scanf("%d",&move);
      while(getchar() != '\n') 
      {
      } // End While(getchar() != '\n') loop
      if(move < 1 || move > BOARD_SIZE_HORIZ)
      {
         printf("Not a valid move. Enter a column number!\n");
      }
      else if(is_column_full(board,move-1))
      {
         printf("This column is full. Try again!\n");
      }
      else
      {
         
         update_board(board,move-1,player_num);
         update_col_height(move-1);
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
      printf("Player %c won!\n",(winner == 1) ? 'X' : 'O');
      return true;
   }
   else
   {  // if there was no winner, check to see if the board is full
      // if any column is not full then return false
      for(int i = 0; i < BOARD_SIZE_HORIZ; i++)
      {
          if(is_column_full(board,i) == false)
	  {
	     return false;
	  }
      }
   }
   //if not win and board is full then print tie game and return true
   printf("Tie game!\n");
   return true;
}
/******************************************************************************
*                                                                             *
*                     Function is_column_full()                               *
*                                                                             *
******************************************************************************/
bool is_column_full(int board[][BOARD_SIZE_VERT], int m)
{
   int col_height = get_col_height(m);
   if(col_height < (BOARD_SIZE_VERT))
   {
      return false;
   }
   return true;
}

/******************************************************************************
*                                                                             *
*                      Function update_board()                                *
*                                                                             *
******************************************************************************/
void update_board(int board[][BOARD_SIZE_VERT], int m, int player_num)
{
   int col_height = get_col_height(m);
   board[m][col_height] = player_num;
}

/******************************************************************************
*                                                                             *
*                      Function check_winner()                                *
*                                                                             *
******************************************************************************/
int check_winner(int board[][BOARD_SIZE_VERT], int last_move)
{
   int winner = 0;
   if((check_horizontal(board,last_move-1)) || 
      (check_verticle(board,last_move-1))   ||
      (check_diagonal(board,last_move-1)))
   {
      // see what the last stone was that was played
      // to determine who the winner.
      int row = get_col_height(last_move-1);
      winner = board[last_move-1][row-1];
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

bool check_verticle(int board[][BOARD_SIZE_VERT],int last_move)
{
   int cur_col = last_move;
   int row = get_col_height(cur_col);
   if(row <4) return false;
   int num = 0;
   int cur_player = board[cur_col][row-1];
   for(int i = row-1; i >= 0 ; i--)
   {
      if(board[cur_col][i] == cur_player)
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
      printf("won by verticle from [%d][%d] :\n",cur_col,row);
      return true;
   }
   return false;
}

/******************************************************************************
*                                                                             *
*                      Function check_horizontal()                                *
*                                                                             *
******************************************************************************/

bool check_horizontal(int board[][BOARD_SIZE_VERT],int last_move)
{
   int cur_col = last_move ;
   int num = 0;
   int row = get_col_height(cur_col);
   int cur_player = board[cur_col][row-1];
   for(int i = cur_col; i >= 0; i--)
   {
      if(board[i][row-1] == cur_player)
      {
         num++;
      }
      else
      {
         break;
      }
   }
   for(int i = cur_col+1; i < BOARD_SIZE_HORIZ; i++)
   {
      if(board[i][row-1] == cur_player)
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
      printf("won by horizontal from [%d][%d] :\n",cur_col,row);
      return true;
   }
   return false;
}

/******************************************************************************
*                                                                             *
*                      Function check_diagonal()                                *
*                                                                             *
******************************************************************************/

bool check_diagonal(int board[][BOARD_SIZE_VERT],int last_move)
{
   int dist_from_left,dist_from_right;
   int cur_col = last_move ;
   int row = get_col_height(cur_col)-1;
   int left_up = 0,left_down = 0,right_up = 0,right_down = 0;
   int cur_player = board[cur_col][row];
   dist_from_left = cur_col;
   dist_from_right = (BOARD_SIZE_HORIZ - 1) - cur_col;
 //  dist_from_top = (BOARD_SIZE_VERT - 1) - row;
 //  dist_from_bot = row;
   for(int i = 1; i < dist_from_left; i++)
   {
      int prev_left_down = left_down;
      int prev_left_up = left_up;
      if(row-i >= 0)
      {
         if(board[cur_col - i][row - i] == cur_player)
	 {
	    left_down++;
         }
      }
      if(row+i < BOARD_SIZE_VERT)
      {
         if(board[cur_col - i][row + i] == cur_player)
	 {
	    left_up++;
	 }
      }  
      if((prev_left_down == left_down) &&
         (prev_left_up == left_up))
      {
         break;
      }
   }
   for(int i = 1; i < dist_from_right; i++)
   {
      int prev_right_down = right_down;
      int prev_right_up = right_up;
      if(row-i >= 0)
      {
         if(board[cur_col + i][row - i] == cur_player)
	 {
	    right_down++;
         }
      }
      if(row+i < BOARD_SIZE_VERT)
      {
         if(board[cur_col + i][row + i] == cur_player)
	 {
	    right_up++;
	 }
      }
      if((prev_right_down == right_down) &&
         (prev_right_up == right_up))
      {
         break;
      }
   }
   if(((left_up + right_down) >= 3) ||
      ((left_down + right_up) >= 3))
   {
      printf("won by diag from [%d][%d] :\n",cur_col,row);
      return true;
   }
   return false;
}

/******************************************************************************
*                                                                             *
*                      Function check_diagonal()                                *
*                                                                             *
******************************************************************************/

void update_col_height(int last_move)
{
    
    switch(last_move)
    {
       case 0:
          currH0++;
          break;
       case 1:
          currH1++;
          break;
       case 2:
          currH2++;
          break;
       case 3:
          currH3++;
          break;
       case 4:
          currH4++;
          break;
       case 5:
          currH5++;
          break;
       case 6:
          currH6++;
          break;
       default:
          break;
    }
}

int get_col_height(int col)
{
    int newH = 0;
    switch(col)
    {
       case 0:
          newH = currH0;
          break;
       case 1:
          newH = currH1;
          break;
       case 2:
          newH = currH2;
          break;
       case 3:
          newH = currH3;
          break;
       case 4:
          newH = currH4;
          break;
       case 5:
          newH = currH5;
          break;
       case 6:
          newH = currH6;
	  break;
       default:
          break;
   }
return newH;
}
/******************************************************************************
                                End of file
******************************************************************************/


