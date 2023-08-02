/**
 * @file 023_grade_system.c
 * @author Ronald Tavarez
 * @brief Write a program that allows you to save student information and their grades to a file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FIELD_LENGTH 50

typedef struct Student {
    char first_name[MAX_FIELD_LENGTH];
    char last_name[MAX_FIELD_LENGTH];
    char phone_number[MAX_FIELD_LENGTH];
    char email[MAX_FIELD_LENGTH];
    float grade;
    char grade_description[MAX_FIELD_LENGTH];
} Student;

bool get_user_input(char * destination, size_t size, const char * field);
bool check_file_exists(const char * file_name);
const char * get_grade_description(float grade);
void remove_trailing_newline(char * string);

void student_init(Student * student);
bool student_populate(Student * student);
void student_print_to_csv(const Student * student, const char * file_name);

int main(int argc, char ** argv) {
    Student student;
    student_init(&student);

    if (!student_populate(&student))
        return EXIT_FAILURE;

    student_print_to_csv(&student, "students.csv");
    return EXIT_SUCCESS; 
}

bool get_user_input(char * destination, size_t size, const char * field) {
    memset(destination, '\0', size);
    printf("Enter %s: ", field);
    if (fgets(destination, size, stdin) == NULL) {
        printf("Error: Failed to read %s.", field);
        return false;
    }
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

const char * get_grade_description(float grade) {
    if (grade > 90) 
        return "Excellent";

    if (grade > 80)
        return "Very Good";
    
    if (grade > 70)
        return "Good";

    if (grade > 60)
        return "Mediocre";
    
    if (grade > 50)
        return "Poor";
    
    return "Failed";
}

void remove_trailing_newline(char * string) {
    size_t ln = strlen(string) - 1;
    if (*string && string[ln] == '\n')
        string[ln] = '\0';
}

void student_init(Student * student) {
    memset(student->first_name, '\0', sizeof(student->first_name));
    memset(student->last_name, '\0', sizeof(student->last_name));
    memset(student->phone_number, '\0', sizeof(student->phone_number));
    memset(student->email, '\0', sizeof(student->email));
    student->grade = 0.0f;
    memset(student->grade_description, '\0', sizeof(student->grade_description));
}

bool student_populate(Student * student) {
    char buffer[MAX_FIELD_LENGTH];
    if (!get_user_input(student->first_name, sizeof(student->first_name), "first name"))
        return false;
    remove_trailing_newline(student->first_name);
    
    if (!get_user_input(student->last_name, sizeof(student->last_name), "last name"))
        return false;
    remove_trailing_newline(student->last_name);
    
    if (!get_user_input(student->phone_number, sizeof(student->phone_number), "phone number"))
        return false;
    remove_trailing_newline(student->phone_number);

    if (!get_user_input(student->email, sizeof(student->email), "email"))
        return false;
    remove_trailing_newline(student->email);

    if (!get_user_input(buffer, sizeof(buffer), "grade"))
        return false;
    student->grade = atof(buffer);
    
    if (strcpy_s(student->grade_description, sizeof(student->grade_description), get_grade_description(student->grade)) != 0)
        return false;
    remove_trailing_newline(student->grade_description);

    return true;
}

void student_print_to_csv(const Student * student, const char * file_name) {
    FILE * file = NULL;
    if (!check_file_exists(file_name)) {
        file = fopen(file_name, "a");
        fprintf(file, "first_name, last_name, phone_number, email, grade, grade_description\n");
        fclose(file);
    }
    file = fopen(file_name, "a");
    fprintf(
        file,
        "%s, %s, %s, %s, %.2f, %s\n", 
        student->first_name, 
        student->last_name,
        student->phone_number,
        student->email,
        student->grade,
        student->grade_description
    );
    fclose(file);
}