/**
 * @file 016_unit_converter.c
 * @author Ronald Tavarez
 * @brief Write a program to display feet as inches and or centimeters and vice versa.
 */

#include <stdio.h>
#include <stdlib.h>

#define REQUIRED_ARGUMENT_COUNT 3

void print_units(float feet, float inches, float centimeters);

int main(int argc, char ** argv) {
    if (argc < REQUIRED_ARGUMENT_COUNT) {
        printf("Error: Usage a.exe <float> <char>");
        return EXIT_FAILURE;
    }

    float feet = 0.0f, inches = 0.0f, centimeters = 0.0f;
    char base_unit = argv[2][0];
    switch(base_unit) {
        case 'f':
        case 'F':
            feet = atof(argv[1]);
            inches = feet * 12.0f;
            centimeters = inches * 2.54f;
        break;
        case 'i':
        case 'I':
            inches = atof(argv[1]);
            feet = inches / 12.0f;
            centimeters = inches * 2.54f;
        break;
        case 'c':
        case 'C':
            centimeters = atof(argv[1]);
            inches = centimeters / 2.54f;
            feet = inches / 12.0f;
        break;
    }
    
    print_units(feet, inches, centimeters);

    return EXIT_SUCCESS;
}

void print_units(float feet, float inches, float centimeters) {
    printf("Feet: %.4f\n", feet);
    printf("Inches: %.4f\n", inches);
    printf("Centimeters: %.4f\n", centimeters);
}