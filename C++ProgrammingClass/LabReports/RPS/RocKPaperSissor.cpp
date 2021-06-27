#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

int main() {
    string Bplayer1;
    string Bplayer2;

    char Rock = 'R';
    char Paper = 'P';
    char scissor = 'S';


    cout << "Player 1, Enter either R, P, or S: ";
    cin >> Bplayer1;

    //########### Work Around for bug ################
    //Previously when too many characters were inputed the second chracter would just go to the second player
    //For instance teh first personc ould type in RR and skip the opponet's turn and get a tie
    if (Bplayer1.size() != 1){
        cout << "Too many Characters inputed";
        return 1;
    }

    char charArray[2];
    strcpy(charArray, Bplayer1.c_str());
    char player1 = charArray[0];

    //#################################################

    cout << "Player 2, Enter either R, P, or S: ";
    cin >> Bplayer2;
    //############### Work around bug ##################################
    if (Bplayer2.size() != 1){
        cout << "Too many Characters inputted";
        return 1;
    }
    char charArray2[2];
    strcpy(charArray2, Bplayer2.c_str());
    char player2 = charArray2[0];

    player1 = toupper(player1);
    player2 = toupper(player2);
    //##################################################################

    //Verify correct input

    if (player1 == Rock || player1 == Paper || player1 == scissor){
        if (player2 == Rock || player2 == Paper || player2 == scissor){


            //PLAYER1 WINS
            //Rock breaks scissors
            if (player1 == Rock && player2 == scissor){
                cout << "Player1 Wins";
                return 1;
            }
            //Paper swallows rock
            if (player1 == Paper && player2 == Rock){
                cout << "Player1 Wins";
                return 1;
            }
            //scissor cuts paper 
            if (player1 == scissor && player2 == Paper){
                cout << "Player1 Wins";
                return 1;
            }
            //PLAYER2 WINS
            //Rock breaks scissors
            if (player2 == Rock && player1 == scissor){
                cout << "Player2 Wins";
                return 1;
            }
            //Paper swallows rock
            if (player2 == Paper && player1 == Rock){
                cout << "Player2 Wins";
                return 1;
            }
            //scissor cuts paper 
            if (player2 == scissor && player1 == Paper){
                cout << "Player2 Wins";
                return 1;
            }
            //Tie no One wins
            if (player1 == player2){
                cout << "Tie - No one wins";
                return 1;
            }
        }
    }
    cout << "Invalid Input";



return 0;
}
