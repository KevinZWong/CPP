/* 
CreditCard
6/23/2021
Kevin Wong
*/


#include <iostream>
#include <iomanip>
using namespace std;

const double YEARLY_INTEREST_RATE = 22.24 / 100.0;    // 22.24% = 0.2224
const double MONTHLY_INTEREST_RATE = YEARLY_INTEREST_RATE / 12;
const double CREDIT_LIMIT = 500.00;     // credit limit
const int    MAX_MONTHS = 12;           // maximum months to display


int main()
{
    // Input values
    double balance = 240.75;
    double payment = 35.00;
    double charges = 60.00;

    // Computed values
    double interest;
    double newBalance;
    int month = 1;

    // table column headings
    cout << fixed << showpoint;
    cout << setw(7) << "Month" << setw(9) << "Balance" << setw(10) << "Interest" << setw(9) << "Payment" 
        << setw(9) << "Charges" << setw(12) << "New Balance" << endl;

    int counter1 = 0; 

    do {
        counter1 += 1; 
        if (counter1 > 12){
            return 1;
        }
        interest = balance * MONTHLY_INTEREST_RATE;    
        newBalance = balance + interest + charges - payment;
        if (newBalance < 0){
            newBalance = 0;
        }
        if(balance > CREDIT_LIMIT){
            cout << "Balance is greater than credit limit";
            return 1;
        }
        // display table values
        cout << setprecision(2);
        cout << setw(7) << month << setw(9) << balance << setw(10) << interest << setw(9) << payment 
            << setw(9) << charges << setw(12) << newBalance << endl;

        month++;                // update month number
        balance = newBalance;   // transfer newBalance to balance for next computation
    } while (balance > 0.00);
}


