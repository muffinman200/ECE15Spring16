#include <stdio.h>

#define KEY_LENGTH 5 

int main()
{
   int WORD_LENGTH = 7;
   char cryptoArr[5], startWord[WORD_LENGTH], encryptedWord[WORD_LENGTH];
   int scanned;
   int i = 0;
   printf("Enter key: ");
   scanned = scanf("%c%c%c%c%c",&cryptoArr[0],&cryptoArr[1],&cryptoArr[2],&cryptoArr[3],&cryptoArr[4]);
   if(scanned != 5) { 
      printf("Usage: key must be 5 chars; 1 each of a b c d and r!");
      return 1;
   }
   printf("Enter word: ");
   while(i < WORD_LENGTH) {
     scanf(" %c",&startWord[i]);
     i++;
   }
   i = 0;
   while(i < WORD_LENGTH) {
      switch(startWord[i]) {
         case 'a':
            i++;
            break;
         case 'b':
            i++;
            break;
         case 'c':
            i++;
            break;
         case 'd':
            i++;
            break;
         case 'r':
            i++;
            break;
         default :
            printf("You did not speak in ABRACADABRA to me!\n");
            return 1;
      }
   }
   i = 0;
   while(i < WORD_LENGTH ){
      if(startWord[i] == 'a'){
         encryptedWord[i] = cryptoArr[0];
      }
      else if(startWord[i] == 'b'){
         encryptedWord[i] = cryptoArr[1];
      }
      else if(startWord[i] == 'c'){
         encryptedWord[i] = cryptoArr[2];
      }
      else if(startWord[i] == 'd'){
         encryptedWord[i] = cryptoArr[3];
      }
      else if(startWord[i] == 'r'){
         encryptedWord[i] = cryptoArr[4];
      }
      i++;
   }

   i = 0;
   printf("Encrypted word: ");
   while(i < WORD_LENGTH) {
     printf("%c",encryptedWord[i]);
     i++;
   }
   printf("\n");
   return 0;
}
