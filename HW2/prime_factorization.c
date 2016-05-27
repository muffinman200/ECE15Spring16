#include <stdio.h>

int main() {

   int inputInt, tempStarter;
   int index = 0;
   int i = 2;
   printf("Enter an integer: ");
   if(scanf("%i",&inputInt) != 1) {
      printf("Usage: input should be of type integer!\n");
      return 1;
   }
   while(inputInt > 1) {
      tempStarter = inputInt;
      int primeArray[inputInt + 1];
      while(inputInt >= i) {
         if(inputInt % i == 0) {
            primeArray[index] = i;
            inputInt = inputInt / i;
            index++;
         }
         else {
         i++;
         }
      }
      int j = 0;
      printf("The prime factorization of %i is ",tempStarter);
      while(j < index) {
         printf("%i ",primeArray[j]);
         j++;
      }
      printf("\n");
      i = 2;
      index = 0;
      printf("Enter an integer: ");
      if(scanf("%i",&inputInt) != 1) {
         printf("Usage: input should be of type integer!\n");
         return 1;
      }
      if(inputInt <= 1) {
         break;
      }
           
   }
   return 0;
}
