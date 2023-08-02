/**
 * @file 019_number_swap.c
 * @author Ronald Tavarez
 * @brief Write a program to swap to numbers without using a temporary variables 
 */

#include <stdio.h>
#include <stdlib.h>

#define REQUIRED_ARGUMENT_COUNT 3

int main(int argc, char ** argv) {
    if (argc < REQUIRED_ARGUMENT_COUNT) {
        printf("Error: Usage a.exe <int> <int>");
        return EXIT_FAILURE; 
    }
    
    int a = 0, b = 0;
    a = atoi(argv[1]);
    b = atof(argv[2]);

    printf("Unswapped: { A: %d, B: %d}\n", a, b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("Swapped: { A: %d, B: %d }\n", a, b);
    return EXIT_SUCCESS;
}