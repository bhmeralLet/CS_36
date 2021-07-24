#include <stdio.h>
#include <stdlib.h>


/**
 * Creating an Employee struct defining employee's data
 */
struct Employee{
    char employeeName[20];
    int employeeHoursWorked;
    double employeeHourlyRate;
    double grossPayment;
    double overTimePayment;
    double taxPaid;
};
/**
 * loadEmployee - It will prompt user to enter the given employee data
 * and initializing the data using pass by reference
 * @param employee - pointer to struct Employee
 */
void loadEmployee(struct Employee *employee){
    printf("Enter the employee name:");
    scanf("%s", employee->employeeName);
    printf("Enter the hourly rate:");
    scanf("%lf", &employee->employeeHourlyRate);
    printf("Enter hours worked:");
    scanf("%d",&employee->employeeHoursWorked);

}
/**
 * printEmployeeData - It will print the employee's data, accessing the data with employee pointer;
 * @param employee - pointer to struct Employee
 */
void printEmployeeData(struct Employee *employee){
    printf("\nEmployee name:%s\n",employee->employeeName);
    printf("Hours worked:%d\n",employee->employeeHoursWorked);
    printf("Hourly rate:$%0.2f\n",employee->employeeHourlyRate);
    printf("Gross paid:$%0.2f\n",employee->grossPayment);
    printf("Overtime paid:$%0.2f\n",employee->overTimePayment);
    printf("Tax paid:$%0.2f\n",employee->taxPaid);
}
/**
 * printAllEmployeeData - It will print employee's data in a summary view, accessing employee's data with employee pointer;
 * even though it is named printAllEmployeeData it just prints one employee's data in a summary view.
 * We call the method inside the loop to print all employee data iterating through employees[].
 * @param employee
 */
void printAllEmployeeData(struct Employee *employee){
    printf("\nEmployee name:%s\n",employee->employeeName);
    printf("Hours worked:%d\n",employee->employeeHoursWorked);
    printf("Hourly rate:$%0.2f\n",employee->employeeHourlyRate);
    printf("Gross paid:$%0.2f\n",employee->grossPayment);
}

/**
 * loadMenu - It will display the menu of options and ask the user to which operation user wants.
 * @return choice - returning an integer for user's choice which operation user wants to do.
 */
 int loadMenu(){
    int choice;
    printf("Enter the operation number you want to do.");
    printf("\n1.Enter employee data.");
    printf("\n2.Display employee data.");
    printf("\n3.Display all employee data.");
    printf("\n4.Edit an employee data.");
    printf("\n0.Quit the application\n");
    scanf_s("%d",&choice);
    if(choice < 0 || choice > 4){
        printf("Cannot respond to given choice..\n");
        printf("Quitting the application...");
        exit(0);
    }
    return choice;
}

void payment(struct Employee *employee){

    if((employee->employeeHoursWorked) > 40){
        employee->overTimePayment = ((employee->employeeHoursWorked) - 40) * 1.5 * (employee->employeeHourlyRate);
    }else{
        employee->overTimePayment = 0;
    }
    employee->grossPayment = (employee->employeeHoursWorked) * (employee->employeeHourlyRate) + employee->overTimePayment;
    employee->taxPaid = (employee->grossPayment) * .2;
}

int main() {

    struct Employee employees[5];
    int employeeIndex;
    int flag = 0;
    int loopIndex = 0;
    int choice;
    do {
        choice = loadMenu();
        switch (choice) {
            case 0:
                printf("Quitting the application..");
                exit(0);
            case 1:
                loadEmployee(&employees[loopIndex]);
                payment(&employees[loopIndex]);
                loopIndex++;
                break;
            case 2:
                printf("Enter the index of the employee..");
                scanf("%d", &employeeIndex);
                if (employeeIndex > (sizeof(employees) / sizeof(struct Employee)) || employeeIndex < 0) {
                    printf("You don't have any employee's at this index..");
                    printf("Returning to the main menu..");
                    break;
                } else {
                    printEmployeeData(&employees[employeeIndex]);
                }
                break;
            case 3:
                printf("Printing all employee's summary data");
                for (int employee = 0; employee < loopIndex; ++employee) {
                    if (loopIndex == 0) {
                        printf("There is no employee data on the system yet.");
                        printf(" Returning to the main menu.\n");
                        break;
                    } else {
                        printAllEmployeeData(&employees[employee]);
                    }
                }
                break;
            case 4:
                printf("\nEnter the index of the employee you want to edit..");
                scanf("%d", &employeeIndex);
                if (employeeIndex > (sizeof(employees) / sizeof(struct Employee)) || employeeIndex < 0) {
                    printf("You don't have any employee's at this index..");
                    printf("Returning to the main menu..");
                    break;
                } else {
                    int editIndex;
                    printf("Employees data:");
                    printEmployeeData(&employees[employeeIndex]);
                    printf("Enter the number next to field you want to edit..\n");
                    printf("1-Name, 2-Hourly rate, 3-Hours worked, 4-Gross payment\n");
                    scanf("%d", &editIndex);
                    switch (editIndex) {
                        printf("Editting...");
                        case 1:
                            printf("Enter the employee name:");
                            scanf("%s", employees[employeeIndex].employeeName);
                            break;
                        case 2:
                            printf("Enter the hourly rate:");
                            scanf("%lf", &employees[employeeIndex].employeeHourlyRate);
                            break;
                        case 3:
                            printf("Enter hours worked:");
                            scanf("%d", &employees[employeeIndex].employeeHoursWorked);
                            break;
                        case 4:
                            printf("Enter gross payment:");
                            scanf("%lf", &employees[employeeIndex].grossPayment);
                            break;
                        default:
                            printf("\nWhoops. Didnt get that one.\n");
                            break;
                    }
                    printf("Edited employee data:");
                    printEmployeeData(&employees[employeeIndex]);
                }
        }
    } while ((loopIndex + 1 != 5));

}



        // Sample Program Execution

/*
        C:\Users\BAHA\CLionProject\CS_36\cmake-build-debug\CS_36.exe
Enter the operation number you want to do.
1.Enter employee data.
2.Display employee data.
3.Display all employee data.
4.Edit an employee data.
0.Quit the application
1
Enter the employee name:baha
Enter the hourly rate:100
Enter hours worked:40
Enter the operation number you want to do.
1.Enter employee data.
2.Display employee data.
3.Display all employee data.
4.Edit an employee data.
0.Quit the application
1
Enter the employee name:nazmi
Enter the hourly rate:50
Enter hours worked:30
Enter the operation number you want to do.
1.Enter employee data.
2.Display employee data.
3.Display all employee data.
4.Edit an employee data.
0.Quit the application
1
Enter the employee name:nazmiye
Enter the hourly rate:40
Enter hours worked:10
Enter the operation number you want to do.
1.Enter employee data.
2.Display employee data.
3.Display all employee data.
4.Edit an employee data.
0.Quit the application
2
Enter the index of the employee..1

Employee name:nazmi
Hours worked:30
Hourly rate:$50.00
Gross paid:$1500.00
Overtime paid:$0.00
Tax paid:$300.00
Enter the operation number you want to do.
1.Enter employee data.
2.Display employee data.
3.Display all employee data.
4.Edit an employee data.
0.Quit the application
3
Printing all employee's summary data
Employee name:baha
Hours worked:40
Hourly rate:$100.00
Gross paid:$4000.00

Employee name:nazmi
Hours worked:30
Hourly rate:$50.00
Gross paid:$1500.00

Employee name:nazmiye
Hours worked:10
Hourly rate:$40.00
Gross paid:$400.00
Enter the operation number you want to do.
1.Enter employee data.
2.Display employee data.
3.Display all employee data.
4.Edit an employee data.
0.Quit the application
4

Enter the index of the employee you want to edit..1
Employees data:
Employee name:nazmi
Hours worked:30
Hourly rate:$50.00
Gross paid:$1500.00
Overtime paid:$0.00
Tax paid:$300.00
Enter the number next to field you want to edit..
1-Name, 2-Hourly rate, 3-Hours worked, 4-Gross payment
1
Enter the employee name:necmi
Edited employee data:

Employee name:necmi
Hours worked:30
Hourly rate:$50.00
Gross paid:$1500.00
Overtime paid:$0.00
Tax paid:$300.00
Enter the operation number you want to do.
1.Enter employee data.
2.Display employee data.
3.Display all employee data.
4.Edit an employee data.
0.Quit the application
0
Quitting the application..
Process finished with exit code 0
 */





































