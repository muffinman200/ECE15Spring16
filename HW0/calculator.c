#include <stdio.h>

int main()
{
   int x,y;
   int plus,mul,div,mod;

   printf("Enter x: ");
   scanf("%i", &x);
   printf("Enter y: ");
   scanf("%i", &y);
   plus = x + y;
   mul = x * y;
   div = x / y;
   mod = x % y;
   printf("\nHere are the results:\n");
   printf("x+y = %i\n",plus);
   printf("x*y = %i\n",mul);
   printf("x/y = %i\n",div);
   printf("x%%y = %i\n",mod);
   return 0;
}
   
