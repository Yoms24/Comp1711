
#include <stdio.h>
int main()
{
    char str[] = "Hello";
    int length = 0;
    
    while ( str[length] != '\0')
    {
     length++;
    }

    int count = 0;
    for (count = length; count >= 0; count--)
    {
        if (str[count] == '\0')
        {
            printf("\\0");
        
        } else
        {
            printf("%c", str[count]);
        }
    }
    
    printf("\n");
    return 0;
}