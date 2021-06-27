/* 
C++ Paycheck
6/16/2021
Kevin Wong
*/
#include <iostream>
#include <iomanip> // used to set up 2 digits past the decimal
using namespace std;

int main(int argc, char *argv[])
{
    // define constants
    const double OVERTIME_RATE = 1.5;      // time and a half for overtime
 
    // Declare the variables
    double hours, payRate;                 // values input from the keyboard
    double regHours, overtimeHours;        // rest of values computed
    double regPay, overtimePay;
    double totalPay;

    // INPUT: hours and payRate//
    cout << "Enter the hours worked: ";    // Prompt message imput payrate
    cin >> hours;                          // Input hours
    cout << "Enter the pay rate: ";        
    cin >> payRate;                        // input payrate

    // PROCESS: compute the paycheck
    //    separate the regular and overtime hours
    if (hours <= 40.0)                     // less or equal to 40. No overtime
    {
    regHours = hours;                      // separate regHours and overtimeHours
    overtimeHours = 0.0;
    }
    else                                   // hours are over 40. Compute how many are overtime?
    {
    regHours = 40.0;                       // regular pay for the first 40 hours
    overtimeHours = hours - 40.0;          // anything over 40 hours
    }
    // compute regular, overtime and total pay
    regPay = regHours * payRate;
    overtimePay = overtimeHours * payRate * OVERTIME_RATE;
    totalPay = regPay + overtimePay;
    // OUTPUT: display the paycheck values with two digits past the decimal
    cout << endl;                          // blank line before the output
    cout << setiosflags(ios::fixed | ios::showpoint); // C++ setup for display past decimal
    cout << setprecision (2);               // 2 digits past the decimal point
    cout << "Pay for regular hours   " << setw(7) << regPay << endl;
    cout << "Pay for overtime        " << setw(7) << overtimePay << endl;
    cout << "Total pay               " << setw(7) << totalPay << endl << endl;
    return 0;
} // end of main()
