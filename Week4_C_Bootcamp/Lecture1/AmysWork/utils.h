// Include guards - prevents multiple includes which cause errors!
#ifndef UTILS_H
#define UTILS_H

// These will be included in any file which includes this header file!
#include <stdio.h>
#include <stdlib.h>

FILE *open_file(char *filename, char *mode);

// this is a doxygen comment - you'll see more of these in COMP1921 :)
/**
 * @brief Opens the specified file
 *
 * @param filename the path to the file to be opened.
 * @param mode the mode ( r/w/a | + )
 * @return the opened file pointer
 */
FILE *open_file(char *filename, char *mode)
{
    FILE *file = fopen(filename, mode);

    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    return file;
}

// this is closing the include guards.
#endif