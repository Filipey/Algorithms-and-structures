#ifndef TESTE_EMPLOYEE_H
#define TESTE_EMPLOYEE_H

typedef struct Employee {
    int id;
    char name[20];
    float salary;
}Temp;

void fillEmployee(Temp *employee, int size);
void printEmployeeList(Temp *employee, int size);
Temp sortByName(Temp *employee, int size);
Temp sortBySalary(Temp *employee, int size);
Temp generateRandomFields(Temp *employee, int size);

#endif //TESTE_EMPLOYEE_H
