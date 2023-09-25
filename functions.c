#include "header.h"

int getIdFromUser()
{
    int id;
    printf("\nEnter the id : ");
    scanf("%d", &id);
    return id;
}

Employee employeeInput(int id)
{
    Employee emply;
    int dd, mm, yyyy;
    emply.id = id;
    float sal;
    printf("\nEnter First Name : ");
    scanf("%s", &emply.firstName);
    printf("\nEnter last Name : ");
    scanf("%s", &emply.lastName);
    printf("\nEnter the hire date : ");
    scanf("%d%d%d", &dd, &mm, &yyyy);
    while (!isDateValid(dd, mm, yyyy))
    {
        printf("Please enter valid date ;");
        scanf("%d%d%d", &dd, &mm, &yyyy);
    }
    emply.Date.dd = dd;
    emply.Date.mm = mm;
    emply.Date.yyyy = yyyy;
    printf("\nEnter the valid salary : ");
    scanf("%f", &sal);
    while (!isSalaryValid(sal))
    {
        printf("Enter the valid salary : ");
        scanf("%f", &sal);
    }
    emply.basicSal = sal;
    return emply;
}

int addEmployee(Employee empArr[], int last, int size, int id)
{
    if (last < size)
    {
        Employee emp = employeeInput(id);
        empArr[last] = emp;
        return 1;
    }
    return 0;
}

Employee deleteEmployee(Employee empArr[], int last, int id)
{
    Employee emp1;
    for (int i = 0; i < last; i++)
    {
        Employee emp = empArr[i];
        if (emp.id = id)
        {
            for (; i < last - 1; i++)
            {
                empArr[i] = empArr[i + 1];
            }
            return emp;
        }
        emp1.id = -1;
        return emp1;
    }
}

void displayEmployee(Employee empArr[], int last, int id)
{
    for (int i = 0; i < last; i++)
    {
        Employee emp = empArr[i];
        if (emp.id == id)
        {
            printf("\n--------------------------------------------------------------\n");
            printf("Employee Details are: \n");
            printf("Id = %d\nFirst Name = %s\nLast Name = %s\nBasic Salary = %f\n Hire Date = %d/%d/%d\n", emp.id, emp.firstName, emp.lastName, emp.basicSal, emp.Date.dd, emp.Date.mm, emp.Date.yyyy);
            printf("--------------------------------------------------------------\n\n");
            return;
        }
    }
    printf("Employee not found\n");
}

void displayAllEmployees(Employee empArr[], int last)
{
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------");
    printf("\nAll Employee Details are: \n");
    for (int i = 0; i < last; i++)
    {
        Employee emp = empArr[i];
        printf("S.No = %d  Id = %d  First Name = %s  Last Name = %s  Basic Salary = %.2f  Hire Date = %d/%d/%d\n", i + 1, emp.id, emp.firstName, emp.lastName, emp.basicSal, emp.Date.dd, emp.Date.mm, emp.Date.yyyy);
    }
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
}

float netPayment(Employee empArr[], int last, int id)
{
    for (int i = 0; i < last; i++)
    {
        float TA, DA, PF, grossPay;
        Employee emp = empArr[i];
        if (id == emp.id)
        {
            DA = (40 * emp.basicSal) / 100;
            TA = (10 * emp.basicSal) / 100;
            PF = (5 * emp.basicSal) / 100;
            grossPay = emp.basicSal + DA + TA - PF;
            return grossPay;
        }
    }
    return -1;
}

void updateEmployee(Employee empArr[], int last, int id)
{
    for (int i = 0; i < last; i++)
    {
        Employee emp = empArr[i];
        if (emp.id == id)
        {
            int choice = 0;
            while (choice != 4)
            {
                printf("Press 1 to update employee's first name\n");
                printf("Press 2 to update employee's last name\n");
                printf("Press 3 to update employee's salary\n");
                printf("press 4 to exit update function\n");
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                    printf("\nEnter  First Name To Update: ");
                    scanf("%s", emp.firstName);
                    break;
                case 2:
                    printf("\nEnter Last Name To Update: ");
                    scanf("%s", emp.lastName);
                    break;
                case 3:
                    printf("\nEnter Basic Salary To Update: ");
                    scanf("%f", &emp.basicSal);
                    break;
                case 4:
                    break;
                default:
                    printf("Wrong Input!!!! Try again\n\n");
                    break;
                }
            }
            // printf("\nEnter  First Name To Update: ");
            // scanf("%s", emp.firstName);
            // printf("Enter Last Name To Update: ");
            // scanf("%s", emp.lastName);
            // printf("Enter Basic Salary To Update: ");
            // scanf("%f", emp.basicSal);
            empArr[i] = emp;
            printf("Details Updated Successfully!!\n\n");
            displayEmployee(empArr, last, id);
            return;
        }
    }
    printf("Employee Not Found!!!!\n\n");
}

int isYearLeap(int yyyy)
{
    if (yyyy % 400 == 0 || ((yyyy % 4 == 0) && (yyyy % 100 != 0)))
        return 1;
    return 0;
}

int isDateValid(int dd, int mm, int yyyy)
{
    if (dd <= 0 || dd > 31 || mm <= 0 || mm > 12 || yyyy < 0)
        return 0;
    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int result = isYearLeap(yyyy);
    if (result)
    {
        if (mm == 2 && dd <= 29)
            return 1;
        else if (dd <= monthDays[mm - 1])
            return 1;
    }
    else
    {
        if (dd <= monthDays[mm - 1])
            return 1;
    }
    return 0;
}

int isSalaryValid(float sal)
{
    if (sal <= 0)
        return 0;
    return 1;
}