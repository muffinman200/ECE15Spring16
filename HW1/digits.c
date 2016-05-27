#include <stdio.h>

int main()
{
   int inputInt,digit,digitPos;
   printf("Enter an integer: ");
   if(scanf("%i",&inputInt) < 1)
   {
      printf("Usage: Please input an integer!");
      return -1;
   }
   if(inputInt < 0)
   {
      inputInt = inputInt * -1;
   }
   digitPos = 1;
   do{
      digit = inputInt % 10;
      printf("Digit (%i): %i\n", digitPos, digit);
      inputInt = inputInt / 10;
      digitPos++;
   }while(inputInt != 0);
   return 0;
}
