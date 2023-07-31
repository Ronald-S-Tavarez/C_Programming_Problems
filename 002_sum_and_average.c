/**
 * @file 002_sum_and_average.c
 * @author Ronald Tavarez
 * @brief Sum and Average of two numbers
 * @def Write a program to calculate the sum and average of two integers.
 */

#include <stdio.h>
#include <stdlib.h>

#define REQUIRED_ARGUMENT_COUNT 3

int main(int argc, char ** argv) {
    if (argc < REQUIRED_ARGUMENT_COUNT) {
        printf("Error!: Usage a.exe <int> <int>");
        return EXIT_FAILURE;
    }

    int a = 0, b = 0, sum = 0;
    float average = 0.0f;

    a = atoi(argv[1]);
    b = atoi(argv[2]);
    sum = a + b;
    average = (float)sum / (float)(REQUIRED_ARGUMENT_COUNT - 1);

    printf("A: %d | ", a);
    printf("B: %d\n", b);
    printf("Sum: %d\n", sum);
    printf("Average: %.2f", average);

    return EXIT_SUCCESS;
}