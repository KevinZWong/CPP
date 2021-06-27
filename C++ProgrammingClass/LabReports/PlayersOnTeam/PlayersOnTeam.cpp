/* 
C++ PlayersOnTeam
6/18/2021
Kevin Wong
*/
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
    int teamSize;
    int playersOnTeam;
    int morePlayersNeeded;
    int extraPlayers;
    
    // Input the team size
    cout << "How many players should be on the team? ";
    cin >> teamSize;
    if (cin.fail() ) // check for a non-numeric value being input
    {
        cout << "Illegal entry for team size" << endl;
        return 1; // exit the program and return an error code = 1
    }
    if (teamSize < 1) // check for a negative number being input
    {
        cout << "Negative values are not allowed" << endl;
        return 1; // exit the program and return an error code = 1
    }
    // Input the number of players are on the team
    cout << "How many players are actually on the team? ";
    cin >> playersOnTeam;
    if (cin.fail() ) // check for a non-numeric value being input
    {
        cout << "Illegal entry for players on the team" << endl;
        return 1; // exit the program and return an error code = 1
    }
        if (playersOnTeam < 1) // check for a negative number being input
    {
    cout << "Negative values are not allowed" << endl;
    return 1; // exit the program and return an error code = 1
    }
    // Process and output - check for correct number of players
    if (playersOnTeam < teamSize)
    {
        cout << "There are not enough players" << endl;
        morePlayersNeeded = teamSize - playersOnTeam;
        cout << morePlayersNeeded << " more players are needed" << endl << endl;
    }
    else if (playersOnTeam > teamSize)
    {
        cout << "There are too many players" << endl;
        extraPlayers = playersOnTeam - teamSize;
        cout << extraPlayers << " players need to be eliminated" << endl << endl;
    }
    else
    {
    cout << "You have the correct number of players" << endl << endl;
    }
    return 0; // exit the program with error code = 0
}
