#include <stdio.h>
/*
 * Extra Credit: No there are not values for a,b, and c that would make all
 * of the answers false. To determine this i tested values for each variable
 * individually to see what the constraints on each was for a false result.
 * For a the value has to be 1 in order to make all of the results false. For
 * c it has to be -2 in order to make sure the 3rd result is false and b has to
 * either be 0 for the 4th to be false and -1 for the first to be false, but 
 * since it cannot be both then there is no solution. You could also use 
 * boolean algebra to solve for a,b,c often used in circuit design to reduce
 * the number of gates used.
 */
int main()
{
   int a,b,c;
   int result;

   printf("Enter integers a,b,c: ");
   if(scanf("%i%i%i",&a,&b,&c) != 3)
   {
      printf("Usage: Please Enter 3 integers a, b, and c!");
      return -1;
   }
   result = !a || (!b++ && c);
   printf("       !a || !b++ && c: %s\n", result ? "True" : "False");
   result = (a-1 || b/2) && (c*=2);
   printf("(a-1 || b/2) && (c*=2): %s\n", result ? "True" : "False");
   result = (a-- || --b) && (c+=2);
   printf("(a-- || --b) && (c+=2): %s\n", result ? "True" : "False");
   result = a || !(b && --c);
   printf("      a || !(b && --c): %s\n", result ? "True" : "False");
   return 0;


}
