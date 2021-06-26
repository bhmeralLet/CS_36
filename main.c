#include <stdio.h>

int main() {


   // Link for scanf_s() https://stackoverflow.com/questions/23378636/string-input-using-c-scanf-s
   // Link for why you dont address string https://www.geeksforgeeks.org/not-used-strings-scanf-function/

    char name[15];
    double hourlyRate = 0;
    int numberOfHoursWorked = 0;
    double overTimePaid = 0;
    double grossPaid;
    double taxPaid;
    double amountAfterTax;
    int optionalQuit = 0;

    for (unsigned int employee = 1; employee <= 5; ++employee ){

        // Asking user to enter the Employee's name, hourly rate, and number of hours worked
        printf("Enter the name of employee:");
        scanf_s("%s", name, sizeof(name));
        printf("Enter hourly rate of the employee:");
        scanf_s("%lf", &hourlyRate);
        printf("Enter the number of hours worked:");
        scanf_s("%d", &numberOfHoursWorked);

        // Checking if the employee over worked
        if(numberOfHoursWorked > 40){
            // calculating the over time pay (number of over time hours * 1.5 * hourlyRate)
            overTimePaid = (numberOfHoursWorked - 40) * 1.5 * hourlyRate;
        }
        // calculating gross paid, tax paid, amount after tax and initializing
        grossPaid = hourlyRate * numberOfHoursWorked + overTimePaid;
        taxPaid = grossPaid * 0.20;
        amountAfterTax = grossPaid - taxPaid;

        // Outputting the employee's payment info
        printf("\nPay to: %s",name);
        printf("\nHourly rate: $%0.2lf",hourlyRate);
        printf("\nHours worked: %d",numberOfHoursWorked);
        printf("\nGross paid: $%0.2lf", grossPaid);
        printf("\nOver paid: $%0.2lf",overTimePaid);
        printf("\nTaxes paid: $%0.2lf",taxPaid);
        printf("\nTake home: $%0.2lf",amountAfterTax);

        // Added optional way to quit the loop if desired
        printf("\nDo you still want to use the application\nIf yes press 1 If no press 0:");
        scanf_s("%d",&optionalQuit);
        // using optionalQuit as a flag if it is 1 it will continue to run if it is 0 it will end the loop.
        if(optionalQuit == 1){
            continue;
        }else{
            break;
        }
    }
}