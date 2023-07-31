/**
 * @file 001_subtract_two_int.c
 * @author Ronald Tavarez
 * @brief Subtract two integers
 * @def Write a program to subtract two integers from the console.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
    if (argc < 3) {
        puts("Must Enter 2 Enters!");
        return 1;
    }
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int result = a - b;
    printf("%d", result);
    return 0;    
}