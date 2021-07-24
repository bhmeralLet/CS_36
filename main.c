#include <stdio.h>
#include <stdlib.h>

struct Employee{
    char employeeName[20];
    int employeeHoursWorked;
    double employeeHourlyRate;
    double grossPayment;
    double overTimePayment;
    double taxPaid;
};

void loadEmployee(struct Employee *employee){
    printf("Enter the employee name:");
    scanf("%s", employee->employeeName);
    printf("Enter the hourly rate:");
    scanf("%lf", &employee->employeeHourlyRate);
    printf("Enter hours worked:");
    scanf("%d",&employee->employeeHoursWorked);

}
void printEmployeeData(struct Employee *employee){
    printf("\nEmployee name:%s\n",employee->employeeName);
    printf("Hours worked:%d\n",employee->employeeHoursWorked);
    printf("Hourly rate:$%0.2f\n",employee->employeeHourlyRate);
    printf("Gross paid:$%0.2f\n",employee->grossPayment);
    printf("Overtime paid:$%0.2f\n",employee->overTimePayment);
    printf("Tax paid:$%0.2f\n",employee->taxPaid);
}

void printAllEmployeeData(struct Employee *employee){
    printf("\nEmployee name:%s\n",employee->employeeName);
    printf("Hours worked:%d\n",employee->employeeHoursWorked);
    printf("Hourly rate:$%0.2f\n",employee->employeeHourlyRate);
    printf("Gross paid:$%0.2f\n",employee->grossPayment);
}


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


int main(){

    struct Employee employees[5];
    int employeeIndex;
    int flag = 0;
    int loopIndex = 0;
    int choice;
    do{
        choice = loadMenu();
        switch (choice) {
            case 0:
                printf("Quitting the application..");
                flag = 1;
                break;
            case 1:
                loadEmployee(&employees[loopIndex]);
                payment(&employees[loopIndex]);
                loopIndex++;
                break;
            case 2:
                printf("Enter the index of the employee..");
                scanf("%d",&employeeIndex);
                if(employeeIndex > (sizeof (employees) / sizeof(struct Employee)) || employeeIndex < 0){
                    printf("You don't have any employee's at this index..");
                    printf("Returning to the main menu..");
                    break;
                }else{
                    printEmployeeData(&employees[employeeIndex]);
                }
                break;
            case 3:
                printf("Printing all employee's summary data");
                for (int employee = 0; employee < loopIndex; ++employee) {
                    if(loopIndex == 0){
                        printf("There is no employee data on the system yet.");
                        printf(" Returning to the main menu.\n");
                        break;
                    }else{
                        printAllEmployeeData(&employees[employee]);
                    }
                }
                break;
            case 4:
                printf("\nEnter the index of the employee you want to edit..");
                scanf("%d",&employeeIndex);
                if(employeeIndex > (sizeof (employees) / sizeof(struct Employee)) || employeeIndex < 0){
                    printf("You don't have any employee's at this index..");
                    printf("Returning to the main menu..");
                    break;
                }else{
                    int editIndex;
                    printf("Employees data:\n");
                    printEmployeeData(&employees[employeeIndex]);
                    printf("Enter the number next to field you want to edit..\n");
                    printf("1-Name, 2-Hours worked, 3-Hourly rate, 4-Gross payment\n");
                    scanf("%d",&editIndex);
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
                            scanf("%d",&employees[employeeIndex].employeeHoursWorked);
                            break;
                        case 4:
                            printf("Enter gross payment:");
                            scanf("%lf",&employees[employeeIndex].grossPayment);
                            break;
                        default:
                            printf("\nWhoops. Didnt get that one.\n");
                            break;
                    }
                    printf("Edited employee data:\n");
                    printEmployeeData(&employees[employeeIndex]);
                }
        }
    }while(flag != 1 || (loopIndex + 1 != 5));











































//void getData(char name[][20],float rate[],float hours[]){
//    int index =  0;
//    printf("Name:");
//    scanf_s("%s",name[index],20);
//    printf("Rate:");
//    scanf("%f",&rate[index]);
//    printf("Hours");
//    scanf("%f",&hours[index]);
//    index++;
//}
//
//
//
//char names[5][20];
//float rate[5];
//float hours[5];
//for (int i = 0; i < 4; i++) {
//getData(&names[i],&rate[i],&hours[i]);
//printf("\nname: %s\n",names[i]);
//printf("rate: %0.2f\n",rate[i]);
//printf("hours: %0.2f\n",hours[i]);
//
//}
