/**
 * @file 024_store_sphere.c
 * @author Ronald Tavarez
 * @brief Write a program to calculate the surface area and volume of a sphere given its radius and save the results to a file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string.h>

typedef struct Sphere {
    float radius;
    float volume;
    float surface_area;
} Sphere;

bool get_user_input(char * destination, size_t size, const char * field);
bool check_file_exists(const char * file_name);

void sphere_init(Sphere * sphere);
bool sphere_populate(Sphere * sphere);
void sphere_print_to_csv(const Sphere * sphere, const char * file_name);

int main(int argc, char ** argv) {
    Sphere sphere;
    sphere_init(&sphere);

    if (!sphere_populate(&sphere))
        return EXIT_FAILURE;

    sphere_print_to_csv(&sphere, "spheres.csv");
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

void sphere_init(Sphere * sphere) {
    sphere->radius = 0.0f;
    sphere->surface_area = 0.0f;
    sphere->volume = 0.0f;
}

bool sphere_populate(Sphere * sphere) {
    char buffer[100];
    if (!get_user_input(buffer, sizeof(buffer), "radius"))
        return false;
    sphere->radius = atof(buffer);

    sphere->volume = (4.0f / 3.0f) * (M_PI) * pow(sphere->radius, 3);
    sphere->surface_area = 4.0f * (M_PI) * pow(sphere->radius, 2);

    return true;
}

void sphere_print_to_csv(const Sphere * sphere, const char * file_name) {
    FILE * file = NULL;
    if (!check_file_exists(file_name)) {
        file = fopen(file_name, "a");
        fprintf(file, "radius, volume, surface_area\n");
        fclose(file);
    }
    file = fopen(file_name, "a");
    fprintf(file, "%.2f, %.2f, %.2f\n", sphere->radius, sphere->volume, sphere->surface_area);
    fclose(file);
}