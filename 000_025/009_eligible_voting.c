/**
 * @file 009_eligible_voting.c
 * @author Ronald Tavarez
 * @brief Eligible Voting
 * @def Write a program to check whether a person is eligible for voting.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define REQUIRED_AGE_TO_VOTE 18

typedef struct Person {
    char first_name[25];
    char last_name[25];
    uint8_t age;
} Person;

void init_person(Person * person);
bool create_person(Person * person);
void print_person(const Person * person);
bool person_is_eligible_to_vote(const Person * person);

int main(int argc, char ** argv) {
    Person person;
    init_person(&person);

    if (!create_person(&person)) {
        printf("Error!: Failed to Create Person\n");
        return EXIT_FAILURE;
    }

    if (person_is_eligible_to_vote(&person)) {
        print_person(&person);
        printf("This person is eligible to vote.\n");
    } else {
        print_person(&person);
        printf("This person is not eligible to vote.\n");
    }
    
    return EXIT_SUCCESS;
}

void init_person(Person * person) {
    memset(person->first_name, '\0', sizeof(person->first_name));
    memset(person->last_name, '\0', sizeof(person->last_name));
    person->age = 0;
}

bool create_person(Person * person) {
    printf("Enter First Name: ");
    if (fgets(person->first_name, sizeof(person->first_name), stdin) == NULL) {
        printf("Error Reading First Name\n");
        return false;
    }

    printf("Enter Last Name: ");
    if (fgets(person->last_name, sizeof(person->last_name), stdin) == NULL) {
        printf("Error Reading Last Name\n");
        return false;
    }

    printf("Enter Age: ");
    char age[4];
    memset(age, '\0', sizeof(age));
    if (fgets(age, sizeof(age), stdin) == NULL) {
        printf("Error Reading Age\n");
        return false;
    }
    person->age = atoi(age);

    return true;
}

void print_person(const Person * person) {
    printf("First Name: %s", person->first_name);
    printf("Last Name: %s", person->last_name);
    printf("Age: %d\n", person->age);
}

bool person_is_eligible_to_vote(const Person * person) {
    return (person->age >= REQUIRED_AGE_TO_VOTE);
}