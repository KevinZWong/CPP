/* 
C++ PlayersOnTeam
6/18/2021
Kevin Wong
*/
#include <iostream> // used for cin and cout
#include <iomanip> // used to set 2 digits past the decimal
using namespace std;
// define the constants
const double OVERTIME_RATE = 1.5;
const double TAX_RATE = 0.17;
// time and a half for overtime
// 0.17 is 17%
int main(int argc, char* argv[])
{
    // Declare the variables
    double hours, payRate;
    double regHours, overtimeHours;
    double regPay, overtimePay;
    double grossPay, taxes, netPay;
    // prompt
    // INPUT: hours and payRate
    cout << "Enter the hours worked: ";
    cin >> hours;
    cout << "Enter the pay rate: ";
    cin >> payRate;
    // PROCESS: compute the paycheck
    // separate the regular and overtime hours
    // compute regular, overtime and total paycheck
    if (hours <= 40.0) // less or equal to 40. No overtime
    {
        regHours = hours; // separate regHours and overtime Hours
        overtimeHours = 0.0;
    }
    else // over 40. How much is overtime?
    {
    regHours = 40.0; // regular pay for the first 40 hours
    overtimeHours = hours - 40.0; // anything over 40 hours
    }
    regPay = regHours * payRate;
    overtimePay = overtimeHours * payRate * OVERTIME_RATE;
    grossPay = regPay + overtimePay;
    taxes = grossPay * TAX_RATE;
    netPay = grossPay - taxes;
    
    // OUTPUT: display the paycheck values with two digits past the decimal
    cout << endl; // blank line before the output
    cout << setiosflags (ios::fixed | ios::showpoint);
    cout << "Your gross pay is $" << setprecision(2) << grossPay << endl;
    cout << "Your taxes are $" << setprecision(2) << taxes << endl;
    cout << "Your net pay is $" << setprecision(2) << netPay << endl << endl;
    return 0;
}
