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
const char fileName[] = "FitnessData_2023.csv";

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
    FITNESS_DATA * steps_array = NULL;
    int size = 0;
    int capacity = 10;
    char row[50];

    file = fopen(fileName, "r");

    // Check fiel is able to be opened.
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    steps_array = (FITNESS_DATA *) malloc(capacity * sizeof(FITNESS_DATA));

    // Check memory allocation was successful.
    if (steps_array == NULL)
    {
        perror("Error allocating memory");
        fclose(file);
        return 1;
    }

    while (fgets(row, sizeof(row), file) != NULL) {
        // Resize the array if there's more items in the file to be added.
        // Found how to resize array here - https://dev.to/crazysamurai/how-to-increase-the-size-of-an-array-in-c-50o0
        if (size == capacity) {
            capacity *= 2;
            FITNESS_DATA *temp_array = (FITNESS_DATA *) malloc(capacity * sizeof(FITNESS_DATA));
            // Check memory allocation was successful.
            if (temp_array == NULL)
            {
                perror("Error allocating memory");
                fclose(file);
                return 1;
            }


            for (int i = 0; i < capacity; i++) {
                temp_array[i] = steps_array[i];
            }

            free(steps_array);
            steps_array = temp_array;
            temp_array = NULL;
        }

        // Define temp variables and tokenise row
        char date[11], time[6], steps[10];

        tokeniseRecord(row, &delimiter, date, time, steps);

        // Copy temp values into array.
        // Saw strcpy in the helper function and looked it up.
        // https://www.programiz.com/c-programming/library-function/string.h/strcpy
        strcpy(steps_array[size].date, date);
        strcpy(steps_array[size].time, time);
        steps_array[size].steps = atoi(steps); // Use atoi to convert sting to int.

        size++;
    }

    fclose(file);

    printf("Number of records in file: %d\n\n", size);

    // Output only the first three items in the array.
    for (int i = 0; i < 3; i++)
    {
        printf("%s/%s/%d\n", steps_array[i].date, steps_array[i].time, steps_array[i].steps);
    }

    // Debugging - Outputs EVERY item in array.
    // for (int i = 0; i < size; i++)
    // {
    //     printf("%s/%s/%d\n", steps_array[i].date, steps_array[i].time, steps_array[i].steps);
    // }

    free(steps_array);
    return 0;

    // https://dev.to/crazysamurai/how-to-increase-the-size-of-an-array-in-c-50o0
    //https://www.programiz.com/c-programming/library-function/string.h/strcpy
    // https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm
}
