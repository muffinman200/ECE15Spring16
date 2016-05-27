#include <stdio.h>
#define M 7
#define N 5

int main()
{
   int i,j,k;
   for(i = 0; i < N; i++)
   {
      j = M;
      k = i * j;

      if( (i )%2) continue;
      printf("i = %d, j = %d, k = %d\n", i,j,k);
   }
return 0;
}
