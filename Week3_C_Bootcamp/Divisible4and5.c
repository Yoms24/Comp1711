#include <stdio.h>


int main() {
    int a;
    printf("Enter the given mark: ");
    scanf("%d", &a);

    if (a % 4 == 0 && a % 5 == 0)
    {
        printf("The number %d is both divisible by 4 and 5\n", a);
    }
    else if (a % 4 == 0)
    {
        printf("The number %d is divisible by 4 and not 5\n", a);
    }
    else if (a % 5 == 0)
    {
        printf("The number %d is divisible by 5 and not 4\n", a);
    }
    else
    {
        printf("The number %d isn't both divisible by 4 and 5\n", a);
    }

    return (0);
        
}