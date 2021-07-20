// C++ Program to print the elements of a
// Two-Dimensional array

// g++ -o keven1 extraCredit.cpp 
// ./keven1


#include<iostream>
using namespace std;
  
// an array with 4 rows and 6 columns.
int x[4][6] = {{101,1,2,3,4,5}, {102,2,3,4,5,6}, {103,3,4,5,6,7}, {104,4,5,6,7,8}};


int totalSalesPerPerson(int salesNum);
int getRowNumber(int salesNum);
int totalSalesPerProduct(int productId);


int totalSalesPerProduct(int productId) {
    int total = 0;
    for (int i = 0; i < 4; i++) {
        total += x[i][productId];
    }
    return total; 
}



int totalSalesPerPerson(int salesNum) {
    int rowNum = getRowNumber(salesNum);
    cout << "guo " << rowNum;
    int total = 0;
    for (int i = 1; i < 6; i++) {
        total += x[rowNum][i];
    }
    return total; 
}

int getRowNumber(int salesNum) {
    for (int i = 0; i < 4; i++) {
        cout << x[i][0] << " ";
        if (x[i][0] == salesNum)
            return i;
    }
    return 999; 
}


int main()
{

  
    // output each array element's value
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << x[i][j];
            cout << " ";
        }
        cout << endl;
    }
  
    int total102 = totalSalesPerPerson(102);
    cout << "Total Per Sales: 102 is " << total102 << endl;

    int totalProd3 = totalSalesPerProduct(3);
    cout << "Total Sales Per Product: #3 is " << totalProd3 << endl;

    return 0;
}