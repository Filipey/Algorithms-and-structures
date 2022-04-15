#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

void fillEmployee(Temp *employee, int size) {
    for (int i = 0; i < size; i++) {
        employee[i].id = i + 1;
        printf("\nType a name for the Employee %d: ", i+1);
        fgets(employee[i].name, 20, stdin);
        printf("\nType the salary of the Employee %d: ", i+1);
        scanf("%f", &employee[i].salary);
        fflush(stdin);
    }
}


void printEmployeeList(Temp *employee, int size) {
    for (int i = 0; i < size; i++) {
        printf("\nEmployee %d Id: %d", i+1, employee[i].id);
        printf("\nEmployee %d Name: %s", i+1, employee[i].name);
        printf("\nEmployee %d Salary: %0.2f", i+1, employee[i].salary);
        printf("\n");
    }
}


Temp sortByName(Temp *employee, int size) {
    Temp aux;
    int i, j;

    for (i = 0; i < size; i++) {
        aux = employee[i];
        for (j = i; (j > 0) && (strcmp(aux.name, employee[j-1].name) < 0); j--) {
            employee[j] = employee[j - 1];
        }
        employee[j] = aux;
    }

    return *employee;
}


Temp sortBySalary(Temp *employee, int size) {
    Temp aux;

    for (int i = 1; i < size; i++) {
        aux = employee[i];
        int j = i - 1;

        while (aux.salary < employee[j].salary && j >= 0) {
            employee[j + 1] = employee[j];
            --j;
        }
        employee[j + 1] = aux;
    }

    return *employee;
}


Temp generateRandomFields(Temp *employee, int size) {
    char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
    'h', 'i', 'j', 'k', 'l', 'm', 'n',
            'o', 'p', 'q', 'r', 's', 't', 'u',
            'v', 'w', 'x', 'y', 'z' };


    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 20; j++) {
         int r = rand() % 26;
         employee[i].name[j] = alphabet[r];
        }
        employee[i].name[20] = '\0';
    }

    for (int i = 0; i < size; i++) {
        employee[i].id = rand() % 100;
    }

    for (int i = 0; i < size; i++) {
        employee[i].salary = rand() % 10000;
    }

    fflush(stdin);

    return *employee;

}