/*
ATM
7/19/2021
Version 1
Kevin Wong
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <iomanip>
#include "ATM.hpp"
using namespace std;

int main()
{
    streamoff customerIndex;
    char anotherRequest = ' ';

    while (true) {  // infinite loop - typical for embedded systems
        cout << "\n\n===========================\n";
        cout <<     "== Welcome to Phony Bank ==\n";
        cout <<     "===========================\n\n";

        customerIndex = searchForCustomer();
        do {
            if (customerIndex == -1) {
                return -1;  // can't open the customer file. Exit program
            }
            else if (customerIndex == -2) {
                cout << "Account number not found" << endl;
                continue;
            }
            else if (customerIndex == -3) {
                cout << "Incorrect PIN" << endl;
                continue;
            }
            else if (customerIndex == -4)  // the customer file was displayed
                continue;
            char checkingOrSavings = selectAccount(customerIndex); // 'C' = checking, 'S' = savings, 'X' = cancel
            if (checkingOrSavings == 'X')
                break;  // done with this customer
            
            char transaction = selectTransaction();
            switch (transaction) {
            case 'B':  // balance
                cout << showpoint << fixed << setprecision(2);
                cout << "$" << getBalance(customerIndex, checkingOrSavings) << endl;
                break;
            case 'D':  // deposit
                deposit(customerIndex, checkingOrSavings);
                break;
            case 'W':  // withdraw
                withdraw(customerIndex, checkingOrSavings);
                break;
            case 'X':  // cancel
                break;
            }
            // Do you want another requst for the same customer?
            do { // get a 'Y' or 'N' response
                cout << "Do you want another transaction for the same customer? (Y/N)? ";
                anotherRequest = toupper(getChar());
            } while (anotherRequest != 'Y' && anotherRequest != 'N');
        } while (anotherRequest == 'Y');
    } // end of while (true)
    return 0;   // end of main( )
}

////////////////////////////////////////////////////////////
// searchForCustomer()
//    return:  
//      >= 0 index into the file for the selected customer
//      -1 = unable to open customer file
//      -2 = customer not found in the fileIN
//      -3 = PIN does not match customer selection
//      -4 = customer file displayed to stdout
streamoff searchForCustomer() {
    int accountNo;
    int pin = 0;
    streamoff customerIndex=0;      // -2=customer not found,  -3=PIN does not match
    ATM customer;                   // customer record (acctNo, PIN, chk, sav)

    cout << "Select a customer account number," << endl;
    cout << "[Enter] key to  display the customer data file" << endl;
    cout << "Account? ";
    accountNo = getInt();

    if (accountNo == 0) { // display file
        displayFile();
        return -4;  // entire customer file was displayed
    }
    if (accountNo >= 0) {
        cout << "Enter PIN? ";
        pin = getInt();
    }

    // open the customer data file
    ifstream ATM_file(ATMfilename, ios::binary);
    if (ATM_file.fail()) {
        cout << "Unable to open ATMaccounts " << endl;
        return -1;
    }
    ATM_file.read((char*)&customer, sizeof(customer));  // read first record   
    for (int i = 0; !ATM_file.eof(); i++) {
        if (accountNo == customer.getAcctNo()) { // found the customer in the file
            if (pin == customer.getPIN()) customerIndex = i;  // customer an PIN match
            else  customerIndex = -3; // PIN does not match return code
            break;  // customer and PIN match the request. Exit loop
        }
        ATM_file.read((char*)&customer, sizeof(customer));  // next customer
    }
    if (ATM_file.eof())   // reached EOF and didn't find the customer
        customerIndex = -2;  // customer not found
    ATM_file.close();

    if (customerIndex >= 0) {  // customer has been found. Display balances
        cout << fixed << showpoint << setprecision(2);
        cout << endl << "Checking $" << customer.getChecking()
             << "  Savings $" << customer.getSavings() << endl << endl;
    }
    return customerIndex;
}

////////////////////////////////////////////////////////////
// displayFile()
//   Displays all of the customer records in the file
//     return:  
//      0 = success
//     -1 = error displaying file
int displayFile() {
    ifstream ATM_file(ATMfilename, ios::binary);
    if (ATM_file.fail()) {
        cout << "Unable to open ATMaccounts " << endl;
        return -1;
    }
    ATM customer;    // customer record (acctNo, PIN, chk, sav)
    // display header information
    cout << fixed << showpoint << setprecision(2);  // format the output
    cout << setw(-7) << " Acct #" << "     "
        << setw(-4) << "PIN" << "   "
        << setw(-8) << "Checking" << "    "
        << setw(-8) << "Savings" << endl;

    ATM_file.read((char*)&customer, sizeof(customer));  // read first customer
    for (int i = 0; !ATM_file.eof(); i++) {
        cout << setw(7) << customer.getAcctNo() << "    "
             << setw(4) << customer.getPIN() << "   "
             << setw(8) << customer.getChecking() << "   "
             << setw(8) << customer.getSavings() << endl;
        ATM_file.read((char*)&customer, sizeof(customer));  // read next customer
    }
    ATM_file.close();
    return 0;
}

////////////////////////////////////////////////////////////
// selectAccount()
//    return:  'C  or  'S'   for checking or savings
char selectAccount(streamoff customerIndex) {
    cout << "Select account:" << endl;
    cout << "  C = checking" << endl;
    cout << "  S = savings" << endl;
    cout << "  X = cancel" << endl;

    char accountType = ' ';  // C=checking,  S=savings

    do {
        cout << "? ";
        accountType = toupper(getChar());
        if (accountType == 'C' || accountType == 'S' || accountType == 'X')
            break; // legal selection
        cout << "  Illegal selection. Try again." << endl;
    } while (accountType != 'C' && accountType != 'S' && accountType != 'X');
    return accountType;
}

////////////////////////////////////////////////////////////
// getBalance(int customerIndex, char accountType)
//    where:
//      customerIndex = customer number in the file
//      accountType     'C'=checking,  'S'=savings
//    return:  
//       of either customer's checking or savings account
double getBalance(streamoff customerIndex, char accountType) {
    double balance = 0.0;
    // search the file for the customer number
    ifstream ATM_file(ATMfilename, ios::binary);
    if (ATM_file.fail()) {
        cout << "Unable to open ATMaccounts " << endl;
        return balance;
    }
    ATM customer;    // customer record (acctNo, PIN, chk, sav)
    // seek to the selected customer
    streamoff customerPositionInFile = customerIndex * ATM::ATMsize;
    ATM_file.seekg(customerPositionInFile, ATM_file.beg);
    ATM_file.read((char*)&customer, sizeof(customer));
    if (accountType == 'C')
        balance = customer.getChecking();
    else if (accountType == 'S')
        balance = customer.getSavings();
    ATM_file.close();
    return balance;
}

////////////////////////////////////////////////////////////
// char selectTransaction()
//    return:  'B', 'D', 'W' or 'X'
char selectTransaction() { // D=deposit  W=withdraw  X=cancel
    cout << "Select transaction:" << endl;
    cout << "  B = Balance" << endl;
    cout << "  D = deposit" << endl;
    cout << "  W = withdraw" << endl;
    cout << "  X = cancel" << endl;

    char transactionType = ' ';  
    do {
        transactionType = toupper(getChar());
        if (transactionType == 'B' || transactionType == 'D' || transactionType == 'W' || transactionType == 'X')
            break; // legal selection
        cout << "  Illegal selection. Try again." << endl;
    } while (transactionType != 'B' && transactionType != 'D' && transactionType != 'W' && transactionType != 'X');
    return transactionType;
}

////////////////////////////////////////////////////////////
// void deposit(int customerIndex, char accountType)
//    where:
//      customerIndex = customer within the file
//      accountType:  'C'=checking   'S'=savings
//    The function requests the amount to deposit, then
//      validates that the amount is greater than zero
//      reads the customer record and adds the deposit
//    ` updates the customer data file
void deposit(streamoff customerIndex, char accountType) {
    double depositAmount;
    double newBalance = 0.0;

    cout << "Enter the amount of the deposit: ";
    depositAmount = getDouble();  // check for > 0 after getting current balance

    // compute amount of withdrawal in pennies used to check for increments of $20.00
    int intdepositX100 = (int)(depositAmount * 100);  // convert to pennies

    if (depositAmount <= 0.00) 
        cout << "Deposit must be greater than zero" << endl << endl;
    else 
    {
        // open in binary mode for both reading and writing
        fstream ATM_file(ATMfilename, ios::binary | ios::in | ios::out);
        if (ATM_file.fail()) {
            cout << "Unable to open ATMaccounts data file" << endl;
            return;
        }
        ATM currentCustomer;

        streamoff customerPositionInFile = customerIndex * ATM::ATMsize;
        ATM_file.seekg(customerPositionInFile, ATM_file.beg);
        ATM_file.read((char*)&currentCustomer, sizeof(ATM));
        if (accountType == 'C') {  
            newBalance = currentCustomer.getChecking() + depositAmount;
            currentCustomer.setChecking(newBalance);
        }
        else if (accountType == 'S') {
            newBalance = currentCustomer.getSavings() + depositAmount;
            currentCustomer.setSavings(newBalance);
        }
        // seek back to the same record and write the updated record back to disk
        ATM_file.seekg(customerPositionInFile, ATM_file.beg);
        ATM_file.write((char*)&currentCustomer, sizeof(ATM));

        ATM_file.close(); // close the file

        // display the updated balance
        cout << fixed << showpoint << setprecision(2);  // display 2 digits past the decimal
        cout << "Your balance is $" << newBalance << endl;
    } // end of a processed withdrawal
}

////////////////////////////////////////////////////////////
// void withdraw(int customerIndex, char accountType)
//    where:
//      customerIndex = customer within the file
//      accountType:  'C'=checking   'S'=savings
//    The function requests the amount to withdraw, then
//      validates that the amount is an even multiple of $20.00
//      maximum withdrawal is $500.00
//      reads the customer record and validates sufficient funds
//      deducts the amount and updates the customer data file
void withdraw(streamoff customerIndex, char accountType) {
    double withdrawAmount;
    double newBalance = 0.0;

    cout << "Enter the amount of the withdrawal in increments of $20 up to $500: ";
    withdrawAmount = getDouble();  // check for > 0 after getting current balance

    // compute amount of withdrawal in pennies used to check for increments of $20.00
    int intWithdrawX100 = (int)(withdrawAmount * 100);  // convert to pennies

    if (withdrawAmount <= 0.00) 
        cout << "Withdrawal must be greater than zero" << endl << endl;
    else if (withdrawAmount > 500.00)
        cout << "Withdrawal must not exceed $500.00" << endl << endl;
    else if (intWithdrawX100 % 2000 != 0)  // 2000 = $20 in pennies, 
        cout << "Withdrawal must be in increments of $20.00" << endl << endl;
    else // proceed with withdrawal
    {
        // open in binary mode for both reading and writing
        fstream ATM_file(ATMfilename, ios::binary | ios::in | ios::out);
        if (ATM_file.fail()) {
            cout << "Unable to open ATMaccounts data file" << endl;
            return;
        }
        ATM currentCustomer;
        // seek to the selected customer from beginning of the file and update the selected balance
        streamoff customerPositionInFile = customerIndex * ATM::ATMsize;
        ATM_file.seekg(customerPositionInFile, ATM_file.beg);
        ATM_file.read((char*)&currentCustomer, sizeof(ATM));
        if (accountType == 'C') {   // update the customer's checking balance
            newBalance = currentCustomer.getChecking() - withdrawAmount;
            currentCustomer.setChecking(newBalance);
        }
        else if (accountType == 'S') { // update customer's savings balance
            newBalance = currentCustomer.getSavings() - withdrawAmount;
            currentCustomer.setSavings(newBalance);
        }
        // seek back to the same record and write the updated record back to disk
        ATM_file.seekg(customerPositionInFile, ATM_file.beg);
        ATM_file.write((char*)&currentCustomer, sizeof(ATM));

        ATM_file.close(); // close the file

        // display the updated balance
        cout << fixed << showpoint << setprecision(2);  // display 2 digits past the decimal
        cout << "Your balance is $" << newBalance << endl;
    } // end of a processed withdrawal
}

////////////////////////////////////////////////////////////    
//// The following methods read from the keyboard and 
////   verify that valid data was entered
////////////////////////////////////////////////////////////    
// char getChar()
//  reads a line of text from standard input (keyboard)
//  returns the first character that was input
//  the rest of the line is discarded
char getChar() {
    char buff[100];
    cin.getline(buff, 100);
    return(buff[0]);
}

// int getInt()
//  reads an integer from standard input (keyboard)
//  returns the first character that was input
//  displays an error message and tries again if a non-integer is input
int getInt() {
    int result;
    bool tryAgain;
    do {
        tryAgain = false;
        try {
            char buff[100];
            cin.getline(buff, 100);
            result = atoi(buff);
            if (cin.fail())
                throw 1; // different values for the throw to display different conditions in the catch
        }
        catch (...) {
            cout << "*** Illegal entry. Enter an integer. Try again" << endl << "? ";
            cin.clear(); // clear the input buffer
            cin.ignore(1000, '\n'); // and ignore anything else before a new cin
            tryAgain = true;
        }
    } while (tryAgain);
    return result;
}

// double getDouble()
//  reads a real number from standard input (keyboard)
//  returns the first character that was input
//  displays an error message and tries again if an error is detected
double getDouble() {
    double result;
    bool tryAgain;

    do {
        tryAgain = false;
        try {
            char buff[100];
            cin.getline(buff, 100);
            result = atof(buff);
            if (cin.fail())
                throw 1; // different values for the throw to display different conditions in the catch
        }
        catch (...) {
            cout << "*** Illegal entry. Enter an number. Try again" << endl << "? ";
            tryAgain = true;
        }
    } while (tryAgain);
    return result;
}
