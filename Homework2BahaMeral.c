#include <stdio.h>
int main() {


    // declaring all parameters as arrays to store each employee's data
    int employee_sHoursWorked[5];
    double employee_sHourlyRate[5];
    double employee_sOverTimePaid[5];
    double employee_sGrossPaid[5];
    double employee_sTaxPaid[5];
    double employee_sAmountAfterTax[5];
    // using 2D arrays to store multiple names
    char employee_sNames[5][20];

    // declaring the variable count for and increasing the amount of times that the user enters valid data
    int count = 0;



    // loop for getting input from user for each employee
    for(unsigned int employee = 0; employee <= 4; employee++){
        // prompting user to enter employee name
        printf("Enter the employee name:");
        scanf_s("%s", employee_sNames[employee],sizeof(employee_sNames[employee]));
        printf("Enter hours worked:");
        scanf_s("%d",&employee_sHoursWorked[employee]);
        printf("Enter the hourly rate:");
        scanf_s("%lf",&employee_sHourlyRate[employee]);

        // checking the variables whether the user entered -1
        if(employee_sNames[employee] == "-1" || employee_sHoursWorked[employee] == -1 || employee_sHourlyRate[employee] == -1){
            // initializing the variables so that we won't get garbage data for the employee's data
            employee_sGrossPaid[employee] = 0;
            employee_sTaxPaid[employee] = 0;
            employee_sAmountAfterTax[employee] = 0;
            employee_sOverTimePaid[employee] = 0;
            break;
        }
        // increasing one when we pass the if for -1
        count++;

        // checking if the employee worked more than 40 hours
        // calculating overtime pay for the employee if it's more than 40 hours
        // if not initializing to overtime to 0
        if(employee_sHoursWorked[employee] > 40){
            employee_sOverTimePaid[employee] = (employee_sHoursWorked[employee] - 40) * 1.5 * employee_sHourlyRate[employee];
        }else{
            employee_sOverTimePaid[employee] = 0;
        }

        // initializing and calculating  gross paid, tax paid and amount after tax
        employee_sGrossPaid[employee] = employee_sHourlyRate[employee] * employee_sHoursWorked[employee] + employee_sOverTimePaid[employee];
        employee_sTaxPaid[employee] = employee_sGrossPaid[employee] * 0.20;
        employee_sAmountAfterTax[employee] = employee_sGrossPaid[employee] - employee_sTaxPaid[employee];

    }

    // for loop for printing out the each employees data
    // using the int count that we declared and initialized to amount of times users enter valid data
    // so that when employees data prints it wont over print and won't show the employee's data that we never assigned.
    for(unsigned int employee = 0; employee < count; employee++){
        printf("\nPay to: %s",employee_sNames[employee]);
        printf("\nHours worked: %d", employee_sHoursWorked[employee]);
        printf("\nHourly rate: $%0.2f",employee_sHourlyRate[employee]);
        printf("\nGross paid: $%0.2lf", employee_sGrossPaid[employee]);
        printf("\nOver paid: $%0.2lf",employee_sOverTimePaid[employee]);
        printf("\nTaxes paid: $%0.2lf",employee_sTaxPaid[employee]);
        printf("\nTake home: $%0.2lf\n",employee_sAmountAfterTax[employee]);
    }

}

            // Sample Input and Output
        /*

            Enter the employee name:baha
            Enter hours worked:100
            Enter the hourly rate:100
            Enter the employee name:nazmi
            Enter hours worked:100
            Enter the hourly rate:40
            Enter the employee name:-1
            Enter hours worked:-1
            Enter the hourly rate:-1


            Pay to: baha
            Hours worked: 100
            Hourly rate: $100.00
            Gross paid: $19000.00
            Over paid: $9000.00
            Taxes paid: $3800.00
            Take home: $15200.00

            Pay to: nazmi
            Hours worked: 100
            Hourly rate: $40.00
            Gross paid: $7600.00
            Over paid: $3600.00
            Taxes paid: $1520.00
            Take home: $6080.00

         */






























//int userInput;
//int evenCount = 0;
//
//printf("Please enter the number you want to start with:");
//scanf_s("%d",&userInput);
//int loopVar = userInput + 9;
//for (loopVar >= userInput; loopVar--;) {
//if(userInput % 2 == 0){
//printf("%d\n",userInput);
//}
//userInput++;
//
//}

//int userInput;
//int evenCount = 0;
//int flag = 0;
//
//printf("Please enter the number you want to start with:");
//scanf_s("%d",&userInput);
//
//while(!flag){
//if(userInput % 2 != 0){
//userInput++;
//}
//printf("%d\n",userInput);
//userInput += 2;
//
//if(evenCount == 10){
//flag = 1;
//}
//evenCount++;
//}