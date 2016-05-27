#include <stdio.h>

#define EXIT 3
#define DISPLAY 2
#define ENTER 1

int main()
{
   int number, sum, choice, total_numbers;

   printf("Welcome to the integer sum program!\n");

   choice = 0;
   total_numbers = 0;
   sum = 0;
   while(choice != EXIT)
   {
      printf("So far, you have entered %i numbers. You may:\n",total_numbers);
      printf("1. Enter a new integer\n");
      printf("2. Display the current sum\n");
      printf("3. Exit\n");
      printf("Please enter your choice: ");
      scanf("%i",&choice);

      if(choice == ENTER)
      {
         printf("Enter the new integer: ");
         scanf("%i",&number);
         total_numbers++;
         sum += number;
      }
      else if(choice == DISPLAY)
      {
         printf("The current sum is: %i\n",sum);
      }
   }
   return 0;
}
