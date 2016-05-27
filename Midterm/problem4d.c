#include <stdio.h>
int main()
{
  int i, x =0,y=0,a=8,b=3,c=8,d=3;
for(i = 3; i> 0;i--){
if(!(--a%b++))x+=i;
if(!(c--%++d))y+=i;
}
printf("--> i = %d a = %d b = %d",i,a,b);

printf("c = %d d = %d x = %d y = %d",c,d,x,y);
return 0;
}
