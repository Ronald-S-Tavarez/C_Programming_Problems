/**
 * @file 015_highest_common_factor.c
 * @author Ronald Tavarez
 * @brief Write a program that will read two integers and print their highest common factor.
 */

#include <stdio.h>
#include <stdlib.h>

#define REQUIRED_ARGUMENT_COUNT 3

int main(int argc, char ** argv) {
    if (argc < REQUIRED_ARGUMENT_COUNT) {
        printf("Error: Usage a.exe <int> <int>");
        return EXIT_FAILURE;
    }

    int a = 0, b = 0, buffer = 0;
    int highest_common_factor = 0;

    a = atoi(argv[1]);
    b = atoi(argv[2]);

    if (a == 0 || b == 0) {
        highest_common_factor = 0;
        printf("Heighest Common Factor: %d", highest_common_factor);
        return EXIT_SUCCESS;
    }

    while (b != 0) {
        buffer = a % b;
        a = b;
        b = buffer;
    }
    
    highest_common_factor = a;
    printf("Heighest Common Factor: %d", highest_common_factor);
    return EXIT_SUCCESS;
}