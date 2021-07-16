#include <stdio.h>

void userInput(int* hoursWorked,double* hourlyRate,char employeeName [5][20]){

    // using for 2D array employeeName
    int index = 0;

    int hours;
    double rate;
    char name[20];

    printf("Enter name of the employee:");
    scanf_s("%s",employeeName[index], sizeof(employeeName[index])) ;
    index++;
    printf("Enter hours worked:");
    scanf_s("%d",&hours);
    printf("Enter hourly rate:");
    scanf_s("%lf",&rate);

    *hoursWorked = hours;
    *hourlyRate = rate;
}

struct Payment{
    double grossPayment, overTimePayment;
};

struct Payment calculateGroosPaid(int* hoursWorked,double* hourlyRate){

    double grossPayment;
    double overTimePayment;

    if(*hoursWorked > 40){
        overTimePayment = ((*hoursWorked) - 40) * 1.5 * (*hourlyRate);
    }else{
        overTimePayment = 0;
    }

    grossPayment = ((*hoursWorked) * (*hourlyRate)) + overTimePayment;

    struct Payment payment = {grossPayment,overTimePayment};
    return payment;
}

double calculateTax(double grossPayment){

    return grossPayment * 0.20;
}



void outputEmployeeInfo(char employeeName[][20], int hoursWorked[], double employeeHourlyRate[], struct Payment payment){
    int index = 0;
    payment = calculateGroosPaid(&hoursWorked[index],&employeeHourlyRate[index]);

    printf("Pay to: %s\n", employeeName[index]);
    printf("Hours worked: %d\n", hoursWorked[index]);
    printf("Hourly rate: $%.02f\n", employeeHourlyRate[index]);
    index++;
    printf("Gross Pay: $%0.2f\n", payment.grossPayment);
    printf("Base Pay: $%0.2f\n", (payment.grossPayment - calculateTax(payment.grossPayment)));
    printf("Overtime Pay: $%0.2f\n",payment.overTimePayment);
    printf("Taxes Paid: $%0.2f\n", calculateTax(payment.overTimePayment));

}




int main() {

    char employee_sNames[5][20];
    int employee_sHoursWorked[5];
    double employee_sHourlyRate[5];
    double employee_sGrossPaid[5];
    double employee_sOverTimePaid[5];
    double employee_sTaxPaid[5];
    double employee_sAmountAfterTax[5];



    for(int employee = 0; employee < 1; employee++){
        userInput(&employee_sHoursWorked[employee],&employee_sHourlyRate[employee], &employee_sNames[employee]);
    }

    for(int employee = 0; employee < 1; employee++){
        struct Payment payment = calculateGroosPaid(&employee_sHoursWorked[employee],&employee_sHourlyRate[employee]);
        outputEmployeeInfo(&employee_sNames[employee],&employee_sHoursWorked[employee],&employee_sHourlyRate[employee],payment);
    }




}