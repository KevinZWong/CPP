/*
MetricToEnglish
Kevin Wong
Version 1
7/2/2021
*/
#include <iostream>
#include <cctype>
#include <iomanip> 
char menuSelect();
using namespace std;
// used for cin and cout
// used for the toupper function
// returns 'E' or 'M'
int main(int argc, char* argv[])
{
    double inches;
    double centimeters;
    char select;
    do {
        select = menuSelect();
        if (select == 'E')
        {
            cout << "Enter the number of inches: ";
            cin >> inches;
            centimeters = inches * 2.54;
            centimeters = centimeters * 10;
            int cm1 = int(centimeters);
            double cm2 = double(cm1) / 10;
            cout << inches << " inches is equal to " << cm2  << " centimeters" << endl;
        }
        else if (select == 'M')
        {
            cout << "Enter the number of centimeters: ";
            cin >> centimeters;
            inches = centimeters / 2.54;
            inches = inches * 10 ;
            int inches1 = int(inches);
            double inches2 = double(inches1) / 10;
            cout << centimeters << " centimeters is equal to " << inches2 << " inches" << endl;
        }

    } while (select != 'Q');
    return 1;
}
char menuSelect()
{
    char selection;
    do {
        cout << endl; // blank line
        cout << "Enter E to convert English to Metric, or M to convert Metric to English or Q to quit: ";
        cin >> selection;
        cin.clear();
        cin.ignore(10000, '\n');
        selection = toupper(selection); // convert to uppercase
        if (selection != 'E' && selection != 'M' && selection != 'Q'){
            cout << "Illegal entry, try again";
        } 
    } while (selection != 'E' && selection != 'M' && selection != 'Q'); // verify legal selection
    return selection;
}