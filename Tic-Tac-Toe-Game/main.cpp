#include <iostream>
using namespace std;

// Display Board
void displayBoard(char board[9]){
    cout << "\n-------------\n";
    cout << "| " << board[0] << " | " << board[1] << " | " << board[2] << " |\n";
    cout << "-------------\n";
    cout << "| " << board[3] << " | " << board[4] << " | " << board[5] << " |\n";
    cout << "-------------\n";
    cout << "| " << board[6] << " | " << board[7] << " | " << board[8] << " |\n";
    cout << "-------------\n";
}

// Check Win
bool checkWin(char board[9], int winPatterns[][3], char player){
    for(int i = 0; i < 8; i++){
        if(board[winPatterns[i][0]] == player &&
           board[winPatterns[i][1]] == player &&
           board[winPatterns[i][2]] == player){
            return true;
        }
    }
    return false;
}

int main(){
    char board[9] = {'0','1','2','3','4','5','6','7','8'};

    int winPatterns[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8},
        {0,3,6}, {1,4,7}, {2,5,8},
        {0,4,8}, {2,4,6}
    };

    char player1, player2;

    cout << "======= Tic Tac Toe Game =======\n";
    cout << "Enter Player 1 choice (X/O): ";
    cin >> player1;
    player1 = toupper(player1);

    if(player1 == 'X'){
        player2 = 'O';
    } else if(player1 == 'O'){
        player2 = 'X';
    } else{
        cout << "Invalid input! Defaulting to X and O.\n";
        player1 = 'X';
        player2 = 'O';
    }

    cout << "Player 1: " << player1 << endl;
    cout << "Player 2: " << player2 << endl;

    displayBoard(board);

    int moves = 0;
    char currentPlayer = player1;

    while(moves < 9){
        int position;

        cout << "\nPlayer " << currentPlayer << ", enter position (0-8): ";
        cin >> position;

        // Input validation
        if(position < 0 || position > 8 || 
           board[position] == player1 || board[position] == player2){
            cout << "Invalid move! Try again.\n";
            continue;
        }

        // Make move
        board[position] = currentPlayer;
        displayBoard(board);
        moves++;

        // Check win
        if(moves >= 5 && checkWin(board, winPatterns, currentPlayer)){
            cout << "\n🎉 Player " << currentPlayer << " wins!\n";
            return 0;
        }

        // Switch player
        currentPlayer = (currentPlayer == player1) ? player2 : player1;
    }

    cout << "\n Match Draw!\n";
    return 0;
}