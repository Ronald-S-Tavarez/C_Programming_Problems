/**
 * @file 003_print_ascii.c
 * @author Ronald Tavarez
 * @brief Print ASCII value
 * @def Write a program to print the ASCII Value of a character.
 */

#include <stdio.h>
#include <stdlib.h>

#define REQUIRED_ARGUMENT_COUNT 2

int main(int argc, char ** argv) {
    if (argc < REQUIRED_ARGUMENT_COUNT) {
        printf("Error!: Usage a.exe <char>");
        return EXIT_FAILURE;
    }
    char character = '\0';
    character = argv[1][0];
    
    printf("Character: %c\n", character);
    printf("ASCII Value: %d\n", character);

    return EXIT_SUCCESS;
}