/* 
RockPaperScissors
6/21/2021
Version 2
Kevin Wong
*/
#include <iostream>
using namespace std;
int main(int arge, char* argv[])
    {
    char player1;
    char player2;
    char playAgain = 'y'; // loop control

    cout << "Enter RP or for rock, paper or scissors" << endl;
    do
    {
        cout << "Player 1 (RPS): ";
        cin >> player1;
        player1 = toupper(player1); // convert for easy comparisons

        cout << "Player 2 (RPS): ";
        cin >> player2;
        player2 = toupper(player2); // convert for easy comparisons


        if (player1 == 'R')
            {
            if (player2 == 'R')
                cout << "Tie game, nobody wins" << endl;
            else if (player2 == 'P')
                cout << "Paper covers rock - player 2 wins" << endl;
            else if (player2 == 'S')
                cout << "Rock breaks scissors - player 1 wins" << endl;
            else
                cout << "Illegal selection for player 2" << endl;
            }

        else if (player1 == 'P'){
            if (player2 == 'R')
                cout << "Paper covers rock - player 1 wins " << endl;
            else if (player2 == 'P')
                cout << "Tie game, nobody wins" << endl;
            else if (player2 == 'S')
                cout << "Scissors cuts paper - player 2 wins" << endl;
            else
                cout << "Illegal selection for player 2" << endl;
        }
        else if (player1 == 'S'){
            if (player2 == 'R')
                cout << "Rock breaks scissors - player 2 wins " << endl;
            else if (player2 == 'P')
                cout << "Scissors cuts paper" << endl;
            else if (player2 == 'S')
                cout << "Tie game, nobody wins" << endl;
            else
                cout << "Illegal selection for player 2" << endl;
        }
        else
        {
        cout << "Illegal selection for player 1" << endl;
        }
        cout << "Do you want to play again? ";
        cin >> playAgain;
        playAgain = toupper(playAgain);
        cout << endl; // blank line between games
    }
    while (playAgain == 'Y');

    return 0;
}





            