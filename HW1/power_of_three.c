#include <stdio.h>

#define BASE 3

int main()
{
   int num, exponent,temp;
  
   printf("Enter a positive integer: ");
   scanf("%d", &num);

   temp = 1;
   exponent = 0;

   if (num <= 0)
   {
      printf("Error: invalid integer entered!\n");
      return 1;
   }

   while(temp < num)
   {
      temp = temp * BASE;
      exponent++;
   }

   if(temp == num)
   {
      printf("%i is a power of %i, exponent = %i\n",temp,BASE,exponent);
   }
   else
   {
      printf("%i is not a power of %i!\n",num,BASE);
   }

   return 0;
}
