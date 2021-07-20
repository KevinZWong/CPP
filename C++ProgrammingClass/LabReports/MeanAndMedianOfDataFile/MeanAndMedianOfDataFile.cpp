/*
MeanMedian
Kevin Wong
7/16/2021
Version 1
*/


#include <iostream>
#include <fstream>
#include <cstdlib>  // used by the exit() functiona
#include <iomanip>
using namespace std;

int main(int argc, char* argv[])
{
    // variables to control the disk file
    ifstream infile;
    char filename[200];
    int  recordCount = 0;
    int  recordsToSkip = 0;
    // variables for fields of each record in the file
    int    AcctNo = 0;
    char   Name[100] = "";
    double AcctBal = 0.0;
    // varible used to determine the median
    double median = 0.0;
    
    cout << "Enter the name of the data file: ";
    cin.getline(filename, 200);
    cout << setiosflags(ios::fixed | ios::showpoint);

    //C:\\Users\\14088\\Code\\C++ProgrammingClass\\LabReports\\MeanAndMedianOfDataFile\\Balance1.txt
    //Balance1.txt
    
    // ---- PART 1, Count the number of records in the file
    //      Determine the mean when you know the record count and the total of all balances
    infile.open(filename);
    if (infile.fail())
    {
        cerr << "Unable to open --" << filename << "--, first pass" << endl;
        exit(1);
    }

    double SumOfNums;
    while (!infile.eof())   // while not end of file
    {
        
        Name[0] = 0;        // initialize to 0 to test for empty records/
        infile >> AcctNo >> Name >> AcctBal;
        if (Name[0] != 0){   // ignore empty records
            recordCount++;
            SumOfNums += AcctBal;
        }
    }
    infile.close();
    double mean = SumOfNums/recordCount;



    // ---- PART 2, Determine the number of records to skip


    string OddEven; 
    if (recordCount %2 == 1){
        recordsToSkip = recordCount/2;      // Odd number of records
        OddEven = "ODD";
    }
    else{
        recordsToSkip = recordCount/2 - 1;  // Even number of records
        OddEven = "EVEN";
}
    // ---- PART 3, open the file, skip leading records, determine the median
 

    infile.open(filename);
    if (infile.fail())
    {
        cerr << "Unable to open --" << filename << "--, second pass" << endl;
        exit(1);
    }
    double Value1;
    double Value2;

    for (int i = 0; i <= recordsToSkip + 1; i++) 
    {
        infile >> AcctNo >> Name >> AcctBal;
        if (i == recordsToSkip + 1){
            Value1 = AcctBal;
        }

        if (i == recordsToSkip){
            Value2 = AcctBal;
        }
        
    }

    if (OddEven == "EVEN"){
        median = (Value1 + Value2)/2;
    }
    else
        median = Value2;

    infile.close(); 

	// - - - - - You need to complete the program

    // Display the results
    cout << "The mean of " << setprecision(3) << filename << " is " << mean << endl;
    cout << "The median of " << setprecision(3) << filename << " is " << median << endl << endl;
    
	return 0;
}
