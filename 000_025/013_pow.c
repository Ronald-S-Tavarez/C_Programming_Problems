/**
 * @file 013_pow.c
 * @author Ronald Tavarez
 * @brief Pow using console
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define REQUIRED_ARGUMENT_COUNT 3

int main(int argc, char ** argv) {
    if (argc < REQUIRED_ARGUMENT_COUNT) {
        printf("Error: Usage a.exe <float> <float>");
        return EXIT_FAILURE;
    }

    float base = atof(argv[1]);
    float exponent = atof(argv[2]);
    printf("Base: %.2f\n", base);
    printf("Exponent: %.2f\n", exponent);
    printf("Result: %.2f\n", pow(base, exponent));
    return EXIT_SUCCESS;
}