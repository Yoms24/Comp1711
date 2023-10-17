#include <stdio.h>
#define Between(value, min, max) (value < max && value >= min)

int main() {
    
 int a;
    printf("Enter the given mark: ");
    scanf("%d", &a);
        
   if (Between(a, 0, 50))
   {
    printf("The student has received a failing grade\n");
   }
   else if (Between(a, 50, 70))
   {
    printf("The student receieved a passing grade\n");
   }
   else if (Between(a, 70, 101))
   {
    printf("The student received a distinction grade\n");
   }
   else
   {
    printf("The student grade could not be processed\n");
   }
    

    return (0);

}