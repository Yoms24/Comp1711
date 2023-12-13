#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    const char *pattern = "^[0-9]{4}-[0-9]{2}-[0-9]{2},[0-9]{2}:[0-9]{2},[0-9]+.*$";

    regex_t regex;
    int status = regcomp(&regex, pattern, REG_EXTENDED);

    // Check if the regex compiled successfully.
    if (status != 0) {
        fprintf(stderr, "Error compiling regular expression\n");
        exit(1);
    }

    status = regexec(&regex, record, 0, NULL, 0);

    // Check if the string matches the pattern
    if (status != 0) {
        printf("Error: invalid file");
        exit(1);
    }

    regfree(&regex);
    
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}

// Function to compare two FitnessData structs for use with qsort
int compareFitnessData(const void *a, const void *b) {
    const FitnessData *fitnessDataA = a;
    const FitnessData *fitnessDataB = b;

    if (fitnessDataA->steps < fitnessDataB->steps) {
        return 1;
    } else if (fitnessDataA->steps > fitnessDataB->steps) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    // Variables to store the user's input
    char filename[256];
    char outputFilename[256];

    // Ask the user for a filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: invalid file");
        exit(1);
    }

    // Get the number of records in the file
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    int numRecords = 0;
    for (long i = 0; i < fileSize; i++) {
        if (fgetc(file) == '\n') {
            numRecords++;
        }
    }
    fseek(file, 0, SEEK_SET);

    // Read the records into an array
    FitnessData *fitnessData = malloc(numRecords * sizeof(FitnessData));
    char record[100];
    int recordIndex = 0;
    while (fgets(record, sizeof(record), file) != NULL) {
        tokeniseRecord(record, ',', fitnessData[recordIndex].date, fitnessData[recordIndex].time, &fitnessData[recordIndex].steps);
        recordIndex++;
    }
    fclose(file);

    // Sort the data in descending order of steps
    qsort(fitnessData, numRecords, sizeof(FitnessData), compareFitnessData);

    // Create the output filename
    strcpy(outputFilename, filename);
    strcat(outputFilename, ".tsv");

    // Open the output file
    FILE *outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL) {
        perror("Error: invalid output file");
        free(fitnessData);
        return 1;
    }

    // Write the sorted data to the output file
    for (int i = 0; i < numRecords; i++) {
        fprintf(outputFile, "%s\t%s\t%d\n", fitnessData[i].date, fitnessData[i].time, fitnessData[i].steps);
    }
    fclose(outputFile);

    // Free the memory
    free(fitnessData);

    return 0;
}