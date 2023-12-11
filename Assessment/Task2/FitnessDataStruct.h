#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

double round(double x) {
    double decimal_part = x - (int)x;
    
    if (decimal_part >= 0.5) {
        return (int)x + 1;
    } else {
        return (int)x;
    }
}

void printLargestStepsData(FITNESS_DATA data[], int dataCount)
{
    int mostSteps = 0;
    int index = 0;

    for (int i = 0; i < dataCount; i++) {
        if (data[i].steps > mostSteps) {
            mostSteps = data[i].steps;
            index = i;
        }
    }

    printf("Largest steps: %s %s\n", data[index].date, data[index].time);
}

void printFewestStepsData(FITNESS_DATA data[], int dataCount)
{
    int fewestSteps = 1000000;
    int index = 0;

    for (int i = 0; i < dataCount; i++) {
        if (data[i].steps < fewestSteps) {
            fewestSteps = data[i].steps;
            index = i;
        }
    }

    printf("Fewest steps: %s %s\n", data[index].date, data[index].time);
}

void printLongestPeriodData(FITNESS_DATA data[], int dataCount)
{
    int longestPeriod = 0;
    int currentPeriod = 0;
    int startIndex = 0;
    int endIndex = 0;

    for (int i = 0; i < dataCount; i++) {
        if (data[i].steps > 500) {
            currentPeriod++;
        }
        else {
            if (currentPeriod > longestPeriod) {
                longestPeriod = currentPeriod;
                endIndex = i - 1;
                startIndex = endIndex - longestPeriod + 1;
            }
            currentPeriod = 0;
        }
    }

    printf("Logest period start: %s %s\n", data[startIndex].date, data[startIndex].time);
    printf("Logest period end: %s %s\n", data[endIndex].date, data[endIndex].time);
}

void printMeanStepCountData(FITNESS_DATA data[], int dataCount)
{
    int totalSteps = 0;
    for (int i = 0; i < dataCount; i++)
    {
        totalSteps += data[i].steps;
    }

    double meanStepCount = (double)totalSteps / dataCount;

    printf("Mean step count: %.0f\n", round(meanStepCount));
}

// Helper function prototypes
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps);


#endif // FITNESS_DATA_STRUCT_H