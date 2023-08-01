/**
 * @file 020_divisible_by_two.c
 * @author Ronald Tavarez
 * @brief Write a program that finds if a number is divisible by two other numbers. 
 */

#include <stdio.h>
#include <stdlib.h>

#define REQUIRED_ARGUMENT_COUNT 4

int main(int argc, char ** argv) {
    if (argc < REQUIRED_ARGUMENT_COUNT) {
        printf("Error: Usage a.exe dividend<int> divisor<int> divisor<int>");
        return EXIT_FAILURE;
    }

    int dividend = 0, divisor_a = 0, divisor_b = 0;
    dividend = atoi(argv[1]);
    divisor_a = atoi(argv[2]);
    divisor_b = atoi(argv[3]);

    if (dividend % divisor_a == 0 && dividend % divisor_b == 0) {
        printf("%d is divisible by %d and %d\n", dividend, divisor_a, divisor_b);
    } else {
        printf("%d is not divisible by %d and %d\n", dividend, divisor_a, divisor_b);
    }
    return EXIT_SUCCESS;
}