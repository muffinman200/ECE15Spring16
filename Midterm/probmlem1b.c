#include <stdio.h>
//#include <string.h>
#define PHRASELENGTH 20

int main()
{
   int i = 0;
   char phrase[PHRASELENGTH], nextchar;

   printf("Enter a phrase of up to %d letters:",PHRASELENGTH);
   while(1)
   {
      scanf("%c",&nextchar);
      if(nextchar  != '\n') phrase[i++] = nextchar;
      else break;
   }

   for(int j = 0; j <= i; ++j)
   {
      switch(phrase[j])
      {
         case 'a':
         case 'e':
         case 'i':
         case 'o':
         case 'u': printf("*");
                  break;
         default: printf("%c",phrase[j]);
      }
   }
   printf("\n");
   return 0;
}
