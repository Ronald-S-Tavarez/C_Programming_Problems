/**
 * @file 011_gross_salary.c
 * @author Ronald Tavarez
 * @brief Gross Salary
 * @def Write a program that calculate's the gross salary of an employee.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Employee {
    char first_name[25];
    char last_name[25];
    float basic_salary;
    float dearness_allowance;
    float house_rent_allowance;
    float provident_fund;
    float gross_salary;
} Employee;


bool try_input(char * destination, size_t size, const char * field);
void employee_init(Employee * employee);
bool employee_populate(Employee * employee);
void employee_print(const Employee * employee);

int main(int argc, char ** argv) {
    Employee employee;
    employee_init(&employee);
    employee_populate(&employee);
    system("cls");
    employee_print(&employee);
    return EXIT_SUCCESS;
}

bool try_input(char * destination, size_t size, const char * field) {
    printf("Enter %s: ", field);
    if (fgets(destination, size, stdin) == NULL) {
        printf("Error: Failed to read %s.", field);
        return false;
    }
    return true;
}

void employee_init(Employee * employee) {
    memset(employee->first_name, '\0', sizeof(employee->first_name));
    memset(employee->last_name, '\0', sizeof(employee->last_name));
    employee->basic_salary = 0.0f;
    employee->dearness_allowance = 0.0f;
    employee->house_rent_allowance = 0.0f;
    employee->provident_fund = 0.0f;
    employee->gross_salary = 0.0f;
}

bool employee_populate(Employee * employee) {
    char buffer[25];

    if (!try_input(employee->first_name, sizeof(employee->first_name), "first name"))
        return false;

    if (!try_input(employee->last_name, sizeof(employee->last_name), "last name")) 
        return false;

    memset(buffer, '\0', sizeof(buffer));
    if (!try_input(buffer, sizeof(buffer), "basic salary"))
        return false;
    employee->basic_salary = atof(buffer);

    memset(buffer, '\0', sizeof(buffer));
    if (!try_input(buffer, sizeof(buffer), "dearness allowance"))
        return false;
    employee->dearness_allowance = atof(buffer);

    memset(buffer, '\0', sizeof(buffer));
    if (!try_input(buffer, sizeof(buffer), "house rent allowance"))
        return false;
    employee->house_rent_allowance = atof(buffer);
    

    employee->provident_fund = (employee->basic_salary * 12) / 100;
    employee->gross_salary = employee->basic_salary + employee->dearness_allowance + employee->house_rent_allowance + employee->provident_fund;

    return true;
}

void employee_print(const Employee * employee) {
    printf("First Name: %s", employee->first_name);
    printf("Last Name: %s", employee->last_name);
    printf("Basic Salary: %.2f\n", employee->basic_salary);
    printf("DA: %.2f\n", employee->dearness_allowance);
    printf("HRA: %.2f\n", employee->house_rent_allowance);
    printf("PF: %.2f\n", employee->provident_fund);
    printf("Gross Salary: %.2f\n", employee->gross_salary);
}