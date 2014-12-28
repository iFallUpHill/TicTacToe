#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <string>
using namespace std;

class Tictactoe
{
    public:
        Tictactoe();
        void setPlayerNames(); // Displays preliminary information to set up the game
        void resetBoard(); // Resets the tic-tac-toe grid
        void printBoard(); // Prints board with available moves
        void makeMove(); // Enables appropriate player to make a move
        void showScore(); // Displays the score of the game
        void selectFirst(); // Sets who will make the first move
        bool getIsFinished(); // Returns true if user no longer wants to play
        bool getIsVictorious();// Returns true if either player wins
        void printEndPlayerStats(); // Prints the win percentages at the end of the game

    protected:
    private:
        void gameDrawResult(); // Ends game if no valid moves remain and no one has won
        bool checkMove(); // Returns true if the current move is valid
        char gameBoard[3][3]; // Standard 3x3 game board
        int checkedBoard[9]; // Stores true if a square has been played on
        int turn; // Stores whose turn it is
        int playerMove; // Stores the square that the current user wishes to play on
        int p1Score; // Stores the score of the first player
        int p2Score; // Stores the score of the second player
        string p1Name; // Store the name of the first player
        string p2Name; // Stores the name of the second player
        bool isFinished; // False if user wants to play another game
        bool isVictorious; // False if the current game is not over
        bool isValid; // False if the current move is invalid
        bool isDraw; // True if no valid moves remain and no one has won

};

#endif // TICTACTOE_H
