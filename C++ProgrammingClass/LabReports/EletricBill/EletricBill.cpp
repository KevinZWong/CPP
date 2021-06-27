/* 
C++ EletricBill
6/21/2021
Version 1
Kevin Wong
*/

#include <iostream> 
#include <iomanip> 
using namespace std;


int main(int argc, char* argv[])
{   
    //Defining varibles
    double Tier1_kWh = 0.23;
    double Tier2_kWh = 0.29;
    double Tier3_kWh = 0.45;
    double kWt;
    double Eletric_Bill;
    try {
        cout << "\n\nEnter the number of kWts: ";
        cin >> kWt;
        if (cin.fail()){
            throw 0; 
        }
        if (kWt < 0){
            throw 1;
        }

    
        if(kWt <= 350){
            Eletric_Bill = kWt * Tier1_kWh;
        }
        else if(kWt <= 1400){
            Eletric_Bill = 80.5 + (kWt - 350) * Tier2_kWh;
        }
        else{
            Eletric_Bill = 385 + (kWt - 1400) * Tier3_kWh;

        }

        cout << "Your Eletric Bill is: "  << Eletric_Bill;
        }
        catch (int ErrID) {
            cerr << "Error Code " << ErrID << endl;
            if (ErrID == 0){
                cout << "Invaild input, string instead of int";
            }
            if (ErrID == 1){
                cout << "Invaild input, negative Number";
            }
        }
    return 0;
}
