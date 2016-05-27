#include <stdio.h>
#include <stdlib.h>

#define MAX_IN_LENGTH 241
#define OUT_LENGTH 60
#define INPUT_FILE "dna_input.dat"
#define OUTPUT_FILE "dna_output.dat"


int read_DNA(char sequence[]);
double compare_DNA(char seq1[], char seq2[], char seq3[], int n);
void print_DNA(char seq1[], char seq2[], char seq3[], int n);

FILE* input, *output;

int main(){
   char seq1[MAX_IN_LENGTH],seq2[MAX_IN_LENGTH],seq3[MAX_IN_LENGTH],seq4[MAX_IN_LENGTH],
        seq5[MAX_IN_LENGTH],seq6[MAX_IN_LENGTH];
   for(int i = 0; i < MAX_IN_LENGTH; i++){
      seq1[i] = 0;
      seq2[i] = 0;
      seq3[i] = 0;
      seq4[i] = 0;
      seq5[i] = 0;
      seq6[i] = 0;
   }
   input = fopen(INPUT_FILE, "r");
   int numRead = read_DNA(seq1);
   read_DNA(seq2);
   read_DNA(seq3);

   fclose(input);
   output =fopen(OUTPUT_FILE, "w");
   fprintf(output,"Comparison between sequence #1 and sequence #2:\n");
   double ratio = compare_DNA(seq1,seq2,seq4,numRead);
   print_DNA(seq1,seq4,seq2,numRead);
   fprintf(output, "The overlap percentage is %.1lf%%\n\n",ratio);

   fprintf(output,"Comparison between sequence #1 and sequence #3:\n");
   ratio = compare_DNA(seq1,seq3,seq5,numRead);
   print_DNA(seq1,seq5,seq3,numRead);
   fprintf(output, "The overlap percentage is %.1lf%%\n\n",ratio);

   fprintf(output,"Comparison between sequence #2 and sequence #3:\n");
   ratio = compare_DNA(seq2,seq3,seq6,numRead);
   print_DNA(seq2,seq6,seq3,numRead);
   fprintf(output, "The overlap percentage is %.1lf%%\n\n",ratio);

   fclose(output);
   
return 0;
}

int read_DNA(char sequence[]){
   int read=0;
   for(int i = 0; i < MAX_IN_LENGTH;i++){
      fscanf(input,"%c",&sequence[i]);
      if(sequence[i] == '\n'){
        break;
      }
      read++;
   }
   
   return read;   
}

double compare_DNA(char seq1[], char seq2[],char seq3[],int n){
   double numMatching = 0;
   for(int i = 0; i < n ; i++){
       if(seq1[i] == seq2[i]){
          seq3[i] = seq1[i];
          numMatching++;
       }
       else{
          seq3[i] = ' ';
       }
   }
   double simRatio = (numMatching/(double)(n)) * 100;
   return simRatio;
}

void print_DNA(char seq1[], char seq2[], char seq3[],int n){
int lenRemaining = n,k=0;
   while(lenRemaining > OUT_LENGTH){
      for(int i = 0; i < OUT_LENGTH; i++){
         fprintf(output,"%-1.1s",&seq1[i+k]);
      }
      fprintf(output,"\n");

      for(int i = 0; i < OUT_LENGTH; i++){
         fprintf(output,"%-1.1s",&seq2[i+k]);
      }
      fprintf(output,"\n");
      for(int i = 0; i < OUT_LENGTH; i++){
         fprintf(output,"%-1.1s",&seq3[i+k]);
      }
      fprintf(output,"\n");
      lenRemaining -= OUT_LENGTH;
      k += OUT_LENGTH;
   }
   fprintf(output,"\n");
   fprintf(output,"%s",&seq1[k]);
   fprintf(output,"%s\n",&seq2[k]);
   fprintf(output,"%s\n",&seq3[k]);

} 


