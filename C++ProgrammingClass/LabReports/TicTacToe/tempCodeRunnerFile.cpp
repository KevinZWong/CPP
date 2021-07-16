        // convert inputCharacter from ASCII ('1' to '9') to integer (0 to 8)
        // to select the row and column index for the 3x3 array
        choice = inputCharacter - '1'; // now the inputs are 0,1,2,3,4,5,6,7,8
        int row = choice / 3; // row will be 0 (for 0,1,2), 1 (for 3,4,5), 2 for (6,7,8)
        int col = choice % 3; // col will be 0 (for 0,3,6), 1 (for 1,4,7), 2 for (2,5,8)
        
        if (choice < 0 || choice > 8)   // see if the input is below 1 or greater than 0
            cout << "Illegal value, try again" << endl;
        else if (board[row][col]=='X' || board[row][col]=='O')
            cout << "This space has already been used, try again" << endl;
        else
        {
            board[row][col] = player;   // put in an 'X' or an 'O'
            squareCounter++;            // count the number of squares completed
            // select the next player
            if (player=='X')
                player = 'O';           // switch from 'X' to 'O' for next move
            else
                player = 'X';           // switch from 'O' to 'X' for next move
        }
        gameWinner = CheckForWinningGame(board); // returns 'X' or 'O' if the game is won
    }
    
    // The game is over. Either the game has been won or no more squares
    DisplayTicTacToe(board);
    cout << endl;   // blank line
    if (gameWinner =='X' || gameWinner == 'O')
        cout << "Player " << gameWinner << " wins the game" << endl << endl;
    else
        cout << "Tie Game" << endl << endl;

    return 0;
}

// ------ Display the Tic Tac Toe board
void DisplayTicTacToe(char board[3][3])