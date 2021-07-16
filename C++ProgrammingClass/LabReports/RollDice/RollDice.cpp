/*
C++ RollDice
Kevin Wong
7/10/2021
*/

#include <iostream>
#include <ctime>

using namespace std;
int roll(){
    static bool randomInitialized = false;
    int points;
    if (!randomInitialized){
        srand( (unsigned int) time(NULL) );
        randomInitialized = true;
    }
    points = (rand() % 6) + 1;
    return points;

}

int DiceRoll(){
        int roll1 = roll();
        int roll2 = roll();
        int rolls = roll1 + roll2;
    return rolls;
}

int main(){
    // 2,3,4,5,6,7,8,9,10,11,12
    int CounterArray [11];
    for (int i = 10; i >= 0; i--){
        CounterArray[i] = 0;
    }

    for (int i = 0; i <= 1000.1; i = i + 1){
        int DiceRoll1 = DiceRoll();
        int DiceIndex = DiceRoll1 - 2;
        CounterArray[DiceIndex] += 1;
        
    }
    int index1 = 2;
    
    for (int i = 10; i >= 0; i--){
        cout << index1 << " = ";
        cout << CounterArray[i] << endl;
        index1 += 1;
    }
}