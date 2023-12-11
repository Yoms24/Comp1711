#ifndef HELPERS_H
#define HELPERS_H

#include <stdio.h>

double round(double x) {
    double decimal_part = x - (int)x;
    
    if (decimal_part >= 0.5) {
        return (int)x + 1;
    } else {
        return (int)x;
    }
}

#endif // HELPERS_H