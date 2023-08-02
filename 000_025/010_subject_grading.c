/**
 * @file 010_subject_grading.c
 * @author Ronald Tavarez
 * @brief Subject Grading 
 * @def Write a program to grade students marks and assign each of them an average.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define TOTAL_SUBJECT_COUNT 5
#define MAX_STRING_LENGTH 25
#define TOTAL_STUDENT_COUNT 1

typedef enum Division_Tier {
    FIRST = 90,
    SECOND = 80,
    THIRD = 70,
    FOURTH = 60,
    FIFTH = 50
} Division_Tier;

typedef enum Subject_Name {
    MATH,
    SCIENCE,
    ART,
    ENGLISH,
    PHYSICAL_EDUCATION
} Subject_Name;

typedef struct Subject {
    char name[MAX_STRING_LENGTH];
    float grade;
} Subject;

typedef struct Student {
    char first_name[MAX_STRING_LENGTH];
    char last_name[MAX_STRING_LENGTH];
    Subject subject_array[TOTAL_SUBJECT_COUNT];
} Student;

const char * subject_name_to_string(Subject_Name name);
double sum_subject_grades(const Subject * subject_array, uint8_t length);

void subject_init(Subject * subject);
bool subject_populate(Subject * subject);
void subject_print(const Subject * subject);

void student_init(Student * student);
bool student_populate(Student * student);
void student_print(const Student * student);

int main(int argc, char ** argv) {
    Student student_array[TOTAL_STUDENT_COUNT];
    for (uint8_t i = 0; i < TOTAL_STUDENT_COUNT; i++) {
        student_init(&student_array[i]);
        student_populate(&student_array[i]);
    }

    for (uint8_t i =0; i < TOTAL_STUDENT_COUNT; i++)
    {
        system("cls");
        double sum = sum_subject_grades(student_array[i].subject_array, TOTAL_SUBJECT_COUNT);
        double average = (sum / TOTAL_SUBJECT_COUNT);
        student_print(&student_array[i]);
        printf("Total Marks: %.2f\n", sum);
        printf("Average: %.2f\n", average);
        uint64_t tier = (uint64_t) average;

        if (tier < FIFTH) {
            printf("Division: Fail\n");
        } else if (tier >= FIRST) {
            printf("Division: First\n");
        } else if (tier >= SECOND) {
            printf("Division: Second\n");
        } else if (tier >= THIRD) {
            printf("Division: Third\n");
        } else if (tier >= FOURTH) {
            printf("Division: Fourth\n");
        } else if (tier >= FIFTH) {
            printf("Division: Fifth\n");
        }   
    }
    

    return EXIT_SUCCESS;
}

const char * subject_name_to_string(Subject_Name name) {
    switch (name) {
        case MATH:
            return "Math";
        break;
        case SCIENCE:
            return "Science";
        break;
        case ART:
            return "Art";
        break;
        case ENGLISH:
            return "English";
        break;
        case PHYSICAL_EDUCATION:
            return "Physical Education";
        break;
    }
}

double sum_subject_grades(const Subject * subject_array, uint8_t length) {
    double sum = 0.0f;
    for (uint8_t i = 0; i < length; i++)
        sum = sum + subject_array[i].grade;
    return sum;
}

void subject_init(Subject * subject) {
    memset(subject->name, '\0', sizeof(subject->name));
    subject->grade = 0.0f;
}

bool subject_populate(Subject * subject) {
    printf("Enter Subject Name: ");
    if (fgets(subject->name, sizeof(subject->name), stdin) == NULL) {
        printf("Error Reading Subject Name.\n");
        return false;
    }

    printf("Enter Subject Grade: ");
    char buffer[MAX_STRING_LENGTH];
    memset(buffer, '\0', sizeof(buffer));
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        printf("Error Reading Age.\n");
        return false;
    }
    subject->grade = atof(buffer);

    return true;
}

void subject_print(const Subject * subject) {
    printf("Subject Name: %s", subject->name);
    printf("Subject Grade: %.2f\n", subject->grade);
}

void student_init(Student * student) {
    memset(student->first_name, '\0', sizeof(student->first_name));
    memset(student->last_name, '\0', sizeof(student->last_name));
    for (uint8_t i = 0; i < TOTAL_SUBJECT_COUNT; i++) 
        subject_init(&student->subject_array[i]);
}

bool student_populate(Student * student) {
    printf("Enter Student First Name: ");
    if (fgets(student->first_name, sizeof(student->first_name), stdin) == NULL) {
        printf("Error Reading First Name.\n");
        return false;
    }

    printf("Enter Student Last Name: ");
    if (fgets(student->last_name, sizeof(student->last_name), stdin) == NULL) {
        printf("Error Reading Last Name\n");
        return false;
    }

    for (uint8_t i = 0; i < TOTAL_SUBJECT_COUNT; i++) 
        if (!subject_populate(&student->subject_array[i]))
            return false;

    return true;
}

void student_print(const Student * student) {
    printf("Student First Name: %s", student->first_name);
    printf("Student Last Name: %s", student->last_name);
    for (uint8_t i = 0; i < TOTAL_SUBJECT_COUNT; i++)
        subject_print(&student->subject_array[i]);
}