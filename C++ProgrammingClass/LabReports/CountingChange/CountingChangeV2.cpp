/* 
C++ CountingChange
6/18/2021
Kevin Wong
*/

#include <iostream> 
#include <iomanip> 
using namespace std;
const double QUARTER = 0.25;
const double DIME = 0.10;
const double NICKLE = 0.05;
const double PENNY = 0.01;


int main(int argc, char* argv[])
{   
    //Defining varibles
    double Nquarters;
    double Ndimes;
    double Nnickels;
    double Npennies;

    cout << "Kevin's Coin counting Program: ";

    cout << "\n\nHow many quarters do you have: ";
    cin >> Nquarters;
            if (cin.fail() ) 
        {
            cout << "Illegal entry for quarters" << endl;
            return 1; 
        }
            if (Nquarters < 0) 
        {
            cout << "Negative values are not allowed" << endl;
            return 1; 
        }
    cout << "How many dimes do you have: ";
    cin >> Ndimes;
            if (cin.fail() ) 
        {
            cout << "Illegal entry for dimes" << endl;
            return 1; 
        }
            if (Ndimes < 0) 
        {
            cout << "Negative values are not allowed" << endl;
            return 1; 
        }
    cout << "How many nickels do you have: ";
    cin >> Nnickels;
            if (cin.fail() ) 
        {
            cout << "Illegal entry for nickels" << endl;
            return 1; 
        }
            if (Nnickels < 0) 
        {
            cout << "Negative values are not allowed" << endl;
            return 1; 
        }
    cout << "How many pennies do you have: ";
    cin >> Npennies;
            if (cin.fail() ) 
        {
            cout << "Illegal entry for pennies" << endl;
            return 1; 
        }
            if (Npennies < 0) 
        {
            cout << "Negative values are not allowed" << endl;
            return 1; 
        }


    double QuarterValue = QUARTER * Nquarters;
    double DimeValue = DIME * Ndimes;
    double NickleValue = NICKLE * Nnickels;
    double PennyValue = PENNY * Npennies;
    double Total = QuarterValue + DimeValue + NickleValue + PennyValue;
    cout << "\nThe total is: $" << setprecision(2) << Total ;
    return 0;
}
