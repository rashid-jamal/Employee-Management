#include <stdio.h>
#include "functions.c"
#define size 150

int main()
{
    Employee empArr[size];
    int autoGenId = 100;
    int choice = 0;
    int last = 0;
    float netSalary;
    int res, id;
    while (choice != 7)
    {
        printf("Press 1 to add an employee\n");
        printf("Press 2 to delete an employee\n");
        printf("Press 3 to display an employee\n");
        printf("Press 4 to display all employee\n");
        printf("Press 5 to update employee details\n");
        printf("Press 6 to get employee net pay\n");
        printf("Press 7 to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            res = addEmployee(empArr, last, size, autoGenId);
            if (res)
            {
                last++;
                printf("Employee added successfully with id = %d!!\n\n", autoGenId);
                autoGenId++;
            }
            else
            {
                printf("Unable to add employee!!!!\n\n");
            }
            break;
        case 2:
            id = getIdFromUser();
            Employee e = deleteEmployee(empArr, last, id);
            if (e.id != id)
            {
                printf("Employee not found!!!!\n\n");
            }
            else
            {
                printf("Employee with id = %d deleted successfully!!\n", id);
                printf("id = %d First Name = %s Last Name = %s Hire Date = %d/%d/%d Basic Salary = %f\n\n", e.id, e.firstName, e.lastName, e.Date.dd, e.Date.mm, e.Date.yyyy, e.basicSal);
                last--;
            }
            break;
        case 3:
            id = getIdFromUser();
            displayEmployee(empArr, last, id);
            break;
        case 4:
            displayAllEmployees(empArr, last);
            break;
        case 5:
            id = getIdFromUser();
            updateEmployee(empArr, last, id);
            break;
        case 6:
            id = getIdFromUser();
            netSalary = netPayment(empArr, last, id);
            if ((int)netSalary != -1)
            {
                printf("The net pay of employee with id = %d is = %f\n\n", id, netSalary);
            }
            else
            {
                printf("Employee not found!!!!\n\n");
            }
            break;
        case 7:
            break;
        default:
            printf("Wrong Input!!!! Try again\n\n");
            break;
        }
    }
}
