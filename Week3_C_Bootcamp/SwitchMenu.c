#include <stdio.h>
int main() {
    
    int label;
    printf("Enter the value: ");
    scanf("%d", &label);

    switch(label)
    {
        case 0:
            printf("0 was selected.\n");
            break;
        case 1:
            printf("1 was selected.\n");
            break;
        case 2:
            printf("2 was selected.\n");
            break;
        case 3:
            printf("3 was selected.\n");
            break;
        case 4:
            printf("4 was selected.\n");
            break;
        default:
            printf("Invalid selection.\n");
            break;
    }

    return (0);

}