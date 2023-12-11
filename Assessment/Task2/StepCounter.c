#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array
const char delimiter = ',';

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char* input, const char* delimiter,
    char* date, char* time, char* steps) {
    // Create a copy of the input string as strtok modifies the string
    char* inputCopy = strdup(input);

    // Tokenize the copied string
    char* token = strtok(inputCopy, delimiter);
    if (token != NULL) {
        strcpy(date, token);
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

FITNESS_DATA* importFitnessData(const char* filename, int* dataCount) {
    FILE *file;
    FITNESS_DATA * steps_array = NULL;
    int size = 0;
    int capacity = 10;
    char row[50];

    file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error: could not open file");
        exit(1);
    }

    steps_array = (FITNESS_DATA *) malloc(capacity * sizeof(FITNESS_DATA));

    // Check memory allocation was successful.
    if (steps_array == NULL)
    {
        perror("Error allocating memory for additional rows");
        fclose(file);
        return NULL;
    }

    while (fgets(row, sizeof(row), file) != NULL) {
        if (size == capacity) {
            capacity *= 2;
            FITNESS_DATA *temp_array = (FITNESS_DATA *) malloc(capacity * sizeof(FITNESS_DATA));
            // Check memory allocation was successful.
            if (temp_array == NULL)
            {
                perror("Error allocating memory for additional rows.");
                fclose(file);
                return NULL;
            }

            for (int i = 0; i < capacity; i++) {
                temp_array[i] = steps_array[i];
            }

            free(steps_array);
            steps_array = temp_array;
            temp_array = NULL;
        }

        char date[11], time[6], steps[10];

        tokeniseRecord(row, &delimiter, date, time, steps);

        strcpy(steps_array[size].date, date);
        strcpy(steps_array[size].time, time);
        steps_array[size].steps = atoi(steps);

        size++;
    }
    fclose(file);

    *dataCount = size;
    return steps_array;
}

int main() {
    char input;
    char filename[256];
    FITNESS_DATA* data = NULL;
    int dataCount = 0;

    while (1) {
        printf("A: Specify the filename to be imported\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Exit the program\n");
        scanf(" %c", &input);

        switch (input) {
            case 'A':
            case 'a':
                printf("Input Filename: \n");
                scanf("%s", filename);
                data = (FITNESS_DATA*)malloc(sizeof(FITNESS_DATA*) * dataCount);
                data = importFitnessData(filename, &dataCount);
                if (data == NULL)
                {
                    return 1;
                }
                else {
                    printf("File loaded successfully\n");
                }
                break;
            case 'B':
            case 'b':
                printf("Total number of records: %d\n", dataCount);
                break;
            case 'C':
            case 'c':
                printFewestStepsData(data, dataCount);
                break;
            case 'D':
            case 'd':
                printLargestStepsData(data, dataCount);
                break;
            case 'E':
            case 'e':
                printMeanStepCountData(data, dataCount);
                break;
            case 'F':
            case 'f':
                printLongestPeriodData(data, dataCount);
                break;
            case 'Q':
            case 'q':
                return 0;
            default:
                printf("Invalid command. Try again.\n");
                break;
        }
    }
}