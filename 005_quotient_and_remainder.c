/**
 * @file 005_quotient_and_remainder.c
 * @author Ronald tavarez
 * @brief Quotient and Remainder
 * @def Write a program to find the quotient and remainder of two numbers.
 */

#include <stdio.h>
#include <stdlib.h>

#define REQUIRED_ARGUMENT_COUNT 3

int main(int argc, char ** argv) {
    if (argc < REQUIRED_ARGUMENT_COUNT) {
        printf("Error!: Usage a.exe <int> <int>");
        return EXIT_FAILURE;
    }

    int dividend = 0, divisor = 0, remainder = 0;
    float quotient = 0.0f;

    dividend = atoi(argv[1]);
    divisor = atoi(argv[2]);

    quotient = dividend / divisor;
    remainder = dividend % divisor;

    printf("Dividend: %d\n", dividend);
    printf("Divisor: %d\n", divisor);
    printf("Quotient: %.2f\n", quotient);
    printf("Remainder: %d", remainder);

    return EXIT_SUCCESS;
}