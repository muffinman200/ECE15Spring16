#include <stdio.h>
#define KEY_LENGTH 5

int main(){

   int WORD_LENGTH;
   printf("Enter the desired word length: ");
   scanf("%i",&WORD_LENGTH);
   printf("#include <stdio.h>\n\n");
   printf("#define KEY_LENGTH 5 \n");
   printf("\n");
   printf("int main()\n");
   printf("{\n");

   // prompt user for 5 character key
   printf("   int WORD_LENGTH = %i;\n",WORD_LENGTH);
   printf("   char cryptoArr[5], startWord[WORD_LENGTH], encryptedWord[WORD_LENGTH];\n");
   printf("   int scanned;\n");
   printf("   int i = 0;\n");
   printf("   printf(\"Enter key: \");\n");
   printf("   scanned = scanf(\"%%c%%c%%c%%c%%c\",&cryptoArr[0],&cryptoArr[1],&cryptoArr[2],&cryptoArr[3],&cryptoArr[4]);\n");
   printf("   if(scanned != 5) { \n");
   printf("      printf(\"Usage: key must be 5 chars; 1 each of a b c d and r!\");\n");
   printf("      return 1;\n");
   printf("   }\n");

   // prompt user for 7 character abracadabra word to encrypt
   printf("   printf(\"Enter word: \");\n");
   printf("   while(i < WORD_LENGTH) {\n");
   printf("     scanf(\" %%c\",&startWord[i]);\n");
   printf("     i++;\n");
   printf("   }\n");

   printf("   i = 0;\n");

   // make sure the input word is in the abracadabra language
   printf("   while(i < WORD_LENGTH) {\n");
   printf("      switch(startWord[i]) {\n");
   printf("         case 'a':\n");
   printf("            i++;\n");
   printf("            break;\n");
   printf("         case 'b':\n");
   printf("            i++;\n");
   printf("            break;\n");
   printf("         case 'c':\n");
   printf("            i++;\n");
   printf("            break;\n");
   printf("         case 'd':\n");
   printf("            i++;\n");
   printf("            break;\n");
   printf("         case 'r':\n");
   printf("            i++;\n");
   printf("            break;\n");
   printf("         default :\n");
   printf("            printf(\"You did not speak in ABRACADABRA to me!\\n\");\n");
   printf("            return 1;\n");
   printf("      }\n");      
   printf("   }\n");
   printf("   i = 0;\n");

   // create encrypted char array using the given key and word
   printf("   while(i < WORD_LENGTH ){\n");
   printf("      if(startWord[i] == 'a'){\n");
   printf("         encryptedWord[i] = cryptoArr[0];\n");
   printf("      }\n");
   printf("      else if(startWord[i] == 'b'){\n");
   printf("         encryptedWord[i] = cryptoArr[1];\n");
   printf("      }\n");
   printf("      else if(startWord[i] == 'c'){\n");
   printf("         encryptedWord[i] = cryptoArr[2];\n");
   printf("      }\n");
   printf("      else if(startWord[i] == 'd'){\n");
   printf("         encryptedWord[i] = cryptoArr[3];\n");
   printf("      }\n");
   printf("      else if(startWord[i] == 'r'){\n");
   printf("         encryptedWord[i] = cryptoArr[4];\n");
   printf("      }\n");
   printf("      i++;\n");
   printf("   }\n");
   printf("\n");

   // print encrypted word   
   printf("   i = 0;\n");
   printf("   printf(\"Encrypted word: \");\n");
   printf("   while(i < WORD_LENGTH) {\n");
   printf("     printf(\"%%c\",encryptedWord[i]);\n");
   printf("     i++;\n");
   printf("   }\n");
   printf("   printf(\"\\n\");\n");
   printf("   return 0;\n");
   printf("}");
   return 0;
}
