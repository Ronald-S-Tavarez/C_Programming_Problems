/**
 * @file 025_store_cone.c
 * @author Ronald Tavarez
 * @brief Write a program to calculate the surface area and volume of a cone given its radius and height then save the result to a file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define _USE_MATH_DEFINES
#include <math.h>

typedef struct Cone {
    float height;
    float radius;
    float volume;
    float area;
} Cone;

bool get_user_input(char * destination, size_t size, const char * field);
bool check_file_exists(const char * file_name);

void cone_init(Cone * cone);
bool cone_populate(Cone * cone);
void cone_print_to_csv(const Cone * cone, const char * file_name);

int main(int argc, char ** argv) {
    Cone cone;
    cone_init(&cone);

    if (!cone_populate(&cone))
        return EXIT_FAILURE;
    
    cone_print_to_csv(&cone, "cones.csv");
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

bool check_file_exists(const char * file_name) {
    FILE * file = NULL;
    bool file_exists = false;
    file = fopen(file_name, "r");
    if (file != NULL) {
        file_exists = true;
        fclose(file);
    }
    return file_exists;
}

void cone_init(Cone * cone) {
    cone->area = 0.0f;
    cone->height = 0.0f;
    cone->radius = 0.0f;
    cone->volume = 0.0f;
}

bool cone_populate(Cone * cone) {
    char buffer[100];
    if (!get_user_input(buffer, sizeof(buffer), "height"))
        return false;
    cone->height = atof(buffer);

    if (!get_user_input(buffer, sizeof(buffer), "radius"))
        return false;
    cone->radius = atof(buffer);

    cone->area = (M_PI) * cone->radius * (cone->radius + sqrt(pow(cone->radius, 2) + pow(cone->height, 2)));
    cone->volume = (1.0f / 3.0f) * (M_PI) * pow(cone->radius, 2) * cone->height;
    
    return true;
}

void cone_print_to_csv(const Cone * cone, const char * file_name) {
    FILE * file = NULL;
    if (!check_file_exists(file_name)) {
        file = fopen(file_name, "a");
        fprintf(file, "height, radius, area, volume\n");
        fclose(file);
    }
    file = fopen(file_name, "a");
    fprintf(file, "%.2f, %.2f, %.2f, %.2f\n", cone->height, cone->radius, cone->area, cone->volume);
    fclose(file);
}