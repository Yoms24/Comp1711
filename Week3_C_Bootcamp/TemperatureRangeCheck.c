#include <stdio.h>

int main() {
    
 int temp;
    printf("Enter the given temperature: ");
    scanf("%d", &temp);

   if (temp >= -10 && temp <= 40)
   {
    printf("The temperature %d is valid\n", temp);
   }
   else
   printf("The temperature %d isn't valid\n", temp);
    

    return (0);

}