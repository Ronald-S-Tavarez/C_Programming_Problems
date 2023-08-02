/**
 * @file 008_largest_of_three.c
 * @author Ronald Tavarez
 * @brief Largest of Three
 * @def Write a program that finds that largest of three numbers.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define REQUIRED_ARGUMENT_COUNT 4

int main(int argc, char ** argv) {
    if (argc < REQUIRED_ARGUMENT_COUNT) {
        printf("Error!: Usage a.exe <int> <int> <int>");
        return EXIT_FAILURE;
    }

    int max = INT_MIN;

    for (int i = 1; i < REQUIRED_ARGUMENT_COUNT; i++) {
        int number = atoi(argv[i]);
        if (max < number)
            max = number;
    }

    printf("A: %s, B: %s, C: %s\n", argv[1], argv[2], argv[3]);
    printf("Max: %d", max);

    return EXIT_SUCCESS;
}