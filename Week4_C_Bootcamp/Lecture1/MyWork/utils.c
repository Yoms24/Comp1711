#include "utils.h"
#include <stdio.h>

FILE *open_file(char filename[], char mode[]) {
 
    FILE *file = fopen(filename, mode);

    if (file == NULL){
        perror("File I/O");
        exit(1);
    }

    return file; 
}