#include <iostream>
#include <vector>
#include <string>

using namespace std;
class TicTacToe {
public:
/* Constructor*/
    TicTacToe(){
/* Initialize defaults here */
    }
/* This is your game board*/
    vector<vector<char>> gameBoard
            {
                    {'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}
            };
/* This prints your game board*/
    void printGameBoard()
    {
        for (int i = 0; i < gameBoard.size(); i++)
        {
            for (int j = 0; j < gameBoard[i].size(); j++)
            {
                cout << gameBoard[i][j] << " ";
            }
            cout << endl;
        }
    }
/* This method modifes the game board*/
    void modifyGameBoard(char player, int position)
    {
        int row = (position-1)/3;
        int column = (position-1)%3;

        gameBoard[row][column] = player;
    }

    char getCharAtPosition(int position){
        int row = (position-1)/3;
        int column = (position-1)%3;
        return gameBoard[row][column];
    }

    char checkForWinner(){
        char winner = 'N';
        int i;

        for (i=0; i<3 ;i++){
            if (gameBoard[i][0]==gameBoard[i][1] && gameBoard[i][0]==gameBoard[i][2]) {
                winner = gameBoard[i][0];
            } else if (gameBoard[0][i]==gameBoard[1][i] && gameBoard[0][i]==gameBoard[2][i]) {
                winner = gameBoard[0][i];
            }
        }

        if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2]){
            winner = gameBoard[1][1];
        } else if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0]) {
            winner = gameBoard[1][1];
        }

        return winner;
    }
};

int main() {
    TicTacToe game;
    int play_id = 0;
    std::cout << "TIC TAC TOE\n";

    /* N = game in progress, O = "O" wins, X = "X" wins */
    char winner = 'N';
    char current_player = 'X';

    game.printGameBoard();

    while (winner == 'N' && play_id < 9) {
        play_id++;

        bool did_succeed = false;
        int input_position;

        while (!did_succeed) {
            std::cout << "Player " << current_player << " Enter Position :";
            std::cin >> input_position;
            if (input_position >= 1 && input_position <= 9) {
                char current_value = game.getCharAtPosition(input_position);
                if (current_value != 'O' && current_value != 'X') {
                    did_succeed = true;
                    game.modifyGameBoard(current_player, input_position);
                } else {
                    std::cout << "A player has already gone there. Try again!\n";
                }
            } else {
                std::cout << "Enter a valid integer between 1 and 9.\n";
            }
        }

        if (current_player == 'X') {
            current_player = 'O';
        } else {
            current_player = 'X';
        }

        winner = game.checkForWinner();
        game.printGameBoard();
    }

    if (winner != 'N') {
        cout << "Player " << winner << " Wins!!!\nGAME OVER\n";
    } else {
        cout << "It's a draw! Try again.\n";
    }
}