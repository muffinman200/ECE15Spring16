#include <stdio.h>

#define VARIABLE_NAME 'Y'

int main()
{
   float a,b,c,result;
   char y;
   int inputScan;

   printf("Enter a linear equation: "); // prompt user for input equation
   inputScan = scanf("%f%c +%f =%f", &a,&y,&b,&c); // scan user input

   if(y != VARIABLE_NAME) {        // check and make sure variable is correct
      printf("  Invalid input!\n");
      return 1;
   }
   else if(inputScan != 4) {      // make sure the input equation is of the
      printf("  Invalid input!\n"); // correct form aY + b = c
      return 1;
   }
   else if (a == 0) {             // make sure a is not zero
      printf("  Invalid equation!\n");
      return 1;
   }
   else {
      result = (c - b)/a;         // calculate value of Y in aY + b = c
   }
   printf("Y = %.3f\n", result);  // print result Y with 3 places of percission
   return 0;

}
