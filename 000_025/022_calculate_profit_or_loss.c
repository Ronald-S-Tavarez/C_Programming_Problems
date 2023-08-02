/**
 * @file 022_calculate_profit_or_loss.c
 * @author Ronald Tavarez
 * @brief Write a program to calculate proft and loss based on cost and selling price.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

bool try_input(char * destination, size_t size, const char * field);
bool file_exists(const char * file_name);

int main(int argc, char ** argv) {
    // Initialize variables.
    FILE * file = NULL;
    float cost_price = 0, sales_price = 0, amount = 0;
    char buffer [20];

    // Get user input for cost price.
    if(!try_input(buffer, sizeof(buffer), "cost price"))
        return EXIT_FAILURE;
    cost_price = atof(buffer);

    // Get user input for sales price.
    if(!try_input(buffer, sizeof(buffer), "sales price"))
        return EXIT_FAILURE;
    sales_price = atof(buffer);

    // Calculate total proft.
    amount = sales_price - cost_price;

    // File manipulation.
    if (!file_exists("data.csv")) {
        file = fopen("data.csv", "a");
        fprintf(file, "sales_price, cost_price, profit\n");
        fclose(file);
    }

    file = fopen("data.csv", "a");
    fprintf(file, "%.2f, %.2f, %.2f\n", sales_price, cost_price, amount);
    // Free file from memory.
    fclose(file);
    return EXIT_SUCCESS;
}

bool try_input(char * destination, size_t size, const char * field) {
    memset(destination, '\0', size);
    printf("Enter %s: ", field);
    if (fgets(destination, size, stdin) == NULL) {
        printf("Error: Failed to read %s.", field);
        return false;
    }
    return true;
}

bool file_exists(const char * file_name) {
    FILE * file = fopen(file_name, "r");
    bool exists = false;
    if (file != NULL) {
        exists = true;
        fclose(file);
    }
    return exists;
}