#include <stdio.h>
#include <math.h>
#define n 3
int main(){
double x[n], y[n], numerator = 0, denom = 0, projection = 0;
int i =0;
printf("Enter a %d-dimensional vector for x:",n);
while(i<n) scanf("%lf",x+i++); 
i=0;
printf("Enter a %d-dimensional vector for y:",n);
while(i<n)scanf("%lf",y+i++);
for(int i = 0; i < n; i++){
numerator = numerator + (x[i] * y[i]);
denom = denom + (y[i] * y[i]);
}
if(denom == 0){
printf("Projection on all-zero vector is undefined\n");
return 1;
}
denom = sqrt(denom);
if(numerator < 0) numerator * -1;
projection = numerator / denom;
printf("The length of the projection of x on y is %.6f\n",projection);
return 0;
}
