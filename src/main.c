#include <stdio.h>
#include <stdlib.h>
#include "../headers/Employee.h"

int main() {

    int size, op;
    printf("Type the numbers of employees of your company: ");

    scanf("%d", &size);
    fflush(stdin);

    Temp *employee = (Temp *) malloc(size * sizeof (Temp));

    do {
        printf("\nType a operation:\n(1) INSERT MANUALLY EMPLOYEES\n(2) GENERATE RANDOM EMPLOYEES\n(3) PRINT EMPLOYEES\n(4) SORT BY NAME\n(5) SORT BY SALARY\n(-1) EXIT MENU\n");
        scanf("%d", &op);
        fflush(stdin);

        switch (op) {
            case 1:
                fillEmployee(employee, size);
                break;

            case 2:
                generateRandomFields(employee, size);
                break;

            case 3:
                printEmployeeList(employee, size);
                break;

            case 4:
                sortByName(employee, size);
                break;

            case 5:
                sortBySalary(employee, size);
                break;

            case -1:
                break;

            default:
                printf("Invalid value. Type again!");
                break;
        }
    } while (op != -1);

    free(employee);

    return 0;
}
