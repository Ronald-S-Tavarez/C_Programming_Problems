/**
 * @file 021_sum_of_all_numbers.c
 * @author Ronald Tavarez
 * @brief Write a program that finds the sum of all numbers from 0 to N without a loop.
 */

#include <stdio.h>
#include <stdlib.h>

#define REQUIRED_ARGUMENT_COUNT 2

int main(int argc, char ** argv) {
    if (argc < REQUIRED_ARGUMENT_COUNT) {
        printf("Error: Usage a.exe <int>");
        return EXIT_FAILURE;
    }

    int n = atoi(argv[1]);
    int sum = n * (n + 1) / 2;

    printf("The Sum of all Number to %d is %d.", n, sum);
    return EXIT_SUCCESS;
}