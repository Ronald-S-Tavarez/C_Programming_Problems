/**
 * @file 017_net_salary.c
 * @author Ronald Tavarez
 * @brief Write a program to calculate the net salary of an employee
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Employee {
    char first_name[25];
    char last_name[25];
    float basic_salary;
    float da;
    float hra;
    float ta;
    float pf;
    float it;
    float others;
    float net_salary;
} Employee;

bool try_input(char * destination, size_t size, const char * prompt);

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
    employee->da = 0.0f;
    employee->hra = 0.0f;
    employee->ta = 0.0f;
    employee->pf = 0.0f;
    employee->it = 0.0f;
    employee->others = 0.0f;
    employee->net_salary = 0.0f;
}

bool employee_populate(Employee * employee) {
    char buffer[25];
    if (!try_input(employee->first_name, sizeof(employee->first_name), "first name"))
        return false;
    
    if (!try_input(employee->last_name, sizeof(employee->last_name), "last name"))
        return false;

    if (!try_input(buffer, sizeof(buffer), "basic salary"))
        return false;
    employee->basic_salary = atof(buffer);

    if (!try_input(buffer, sizeof(buffer), "hra"))
        return false;
    employee->hra = atof(buffer);

    if (!try_input(buffer, sizeof(buffer), "ta"))
        return false;
    employee->ta = atof(buffer);

    if (!try_input(buffer, sizeof(buffer), "others"))
        return false;
    employee->others = atof(buffer);

    // Calculate DA 12% of Basic Salary
    employee->da = (employee->basic_salary * 12.0f) / 100.0f;

    // Calculate PF 14% of Basic Salary
    employee->pf = (employee->basic_salary * 14.0f) / 100.0f;

    // Calculate IT 15% of Basic Salary
    employee->it = (employee->basic_salary * 15.0f) / 100.0f;

    // Calculate Net Salary
    employee->net_salary = employee->basic_salary + employee->da + employee->hra + employee->ta + employee->others - (employee->pf + employee->it);

    return true;
}

void employee_print(const Employee * employee) {
    printf("%-13s %s", "First Name:", employee->first_name);
    printf("%-13s %s", "Last Name:", employee->last_name);
    printf("%-13s $%.2f\n", "Basic Salary:", employee->basic_salary);
    printf("%-13s $%.2f\n", "HRA:", employee->hra);
    printf("%-13s $%.2f\n", "TA:", employee->ta);
    printf("%-13s $%.2f\n", "Others:", employee->others);
    printf("%-13s $%.2f\n", "DA:", employee->da);
    printf("%-13s $%.2f\n", "PF:", employee->pf);
    printf("%-13s $%.2f\n", "IT:", employee->it);
    printf("%-13s $%.2f\n", "Net Salary:", employee->net_salary);
}