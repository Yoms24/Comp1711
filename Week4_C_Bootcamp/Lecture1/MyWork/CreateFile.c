#include <stdio.h>
#include "utils.h"



int main() {
    
   char filename[] = "./data.txt";
   FILE *file = open_file(filename, "r");

    int buffer_size = 2;
    char buffer [buffer_size];
    int count = 0;

    while (fgets(buffer, buffer_size, file))
    {
        printf("%s", buffer);
        count++;
    }
    
    printf("The loop was executed %d times.\n", count);

    fclose(file);

    return (0);

}