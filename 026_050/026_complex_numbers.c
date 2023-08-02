/**
 * @file 026_complex_numbers.c
 * @author Ronald Tavarez
 * @brief Write a program to calculate the addition of two complex numbers
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct Complex_Number {
    int real;
    int imaginary;
} Complex_Number;

bool get_user_input(char * destination, size_t size, const char * field);

void complex_number_init(Complex_Number * complex_number);
bool complex_number_populate(Complex_Number * complex_number);
void complex_number_add(Complex_Number * destination, const Complex_Number * a, const Complex_Number * b);
void complex_number_print(const Complex_Number * complex_number);

int main(int argc, char ** argv) {
    Complex_Number numbers [3];
    for (uint8_t i = 0; i < 3; i++)
        complex_number_init(&numbers[i]);
    
    for (uint8_t i = 0; i < 2; i++) {
        printf("Complex Number %d:\n", (i + 1));
        complex_number_populate(&numbers[i]);
    }

    complex_number_add(&numbers[2], &numbers[0], &numbers[1]);

    printf("(");
    complex_number_print(&numbers[0]);
    printf(") + (");
    complex_number_print(&numbers[1]);
    printf(") = (");
    complex_number_print(&numbers[2]);
    printf(")\n");

    return EXIT_SUCCESS;
}

bool get_user_input(char * destination, size_t size, const char * field) {
    memset(destination, '\0', size);
    printf("Enter %s: ", field);
    if (fgets(destination, size, stdin) == NULL) {
        printf("Error: Failed to read %s.\n", field);
        return false;
    }

    size_t ln = strlen(destination) - 1;

    if (*destination && destination[ln] == '\n')
        destination[ln] = '\0';

    return true;
}

void complex_number_init(Complex_Number * complex_number) {
    complex_number->real = 0;
    complex_number->imaginary = 0;
}

bool complex_number_populate(Complex_Number * complex_number) {
    char buffer[100];

    if (!get_user_input(buffer, sizeof(buffer), "real component"))
        return false;
    complex_number->real = atoi(buffer);

    if (!get_user_input(buffer, sizeof(buffer), "imaginary component"))
        return false;
    complex_number->imaginary = atoi(buffer);

    return true;
}

void complex_number_add(Complex_Number * destination, const Complex_Number * a, const Complex_Number * b) {
    destination->real = a->real + b->real;
    destination->imaginary = a->imaginary + b->imaginary;
}

void complex_number_print(const Complex_Number * complex_number) {
    printf("%d + %di", complex_number->real, complex_number->imaginary);
}