/*
C++ Falafel
Kevin Wong
Version 1
7/5/2021
*/

#include <iostream>
#include <cctype>
void DisplayMenu();        // display the menu
using namespace std;

int main(int argc, char* argv[])
{
    double subtotal = 0.00;
    double price;
    char selection;
    int Fcounter = 0;
    int Scounter = 0;
    int Xcounter = 0;

    double PriceFcounter = 0;
    double PriceScounter = 0;
    double PriceXcounter = 0;
    DisplayMenu();
    do
    {
        price = 0;
        cout << "Make your selection (FSXT): ";

        cin  >> selection;
        

        switch ( toupper(selection) )
        {
        case 'F':{
            price = 5.15;
            PriceFcounter += price;
            Fcounter += 1;
            break;
            }

        case 'S':{
            price = 2.24;
            PriceScounter += price;
            Scounter += 1;
            break;
        }

        case 'X':{
            price = 1.57;
            PriceXcounter += price;
            Xcounter += 1;
            break;
        }

        case 'T':
            break;
        default:
            cout << "Illegal selection, try again." << endl;
        }
        subtotal += price;
    } while (selection != 'T' && selection != 't');


    cout << Fcounter << " Falafel" << endl;
    cout << Scounter << " Soda" << endl;
    cout << Xcounter << " Extras" << endl << endl;
    cout << PriceFcounter << " Falafel" << endl;
    cout << PriceScounter << " Soda" << endl;
    cout << PriceXcounter << " Extras" << endl << endl;
    cout << "Subtotal $" << subtotal << endl;
    // tax calculation
    double tax = subtotal * 0.087 ;
    tax = tax * 100 ;
    int tax1 = int(tax);
    double tax2 = double(tax1) / 100;
    //
    cout << "Tax $" << tax2 << endl;
    cout<< "Total $" << subtotal + tax2;
    return 0;
}

void DisplayMenu()
{
    cout << endl;   // blank line before start of menu
    cout << "F = falafel  $5.15" << endl;
    cout << "S = soda     $2.24" << endl;
    cout << "X = extras   $1.57" << endl;
    cout << "T = total" << endl;
}

