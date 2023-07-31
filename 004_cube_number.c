/**
 * @file 004_cube_number.c
 * @author Ronald Tavarez
 * @brief Cube a Number
 * @def Write a program that cubes a number received from console input.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define REQUIRED_ARGUMENT_COUNT 2

int main(int argc, char ** argv) {
    if (argc < REQUIRED_ARGUMENT_COUNT) {
        printf("Error!: Usage a.exe <int>");
        return EXIT_FAILURE;
    }

    int a = 0, result = 0;
    a = atoi(argv[1]);
    result = pow(a, 3);

    printf("Number: %d\n", a);
    printf("Cube: %d\n", result);

    return EXIT_SUCCESS;
}