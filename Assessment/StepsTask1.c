#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here
const char delimiter = ',';

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
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

// Complete the main function
int main() {
    FILE *file;
    char fileName[] = "FitnessData_2023.csv";

    file = fopen(fileName, "r");

    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    // Create initial array size and allocate.
    FITNESS_DATA *data_arr = NULL;
    int size = 0; // Size of the array
    int capacity = 10; // Capacity of the array 

    data_arr = (FITNESS_DATA *)malloc(capacity * sizeof(FITNESS_DATA)); //Initial capacity at 10, capacity * size of FITNESS_DATA to allocate just enough memory

    if (data_arr == NULL)
    {
        perror("Error allocating memory");
        fclose(file);
        return 1;
    }

    char row[50];

    while (fgets(row, sizeof(row), file) != NULL) {
        if (size == capacity) { // If it reaches capacity, it multiplies the capacity by 2 and reallocated memory
            // Expand array size and reallocate
            capacity *= 2;
            data_arr = (FITNESS_DATA *)realloc(data_arr, capacity * sizeof(FITNESS_DATA));

            if (data_arr == NULL) {
                perror("Error allocating memory");
                fclose(file);
                return 1;
            }
        }

        // Define temp variables and tokenise row
        char date[11], time[6], steps[10];

        tokeniseRecord(row, &delimiter, date, time, steps);

        // Copy temp values into array.
        strcpy(data_arr[size].date, date);
        strcpy(data_arr[size].time, time);
        data_arr[size].steps = atoi(steps);
        
        size++;
    }

    fclose(file);

    printf("Number of records in file: %d\n", size);

    for (int i = 0; i < 3; i++)
    {
        printf("%s/%s/%d\n", data_arr[i].date, data_arr[i].time, data_arr[i].steps);
    }

    free(data_arr);
    return 0;

    // https://dev.to/crazysamurai/how-to-increase-the-size-of-an-array-in-c-50o0
    //https://www.programiz.com/c-programming/library-function/string.h/strcpy
    // https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm
}