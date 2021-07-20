/*
FinalProjectNames
Kevin Wong
7/16/2021
Version 1
*/


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(int argc, char* argv[])
{
    ifstream infile;
    string filename = "C:\\Users\\14088\\Code\\C++ProgrammingClass\\LabReports\\FinalExamProject\\Names.txt";
    char Name1[100] = "";
    char Name2[100] = "";
    char InputName[100] = "";
    int lineCount = 0;
    int boyRank = 0;
    int girlRank = 0;
    
    cout << "Name: ";
    cin.getline(InputName, 100);


    infile.open(filename);
    if (infile.fail())
    {
        cerr << "Unable to open --" << filename  << endl;
        exit(1);
    }

    while (!infile.eof())   // while not end of file
    {
        infile >> Name1 >> Name2;
        lineCount += 1;
        if (stricmp(InputName,Name1)  ==  0){
            boyRank = lineCount;
        }
        if (stricmp(InputName,Name2)  ==  0){
            girlRank = lineCount;
        }
    }
    infile.close();
    if (boyRank == 0){
        cout << InputName << " was not found for boys." << endl;
    }
    
    else{
        cout << InputName << " is ranked " << boyRank << " for boys." << endl;
    }

    if (girlRank == 0){
        cout << InputName << " was not found for girls." << endl;
    }
    
    else{
        cout << InputName << " is ranked " << girlRank << " for girls." << endl;
    }
    
	return 0;
}
