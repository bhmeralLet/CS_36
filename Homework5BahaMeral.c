#include <stdio.h>
#include <stdlib.h>


/**
 * Creating an Employee struct defining employee's data
 */
struct Employee {
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
void loadEmployee(struct Employee* employee) {
    printf("Enter the employee name:");
    scanf("%s", employee->employeeName);
    printf("Enter the hourly rate:");
    scanf("%lf", &employee->employeeHourlyRate);
    printf("Enter hours worked:");
    scanf("%d", &employee->employeeHoursWorked);

}

/**
 * printEmployeeData - It will print the employee's data, accessing the data with employee pointer;
 * @param employee - pointer to struct Employee
 */
void printEmployeeData(struct Employee* employee) {
    printf("\nEmployee name:%s\n", employee->employeeName);
    printf("Hours worked:%d\n", employee->employeeHoursWorked);
    printf("Hourly rate:$%0.2f\n", employee->employeeHourlyRate);
    printf("Gross paid:$%0.2f\n", employee->grossPayment);
    printf("Overtime paid:$%0.2f\n", employee->overTimePayment);
    printf("Tax paid:$%0.2f\n", employee->taxPaid);
}

/**
 * printAllEmployeeData - It will print employee's data in a summary view, accessing employee's data with employee pointer;
 * even though it is named printAllEmployeeData it just prints one employee's data in a summary view.
 * We call the method inside the loop to print all employee data iterating through employees[].
 * @param employee - pointer to struct Employee
 */
void printAllEmployeeData(struct Employee* employee) {
    printf("\nEmployee name:%s\n", employee->employeeName);
    printf("Hours worked:%d\n", employee->employeeHoursWorked);
    printf("Hourly rate:$%0.2f\n", employee->employeeHourlyRate);
    printf("Gross paid:$%0.2f\n", employee->grossPayment);
}

/**
 * loadMenu - It will display the menu of options and ask the user to which operation user wants.
 * @return choice - returning an integer for user's choice which operation user wants to do.
 */
int loadMenu() {
    int choice;
    puts("Enter the operation number you want to do.");
    puts("1.Enter employee data.");
    puts("2.Display employee data.");
    puts("3.Display all employee data.");
    puts("4.Edit an employee data.");
    puts("0.Quit the application");
    scanf_s("%d", &choice);
    if (choice < 0 || choice > 4) {
        puts("Cannot respond to given choice..");
        puts("Quitting the application...");
        exit(0);
    }
    return choice;
}

/**
 * inputMode - Asking the user which way they want to add employee data.
 * @return mode - user input for upload mode
 */
char inputMode() {
    char mode;
    puts("Please enter which way you want to upload employee data.");
    puts("Uploading with file enter f \t Uploading with keyboard enter k");
    scanf(" %c", &mode);

    return mode;
}


/**
 *
 * @param employees - array of Employee
 * @param arraySize - using on the loops to index accordingly
 * @return count - returning the count integer (amount of employees) on the file or user entered to index accordingly
 */

int employeeEntry(struct Employee employees[], int arraySize) {
    FILE* employeeFile;
    char fileName[20];

    switch (inputMode()) {
        case 'f':
        case 'F':
            printf("Enter the name of the file including .txt:");
            scanf("%s", fileName);

            if ((employeeFile = fopen(fileName, "r+")) == NULL) {
                puts("Entered file cannot open..");
                break;
            }

            /**
             * checking whether the file is empty or not
             */
            if (employeeFile != NULL) {
                fseek(employeeFile, 0, SEEK_END);
                int fileSize = ftell(employeeFile);
                if (fileSize == 0) {
                    puts("File is empty cannot load the employees..");
                    break;
                }
                fseek(employeeFile, 0, SEEK_SET);
            }

            int numberOfLines = 1;
            char c;
            /**
             * checking number of lines to calculate the amount of employees
             */
            while ((c = fgetc(employeeFile)) != EOF) {
                if (c == '\n')
                    numberOfLines++;
            }
            fseek(employeeFile, 0, SEEK_SET);

            fscanf(employeeFile, "%s", employees[0].employeeName);

            fseek(employeeFile, 0, SEEK_SET);

            /**
             * checking whether the file is formatted the way we want
             */

            if (employees[0].employeeName[0] < 65 || employees[0].employeeName[0] > 122) {
                puts("File is not ordered..");
                puts("Format the file as name new line hours worked new line hourly rate..");
                puts("Exiting the application");
                fclose(employeeFile);
                exit(0);
            }

            /**
             * calculating the amount of employees
             * and checking if there is more data than the size of array so we don't overload.
             */
            int amountOfEmployee = numberOfLines / 3;
            if ((amountOfEmployee) > arraySize) {
                printf("Cannot load employee data more than %d..", arraySize);
                puts("Adjust your file");
                break;
            }

            /**
             * loading the employee data from file to employees array
             */
            for (int employee = 0; employee < amountOfEmployee; employee++) {
                fscanf(employeeFile, "%s\n%d\n%lf", employees[employee].employeeName,
                       &employees[employee].employeeHoursWorked, &employees[employee].employeeHourlyRate);
            }
            fclose(employeeFile);
            return amountOfEmployee;


        case 'k':
        case 'K':
            int quit = 0;
            int count = 0;
            /**
             * loading the employee data from keyboard to employees array
             */
            for (int employee = 0; employee < arraySize; employee++) {
                loadEmployee(&employees[employee]);
                count++;
                puts("Press 0 to continue loading data to the system...");
                scanf("%d", &quit);
                if (quit != 0) {
                    break;
                }
            }
            return count;
        default:
            puts("Task failed successfully");
            break;
    }
}

/**
 * payment() - It will calculate the gross paid, overtime paid and tax paid for the employee
 * @param employee - pointer to struct Employee
 */
void payment(struct Employee* employee) {

    if ((employee->employeeHoursWorked) > 40) {
        employee->overTimePayment = ((employee->employeeHoursWorked) - 40) * 1.5 * (employee->employeeHourlyRate);
    } else {
        employee->overTimePayment = 0;
    }
    employee->grossPayment =
            (employee->employeeHoursWorked) * (employee->employeeHourlyRate) + employee->overTimePayment;
    employee->taxPaid = (employee->grossPayment) * .2;
}


int main() {
    FILE* dataFile;
    char fileName[20];
    struct Employee employees[10];
    int employeeIndex;
    int loopIndex = 0;
    int choice;

    /**
     * Using do while loop to show menu options after an operation
     * Showing the user menu of options and asking which one user wants to do
     * then returning the chosen operation as an integer and using in the switch
     * Based on the chosen operation
     */
    do {
        choice = loadMenu();
        switch (choice) {
            case 0:
                /**
                 * asking the user to enter the file name to save the data
                 * taking the data from the employees array
                 */
                puts("Before exiting the application enter the file you want to save the data's");
                scanf("%s", fileName);
                dataFile = fopen(fileName, "w");
                for (int employee = 0; employee < (sizeof(employees) / sizeof(struct Employee)); employee++) {
                    fprintf(dataFile, "%s\n%d\n%lf\n", employees[employee].employeeName,
                            employees[employee].employeeHoursWorked, employees[employee].employeeHourlyRate);
                }
                fclose(dataFile);
                puts("Quitting the application..");
                exit(0);
            case 1:
                /**
                 * assigning loopIndex to use for the for_loops to index better so that we don't spit garbage.
                 */
                loopIndex = employeeEntry(employees, 10);
                break;
            case 2:
                puts("Enter the index of the employee..");
                scanf("%d", &employeeIndex);
                if (employeeIndex >= (sizeof(employees) / sizeof(struct Employee)) || employeeIndex < 0) {
                    puts("You don't have any employee's at this index..");
                    puts("Returning to the main menu..");
                    break;
                } else {
                    printEmployeeData(&employees[employeeIndex]);
                }
                break;
            case 3:
                puts("Printing all employee's summary data");
                for (int employee = 0; employee < loopIndex; employee++) {
                    if (loopIndex == 0) {
                        puts("There is no employee data on the system yet.");
                        puts(" Returning to the main menu.");
                        break;
                    } else {
                        payment(&employees[employee]);
                        printAllEmployeeData(&employees[employee]);
                    }
                }
                break;
            case 4:
                puts("Enter the index of the employee you want to edit..");
                scanf("%d", &employeeIndex);
                if (employeeIndex > (sizeof(employees) / sizeof(struct Employee)) || employeeIndex < 0) {
                    puts("You don't have any employee's at this index..");
                    puts("Returning to the main menu..");
                    break;
                } else {
                    int editIndex;
                    puts("Employees data:");
                    payment(&employees[employeeIndex]);
                    printEmployeeData(&employees[employeeIndex]);
                    puts("Enter the number next to field you want to edit..");
                    puts("1-Name, 2-Hourly rate, 3-Hours worked, 4-Gross payment");
                    scanf("%d", &editIndex);
                    switch (editIndex) {
                        case 1:
                            puts("Enter the employee name:");
                            scanf("%s", employees[employeeIndex].employeeName);
                            break;
                        case 2:
                            puts("Enter the hourly rate:");
                            scanf("%lf", &employees[employeeIndex].employeeHourlyRate);
                            break;
                        case 3:
                            puts("Enter hours worked:");
                            scanf("%d", &employees[employeeIndex].employeeHoursWorked);
                            break;
                        case 4:
                            puts("Enter gross payment:");
                            scanf("%lf", &employees[employeeIndex].grossPayment);
                            break;
                        default:
                            printf("\nWhoops. Didnt get that one.\n");
                            break;
                    }
                    if (editIndex == 2 || editIndex == 3) {
                        payment(&employees[employeeIndex]);
                    }
                    puts("Edited employee data:");
                    printEmployeeData(&employees[employeeIndex]);
                }
        }
    } while (1);

}

/*

Enter the operation number you want to do.
1.Enter employee data.
2.Display employee data.
3.Display all employee data.
4.Edit an employee data.
0.Quit the application
1
Please enter which way you want to upload employee data.
Uploading with file enter f      Uploading with keyboard enter k
f
Enter the name of the file including .txt:employees.txt
Enter the operation number you want to do.
1.Enter employee data.
2.Display employee data.
3.Display all employee data.
4.Edit an employee data.
0.Quit the application
3
Printing all employee's summary data

Employee name:baha
Hours worked:100
Hourly rate:$45.00
Gross paid:$8550.00

Employee name:cemo
Hours worked:100
Hourly rate:$200.00
Gross paid:$38000.00

Employee name:cemoli
Hours worked:7
Hourly rate:$87.00
Gross paid:$609.00

Employee name:nacmiye
Hours worked:100
Hourly rate:$90.00
Gross paid:$17100.00

Employee name:nacmi
Hours worked:100
Hourly rate:$50.00
Gross paid:$9500.00

Employee name:keltos
Hours worked:30
Hourly rate:$55.00
Gross paid:$1650.00

Employee name:necmi
Hours worked:50
Hourly rate:$50.00
Gross paid:$3250.00

Employee name:nacmi
Hours worked:100
Hourly rate:$30.00
Gross paid:$5700.00

Employee name:nazmiye
Hours worked:10
Hourly rate:$30.00
Gross paid:$300.00

Employee name:nazmi
Hours worked:100
Hourly rate:$100000.00
Gross paid:$19000000.00
Enter the operation number you want to do.
1.Enter employee data.
2.Display employee data.
3.Display all employee data.
4.Edit an employee data.
0.Quit the application
2
Enter the index of the employee..
0

Employee name:baha
Hours worked:100
Hourly rate:$45.00
Gross paid:$8550.00
Overtime paid:$4050.00
Tax paid:$1710.00
Enter the operation number you want to do.
1.Enter employee data.
2.Display employee data.
3.Display all employee data.
4.Edit an employee data.
0.Quit the application
4
Enter the index of the employee you want to edit..
0
Employees data:

Employee name:baha
Hours worked:100
Hourly rate:$45.00
Gross paid:$8550.00
Overtime paid:$4050.00
Tax paid:$1710.00
Enter the number next to field you want to edit..
1-Name, 2-Hourly rate, 3-Hours worked, 4-Gross payment
1
Enter the employee name:
nedirsin
Edited employee data:

Employee name:nedirsin
Hours worked:100
Hourly rate:$45.00
Gross paid:$8550.00
Overtime paid:$4050.00
Tax paid:$1710.00
Enter the operation number you want to do.
1.Enter employee data.
2.Display employee data.
3.Display all employee data.
4.Edit an employee data.
0.Quit the application
0
Before exiting the application enter the file you want to save the data's
employees.txt
Quitting the application..

Process finished with exit code 0
 */

/*

 After qutting the application

nedirsin
100
45.000000
cemo
100
200.000000
cemoli
7
87.000000
nacmiye
100
90.000000
nacmi
100
50.000000
keltos
30
55.000000
necmi
50
50.000000
nacmi
100
30.000000
nazmiye
10
30.000000
nazmi
100
100000.000000


 before the application
baha
100
45
cemo
100
200
cemoli
7
87
nacmiye
100
90
nacmi
100
50
keltos
30
55
necmi
50
50
nacmi
100
30
nazmiye
10
30
nazmi
100
100000
 */


