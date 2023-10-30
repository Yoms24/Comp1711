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

// Complete the main function
int main() {
    FILE *file;

    file = fopen("FitnessData_2023.csv", "r");

    if (file == NULL)
    {
        printf("Error reading file.\n");
        return 1;
    }

    FITNESS_DATA data[234];

    const int buffer_size = 50;
    char row_buffer[buffer_size];

    int count = 0;
    while (fgets(row_buffer, buffer_size, file) != NULL) {
        char *date[11];
        char *time[6];
        int *steps;

        tokeniseRecord(row_buffer, &delimiter, &date, &time, &steps);

        strcpy(data[count].date, date);
        strcpy(data[count].time, time);
        data[count].steps = atoi(&steps);

        count++;
    }

    for (int i = 0; i < 3; i++)
    {
        printf("%s/%s/%d\n", data[count].date, data[count].time, data[count].steps);
    }

    return 0;
    // https://dev.to/crazysamurai/how-to-increase-the-size-of-an-array-in-c-50o0
}