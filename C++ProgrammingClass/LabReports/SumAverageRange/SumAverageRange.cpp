/*
C++ SumAverageRange
6/2/2021
Version 1
Kevin Wong
*/
#include <iostream>
#include <iomanip> 
using namespace std;
const int NUMBER_COUNT = 10; // define a constant
int main(int arge, char* argv[])
{
    int sumOfOddNumbers = 0; // integers hold only whole numbers
    int sumOfEvenNumbers = 0;
    double sumOfAllNumbers = 0;
    int minValue = 0;
    int maxValue = 0;
    int number;
    double inputCounter = 1;
    double averageNum;
    // INPUT: numbers
    while (inputCounter <= NUMBER_COUNT){ // count from 1 to NUMBER_COUNT
        cout << "Enter a number: ";
        cin >> number;

        //########################### Rejection Code ######################

        if (cin.fail() ){
            cout << "Illegal entry for number" << endl;
            return 1;
            }
        if (number < 0){
            cout << "Negative values are not allowed" << endl;
            return 1; 
            }
        //##################################################################

        // determine if the number is odd or even
        if (number %2 == 1) // odd number
            sumOfOddNumbers += number;
        else // even number
            sumOfEvenNumbers += number;
            // also add the total of all numbers
            sumOfAllNumbers += number;
        // determine the range (min, max) of the input values
        if (inputCounter == 1) // reading the first value?
            {
            minValue = number; // initialize minValue and maxValue
            maxValue = number; // to the first value read from kbd
            }
        else// not reading the first value
            {
            if (number < minValue) // see if minValue needs updating
            minValue = number;
            // -yes
            if (number > maxValue) // see if maxValue needs updatingS
            maxValue = number; // -yes
            }
        inputCounter++;
    } 
    --inputCounter;
    averageNum = sumOfAllNumbers / inputCounter;
    cout << endl; // blank line before the summary information
    cout << "Sum of Odd Numbers: " << sumOfOddNumbers << endl;
    cout << "Sum of Even Numbers: " << sumOfEvenNumbers << endl;
    cout << "Sum of All Numbers: " << sumOfAllNumbers << endl;
    cout << "The lowest value is: " << minValue << endl;
    cout << "The highest value is: " << maxValue << endl;
    cout << "The average value is: " << setprecision(2) << averageNum << endl;
    cout << endl; // blank line at end of program
    return 0;
}
