/**
 * @file 018_provident_fund.c
 * @author Ronald Tavarez 
 * @brief Write a program to calculate employee and employer contribution in provident fund based on basic pay.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define EMPLOYEE_PERCENTAGE 12.5f
#define EMPLOYER_PERCENTAGE 12.0f

typedef struct Employee {
    char first_name[25];
    char last_name[25];
    float basic_salary;
    float pf_contribution;
} Employee;

typedef struct Employer {
    char business_name[30];
    float pf_contribution;
} Employer;

bool try_input(char * destination, size_t size, const char * prompt);

void employee_init(Employee * employee);
bool employee_populate(Employee * employee);
void employee_print(const Employee * employee);

void employer_init(Employer * employer);
bool employer_populate(Employer * employer, const Employee * employee);
void employer_print(const Employer * employer);

int main(int argc, char ** argv) {
    Employee employee;
    Employer employer;

    employee_init(&employee);
    employer_init(&employer);

    employee_populate(&employee);
    employer_populate(&employer, &employee);
    system("cls");
    employer_print(&employer);
    puts("");
    employee_print(&employee);
    return EXIT_SUCCESS;
}

bool try_input(char * destination, size_t size, const char * prompt) {
    memset(destination, '\0', size);
    printf("Enter %s: ", prompt);
    if (fgets(destination, size, stdin) == NULL) {
        printf("Error: Failed to read %s.\n", prompt);
        return false;
    }
    return true;
}

void employee_init(Employee * employee) {
    memset(employee->first_name, '\0', sizeof(employee->first_name));
    memset(employee->last_name, '\0', sizeof(employee->last_name));
    employee->basic_salary = 0.0f;
    employee->pf_contribution = 0.0f;
}

bool employee_populate(Employee * employee) {
    char buffer[30];

    if (!try_input(employee->first_name, sizeof(employee->first_name), "first name"))
        return false;
    
    if (!try_input(employee->last_name, sizeof(employee->last_name), "last name"))
        return false;
    
    if (!try_input(buffer, sizeof(buffer), "basic salary"))
        return false;
    employee->basic_salary = atof(buffer);

    employee->pf_contribution = (employee->basic_salary / 100.0f) * EMPLOYEE_PERCENTAGE;
}

void employee_print(const Employee * employee) {
    printf("%-16s %s", "First Name:", employee->first_name);
    printf("%-16s %s", "Last Name:", employee->last_name);
    printf("%-16s %.2f\n", "Basic Salary:", employee->basic_salary);
    printf("%-16s %.2f\n", "PF Contribution:", employee->pf_contribution);
}

void employer_init(Employer * employer) {
    memset(employer->business_name, '\0', sizeof(employer->business_name));
    employer->pf_contribution = 0.0f;
}

bool employer_populate(Employer * employer, const Employee * employee) {
    if (!try_input(employer->business_name, sizeof(employer->business_name), "business name"))
        return false;
    
    employer->pf_contribution = (employee->basic_salary / 100.0f) * EMPLOYER_PERCENTAGE;
}

void employer_print(const Employer * employer) {
    printf("%-16s %s", "Business Name:", employer->business_name);
    printf("%-16s %.2f\n", "PF Contribution:", employer->pf_contribution);
}