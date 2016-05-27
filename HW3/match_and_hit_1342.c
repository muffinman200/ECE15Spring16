#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUERIES 12
#define N_DIGITS 4
#define INVALID_Q "Invalid query. Please try again!\n"
#define INVALID_NUM "Invalid number. Please try again!\n"

int isvalid(int n);
int choose_N();
int matches(int N, int M);
int hits(int N, int M);

int main(){
   int computerN,playerM,valid = 0,numHits = 0,numMatches = 0;
   computerN = choose_N();
   printf(" ***Welcome to the MATCH and HIT game***\n\n");
   printf("The computer has selected a %d-digit number.\n",N_DIGITS);
   printf("Try to deduce it in %d rounds of queries.\n\n",MAX_QUERIES);

   for(int i = 1; i <= MAX_QUERIES; i++) {
      printf("Round #%d\n",i);
      while(valid != 1){
         printf("Please enter your query (%d digits): ",N_DIGITS);
         valid = scanf(" %d",&playerM);
  
         if(valid == 0){
            printf(INVALID_Q);
            playerM = 0;
            
         }
         else if((isvalid(playerM) == 0)){
            printf(INVALID_NUM);
            playerM = 0;
            valid = 0;
            
         }
         else if (isvalid(playerM)){
            numMatches = matches(playerM,computerN);
            numHits = hits(playerM,computerN);
            numHits =  numHits - numMatches;
            printf("-> %d %s and %d %s\n\n",numMatches,
                  (numMatches == 1) ? "match" : "matches",
                  numHits,(numHits == 1) ? "hit" : "hits");
            playerM = 0;
            valid = 1;
         }
         if(getchar() != '\n'){
            scanf(" %*s");
         }
      }
      if(numMatches == N_DIGITS){
         printf("**********************************\n");
         printf("CONGRATULATIONS! You won the game!\n");
         printf("**********************************\n");
         break;
      }
      else if(i == MAX_QUERIES){
         printf("*********************************\n");
         printf("Sorry, out of queries. Game Over!\n");
         printf("*********************************\n");
         break;
      }
      else{
         valid = 0;
      }
   }
   
return 0;
}

int isvalid(int n){
    int currDigit, j = 10,k = 10;
    int digitsUsed[10] = {};
    for(int i = 1; i < N_DIGITS - 1; i++){
        k = k * k;
    }
    if(n <= 0 || (n > (k-1)) ){
        return 0;
    }
    else{
       for(int i = 0; i < N_DIGITS; i++){
          currDigit = n % j;
          n = n / j;
          if(currDigit == 0){
             return 0;
          }
          else if(digitsUsed[currDigit] != 0){
             return 0;
          }
          else{
             digitsUsed[currDigit] = currDigit;
          }
        }
   
      if(n != 0){
         return 0;
      }
   }
   return 1;
}

int choose_N(){
    int n,max = 1;
    for(int i = 0; i < N_DIGITS; i++){
        max = max * 10;
    }
    srand(time(0));
    n = rand() % max;
    while(isvalid(n) == 0){
        n = rand() % max;
    }
return 1342;
}

int matches(int N, int M){
   int numMatches = 0,n_digit,m_digit;
   for(int i = 0; i < N_DIGITS; i++){
      n_digit = N % 10;
      m_digit = M % 10;
      N = N / 10;
      M = M / 10;
      if(m_digit == n_digit){
         numMatches++;
      }
   }
   return numMatches;
}

int hits(int N, int M){
   int numHits = 0,n_digit,m_digit; 
   int digitsUsed[9] = {};
   for(int i = 0; i < N_DIGITS; i++){
      n_digit = N % 10;
      N = N / 10;
      digitsUsed[n_digit] = 1;
   }
   for(int i = 0; i < N_DIGITS; i++){
      m_digit = M % 10;
      M = M / 10;
      if(digitsUsed[m_digit] == 1){
         numHits++;
      }
   }
   return numHits;
}
