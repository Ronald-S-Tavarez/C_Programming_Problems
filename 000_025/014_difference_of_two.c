/**
 * @file 014_difference_of_two.c
 * @author Ronald Tavarez
 * @brief Difference of two numbers
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>

#define REQUIRED_ARGUMENT_COUNT 3

int main(int argc, char ** argv) {
    if (argc < REQUIRED_ARGUMENT_COUNT) {
        printf("Error: Usage a.exe <int> <int>");
        return EXIT_FAILURE;
    }

    int max = INT_MIN;
    int difference = 0;
    for (uint8_t i = 1; i < REQUIRED_ARGUMENT_COUNT; i++)
        if (max < atoi(argv[i]))
            max = atoi(argv[i]);
    
    for (uint8_t i = 1; i < REQUIRED_ARGUMENT_COUNT; i++)
        if (atoi(argv[i]) != max)
            difference = max - atoi(argv[i]);

    printf("The Difference is %d\n", difference);

    return EXIT_SUCCESS;
}