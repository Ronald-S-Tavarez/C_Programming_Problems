/**
 * @file 006_simple_interest.c
 * @author Ronald Tavarez
 * @brief Simple Interest
 * @def Write a program to calculate simple interest.
 */

#include <stdio.h>
#include <stdlib.h>

#define REQUIRED_ARGUMENT_COUNT 4

int main(int argc, char ** argv) {
    if (argc < REQUIRED_ARGUMENT_COUNT) {
        printf("Error!: Usage a.exe amount<float> rate<float> time<float>");
        return EXIT_FAILURE;
    }

    float amount = 0.0f, rate = 0.0f, time = 0.0f, calculated_interest = 0.0f;
    
    amount = atof(argv[1]);
    rate = atof(argv[2]);
    time = atof(argv[3]);

    calculated_interest = (amount * rate * time) / 100;

    printf("Amount: $%.2f\n", amount);
    printf("Rate: %.2f\n", rate);
    printf("Time: %.2f years\n", time);
    printf("Simple Interest: $%.2f\n", calculated_interest);

    return EXIT_SUCCESS;
}