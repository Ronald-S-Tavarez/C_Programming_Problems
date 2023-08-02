/**
 * @file 007_even_or_odd.c
 * @author Ronald Tavarez
 * @brief Even or Odd
 * @def Write a program that prints whether a number is even or odd.
 */

#include <stdio.h>
#include <stdlib.h>

#define REQUIRED_ARGUMENT_COUNT 2

int main(int argc, char ** argv) {
    if (argc < REQUIRED_ARGUMENT_COUNT) {
        printf("Error!: Usage a.exe <int>");
        return EXIT_FAILURE;
    }

    int number = 0, remainder = 0;

    number = atoi(argv[1]);
    remainder = number % 2;

    if (remainder == 0) {
        printf("%d is Even", number);
    } else {
        printf("%d is Odd", number);
    }    

    return EXIT_SUCCESS;
}