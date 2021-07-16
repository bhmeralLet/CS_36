#include <stdio.h>

/**
 * This method will ask user to input the employees info
 * Using the pointers on the parameters to use pass by reference. Getting the memory location of parameters
 * and pointing to the value on memory location then initializing the inputted values to the value that we got from the memory location.
 * @param hoursWorked - total number of hours worked
 * @param hourlyRate - amount of payment employee gets by hour
 * @param employeeName - name of the employee
 */
void userInput(int* hoursWorked,double* hourlyRate,char employeeName [][20]){

    int hours;
    double rate;

    printf("Enter name of the employee:");
    scanf_s("%s",employeeName[0], sizeof(employeeName[0]));
    printf("Enter hours worked:");
    scanf_s("%d",&hours);
    printf("Enter hourly rate:");
    scanf_s("%lf",&rate);

    *hoursWorked = hours;
    *hourlyRate = rate;
}

/**
 * Creating a structure hold several data and wrapping grossPayment and overTimePayment
 *
 */
struct Payment{
    double grossPayment, overTimePayment;
};


/**
 * Using the Payment structure we declare to return multiple values at the same time
 * This method will calculate the employees gross payment (amount of money before tax)
 * and over time payment.
 * @param hoursWorked - amount of hours employee worked
 * @param hourlyRate - amount of money employee gets by hour
 * @return payment - calculated gross payment and over time payment
 */

struct Payment calculateGrossPaid(int hoursWorked, double hourlyRate){

    double grossPayment;
    double overTimePayment;

    if(hoursWorked > 40){
        overTimePayment = ((hoursWorked) - 40) * 1.5 * (hourlyRate);
    }else{
        overTimePayment = 0;
    }

    grossPayment = ((hoursWorked) * (hourlyRate)) + overTimePayment;

    struct Payment payment = {grossPayment,overTimePayment};
    return payment;
}

/**
 * This method will calculate the amount of tax money
 * @param grossPayment - employees gross payment
 * @return amount of tax money
 */
double calculateTax(double grossPayment){

    return grossPayment * 0.20;
}


/**
 *  This method will output the employee info.
 * @param employeeName - name of the employee
 * @param hoursWorked - total number of hours employee worked
 * @param employeeHourlyRate - amount of payment employee gets by hour
 * @param payment - payment for the employee
 */

void outputEmployeeInfo(char employeeName[][20], int hoursWorked[], double employeeHourlyRate[], struct Payment payment){
    payment = calculateGrossPaid(hoursWorked[0], employeeHourlyRate[0]);

    printf("Pay to: %s\n", employeeName[0]);
    printf("Hours worked: %d\n", hoursWorked[0]);
    printf("Hourly rate: $%.02f\n", employeeHourlyRate[0]);
    printf("Gross Pay: $%0.2f\n", payment.grossPayment);
    printf("Base Pay: $%0.2f\n", (payment.grossPayment - payment.overTimePayment));
    printf("Overtime Pay: $%0.2f\n",payment.overTimePayment);
    printf("Taxes Paid: $%0.2f\n", calculateTax(payment.grossPayment));
    printf("Base Payment: $%0.2f\n", payment.grossPayment  - calculateTax(payment.grossPayment));

}


int main() {

    char employee_sNames[5][20];
    int employee_sHoursWorked[5];
    double employee_sHourlyRate[5];
    double totalPayToEmployees = 0;


    for(int employee = 0; employee < 2; employee++){
        // asking user to input the employees info and then pointing to the declared arrays
        userInput(&employee_sHoursWorked[employee],&employee_sHourlyRate[employee], &employee_sNames[employee]);
    }


    for(int employee = 0; employee < 2; employee++){
        // declaring and initializing the payment to use in the outputEmployeeInfo
        struct Payment payment = calculateGrossPaid(employee_sHoursWorked[employee],employee_sHourlyRate[employee]);
        // outputting employee infos (name, hours worked, hourly rate, payment, overpay, tax, net pay)
        outputEmployeeInfo(&employee_sNames[employee],&employee_sHoursWorked[employee],&employee_sHourlyRate[employee],payment);
        // adding the gross payment of each employee for calculating total pay to all employees
        totalPayToEmployees += payment.grossPayment;
    }
    // printing out the total payment to all employees
    printf("Total Paid To Employees: $%0.2f", totalPayToEmployees);

}
            // Sample Output
            /*
                Enter name of the employee:baha
                Enter hours worked:30
                Enter hourly rate:100
                Enter name of the employee:nazmi
                Enter hours worked:14
                Enter hourly rate:50
                Pay to: baha
                Hours worked: 30
                Hourly rate: $100.00
                Gross Pay: $3000.00
                Base Pay: $3000.00
                Overtime Pay: $0.00
                Taxes Paid: $600.00
                Base Payment: $2400.00
                Pay to: nazmi
                Hours worked: 14
                Hourly rate: $50.00
                Gross Pay: $700.00
                Base Pay: $700.00
                Overtime Pay: $0.00
                Taxes Paid: $140.00
                Base Payment: $560.00
                Total Paid To Employees: $3700.00
                Process finished with exit code 0
             */

