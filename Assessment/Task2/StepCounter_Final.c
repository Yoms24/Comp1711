#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }

int getTotalSteps(FITNESS_DATA data[], int dataCount) {
    int totalSteps = 0;
    for (int i = 0; i < dataCount; i++) {
        totalSteps += data[i].steps;
    }
    return totalSteps;
}

double getAverageSteps(FITNESS_DATA data[], int dataCount) {
    int totalSteps = getTotalSteps(data, dataCount);
    return (double)totalSteps / dataCount;
}

// Complete the main function
// Inspired by Week 7 Classwork
int main() {

    char filename[256];
    FITNESS_DATA *data = NULL;
    int dataCount = 0;
    char choice;

    while (1)
    {

        printf("A: Specify the filename to be imported\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n"); 
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Exit the program\n");

        // Store the character given as an input
        choice = getchar();

        while (getchar() != '\n');
        // switch statement to control the menu.
        switch (choice)
        {
        // this allows for either capital or lower case
        case 'A':
        case 'a':
        printf("Input Filename: \n");
        scanf("%s", filename);
        data = importFitnessData(filename, &dataCount);

       FILE *input = fopen(filename, "r");
        if (!input)
        {
            printf("Error: File could not be opened\n");
            return 1;
        }
        else    {
            printf("File loaded successfully\n");
        }
    
        break;

        case 'B':
        case 'b':

        printf("Total number of records: %d\n", dataCount);
        break;

        case 'C':
        case 'c':
           return 0;
           break;

        case 'D':
        case 'd':
           return 0;
           break;

        case 'E':
        case 'e':
            printf("Average step count: %.2f\n", getAverageSteps(data, dataCount));

            return 0;
            break;

        case 'F':
        case 'f':
            return 0;
            break;

        case 'Q':
        case 'q':
            return 0;
            break;

        //If they dont choose a eligibile option
        default:
            printf("Not an Option\n");
            
            break;
        }
    }
}