#include <stdio.h>


int main() {
    int a = 0;

    while (a != -1)
    {
        printf("Enter the given mark: ");
        scanf("%d", &a);
        
        if (a >= 0 && a <= 100)
        {
            printf("%d is a valid number between 0 and 100\n", a);
        }
        else if (a == -1)
        {
            printf("You have entered the Loop Termination number\n");
        }
        else
        {
            printf("%d is not a valid number between 0 and 100\n", a);
        }
    }
    printf ("You have successfully left the loop\n");

    return (0);
        
}