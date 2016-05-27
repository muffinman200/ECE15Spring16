#include <stdio.h>
int main(){
int i;
float x = 18.0;
double d1,d2,d3;
i = x/10;
d1 = (double) (i/2);
d2 = (double) i/2;
d3 = d2*1/2;
printf("--> i = %d ",i);
printf("d1 = %.2f d2 = %.2f d3 = %.2f\n",d1,d2,d3);
 return 0;
}
