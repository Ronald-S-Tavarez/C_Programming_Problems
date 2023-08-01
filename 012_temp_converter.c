/**
 * @file 012_temp_converter.c
 * @author your name (you@domain.com)
 * @brief Temp Converter
 * @def Write a program that can convert a temperature from celsius to fahrenheit and back.
 */

#include <stdio.h>
#include <stdlib.h>

#define REQUIRED_ARGUMENT_COUNT 3

float f_to_c(float value);
float c_to_f(float value);

int main(int argc, char ** argv) {
    if (argc < REQUIRED_ARGUMENT_COUNT) {
        printf("Error: Usage a.exe <int> <char>");
        return EXIT_FAILURE;
    }
    float value = atof(argv[1]);
    char unit = argv[2][0];

    if (unit == 'f' || unit == 'F') {
        printf("%.2fC", f_to_c(value));
    } else if (unit == 'c' || unit == 'C') {
        printf("%.2fF", c_to_f(value));
    } else {
        printf("Error: Usage a.exe <int> [cC | fF]<char>");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

float f_to_c(float value) {
    return (value - 32.0f) * (5.0f/9.0f);
}

float c_to_f(float value) {
    return (value * (9.0f/5.0f)) + 32.0f;
}