#include <stdio.h>

int main() {
    
 int a;
    printf("Enter the given number: ");
    scanf("%d", &a);

   if (a > 0)
   {
    printf("The number %d is positive\n", a);
   }
   else if ( a < 0)
   {
    printf("The number %d is negative\n", a);
   }
   else if (a == 0)
   {
    printf("The number %d is 0\n", a);
   }
   else 
   {
    printf ("The number %d is unrecognizable\n", a);
   }
    

    return (0);

}