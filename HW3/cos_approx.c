#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define INPUT_FILE "cos_input.dat"
#define OUTPUT_FILE "cos_output.dat"

int factorial(int n);

double power(double x,int n);

double cos_N(double x,int N);

double cos_delta(double x,double delta);


int main(){
   FILE *infp;
   FILE *outfp;
   if((infp = fopen(INPUT_FILE,"r")) == NULL) {
      printf("Couldn't open %s\n",INPUT_FILE);
      return 1;
    }
   if((outfp = fopen(OUTPUT_FILE, "w")) == NULL) {
      printf("Couldn't open %s\n",OUTPUT_FILE);
      return 1;
   } 
   int num_lines,method,N;
   double x,delta,cos;
   fscanf(infp, "%d\n", &num_lines);
   for(int i = 0; i < num_lines; i++){
      fscanf(infp, "%d",&method);
      if(method == 1){
         fscanf(infp, " %lf %d\n",&x,&N);
         cos = cos_N(x,N);
         fprintf(outfp,"Case %d: cos(%.3lf) = %.12lf\n",i+1,x,cos);
      }
      else if(method == 2){
         fscanf(infp, " %lf %lf\n",&x,&delta);
         cos = cos_delta(x,delta);
         fprintf(outfp,"Case %d: cos(%.3lf) = %.12lf\n",i+1,x,cos);
      }
   }
   fclose(infp);
   fclose(outfp);
      
   
return 0;
}

/******************************************************************************
 * Function: factorial
 * parameters: int x - value for which to compute its factorial
 * return value: int - computed factorial of paramter x.
 * Description: multiples n * (n-1) * .... * 2 * 1 in a for loop to calculate
 *              the factorial of paramter x. If x is not positive returns 1.
 *****************************************************************************/
int factorial(int n){
   int factorial = 1;
   for(int i = 1; i <= n; i++){
      factorial = factorial * i;
   }
   return factorial;
}

/******************************************************************************
 * Function: power
 * parameters: double x - value for which to compute x^n 
 *             int n - integer representing the power to which raise x to.
 * return value: double - returns x^n or 1 if n >= 0
 * Description: multiplies x by itself n times in for loop to get result of 
 *              x^n
 *****************************************************************************/
double power(double x,int n){
   double power = 1.0;
   if(n<0) return power;
   for(int i = 0; i < n; i++){
         power *= x;
   }
   
   return power;
}

/******************************************************************************
 * Function: cos_N
 * parameters: double x - value for which to compute cos(x) of in radians
 *             int N - the number of terms to sum from the taylor series for
 *                     approximating cos(x).
 * return value: double - returns the value of cos(x) up to N terms
 * Description: determines an approximation of the cos(x) with N terms
 *****************************************************************************/
double cos_N(double x,int N){
   if(N < 0)
   {
      return 0.0;
   }
   double cos = 0.0;
   double num,denom;
   for(int i = 0; i < N; i++){
      num = power(-1.0,i) * power(x,2*i); // simple stright from the formula
      denom = factorial(2*i);             // implementation for suming the
      cos = cos + num/denom;              // series from 0 to n
   }
return cos;
}

/******************************************************************************
 * Function: cos_delta
 * parameters: double x - value for which to compute cos(x) of in radians
 *             double delta - precision value to which to calulcaulate cos(x)
 *                            within. Cos(x) is computed with the smallest 
 *                            number of terms for which the absolute value of
 *                            the difference between the taylor series for n-1
 *                            and n-2 is strictly less than delta. 
 * return value: double - returns the value of cos(x) with precision delta
 * Description: determines an approximation of the cos(x) with precision delta
 *              as decribed by the description for the parameter delta.
 *****************************************************************************/
double cos_delta(double x,double delta){
   double temp=1.0,result = 1.0; // setting result = 1 lets us skip n = 0 in
                                 // the summation.
   for(int i = 2; (temp >= delta || -temp >= delta); i=i+2){
      temp *= (power(-1.0,1)*power(x,2))/(i*(i-1));
      result += temp;
   }                  
                         // tried to use my functs  but couldnt get the proper
                         // precision for so i switch to calulating the terms 
                         // individualy and stopped when the nth term was larger
                         // than delta because i realized that the inequality 
                         // given the sum of n-1 minues sum of n-2 was equal to
                         // term in in the sum of n.
   
return result;
}
