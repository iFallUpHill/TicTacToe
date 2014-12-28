#include <iostream>
#include <cstdlib> // For Exit Messages
#include "tictactoe.h"

using namespace std;

Tictactoe::Tictactoe()
{
    turn = 1;
    p1Score = 0;
    p2Score = 0;
    p1Name = "";
    p2Name = "";
    isFinished = false;
    isVictorious = false;
    isValid = false;
    isDraw = false;

    for(int row = 0; row < 3; row++)
    {
        for(int column = 0; column < 3; column++)
        {
            gameBoard[row][column] = static_cast<char>(row*3 + column) + '0';
        }
    }

    for(int i = 0; i < 9; i++)
    {
        checkedBoard[i] = 0;
    }

}

void Tictactoe::resetBoard()
{
    for(int row = 0; row < 3; row++)
    {
        for(int column = 0; column < 3; column++)
        {
            gameBoard[row][column] = static_cast<char>(row*3 + column) + '0';
        }
    }

    for(int i = 0; i < 9; i++)
    {
        checkedBoard[i] = 0;
    }

    isFinished = false;
    isVictorious = false;
    isValid = false;
    isDraw = false;

}

void Tictactoe::printBoard()
{
    for(int row = 0; row < 3; row++)
    {
        cout << "-------------------------------------------------" << endl;
        cout << "|\t\t|\t\t|\t\t|" << endl;
        cout << "|\t\t|\t\t|\t\t|" << endl;
        cout << "|";
        for(int column = 0; column < 3; column++)
        {
            cout << "\t" << gameBoard[row][column] << "\t|";
        }
        cout << endl;
        cout << "|\t\t|\t\t|\t\t|" << endl;
        cout << "|\t\t|\t\t|\t\t|" << endl;
    }
    cout << "-------------------------------------------------" << endl;
}

void Tictactoe::makeMove()
{
    // Draw detection
    int tempCounter = 0;

    for(int i = 0; i < 9; i++)
    {
        if(checkedBoard[i] == 0)
        {
            tempCounter++;
        }
    }

    if(tempCounter > 0)
    {
        do{
            switch(turn)
            {
                case 1:
                    cout << "It's " << p1Name << "'s turn! You are 'x'." << endl
                         << "Where would you like to move? (Select a number to move to): ";
                    cin >> playerMove;
                    break;
                case 2:
                    cout << "It's " << p2Name << "'s turn! You are 'o'." << endl
                         << "Where would you like to move? (Select a number to move to): ";
                    cin >> playerMove;
                    break;
                default:
                    cout << "Something went wrong! Exiting program..." << endl << endl;
                    exit(1);
                    break;
            }
            cout << endl;
        }while(!checkMove());

        switch(turn) // Switches turn to the other user after a valid move has been made
        {
            case 1:
                turn = 2;
                break;
            case 2:
                turn = 1;
                break;
            default:
                cout << "Something went wrong! Exiting program..." << endl << endl;
                exit(1);
                break;
        }
    }
    else
    {
        cout << "No moves remain!" << endl;
        isDraw = true;
    }
}


void Tictactoe::showScore()
{
    cout << p1Name << " has won " << p1Score << " games. | " << p2Name << " has won " << p2Score << " games." << endl << endl;
}

void Tictactoe::setPlayerNames()
{
    cout << "Welcome to 1v1 Tic-Tac-Toe!" << endl << endl;

    cout << "Please enter a name for player 1: ";
    cin >> p1Name;
    cout << "Player 1 renamed to: " << p1Name << "!" << endl << endl;

    cout << "Please enter a name for player 2: ";
    cin >> p2Name;
    cout << "Player 2 renamed to: " << p2Name << "!" << endl << endl;



}

void Tictactoe::selectFirst()
{
    cout << "Please select who will go first. Enter 1 for " << p1Name << endl
         << "or 2 for " << p2Name << ". Enter -1 to quit. Select a player: ";
    do{
        cin >> turn;
        cout << endl << endl;
        if(!cin && turn != 1 && turn != 2)
        {
            cin.clear();
            cin.ignore(256, '\n');

            cout << "Invalid input! Please ensure that you selected" << endl
                 << "a valid player (1 for " << p1Name << ", 2 for " << p2Name << ")." << endl
                 << "Please select who will go first (or -1 to quit): ";
            turn = 0;
        }
    }while(turn != 1 && turn != 2);

    switch(turn)
    {
        case 1:
            cout << p1Name << " will start!" << endl << endl;
            break;
        case 2:
            cout << p2Name << " will start!" << endl << endl;
            break;
        case -1:
            cout << "Thanks for playing!" << endl << endl;
            isFinished = true;
            break;
        default:
            cout << "Something went wrong! Exiting program..." << endl << endl;
            exit(1);
            break;
    }

}

bool Tictactoe::getIsFinished()
{
    char tempResponse;
    cout << "Would you like to play again? Enter Y for yes, N for no." << endl
         << "Please input your selection: ";

    do{
        cin >> tempResponse;
        cout << endl;
        switch(tempResponse)
        {
            case 'Y':
            case 'y':
                cin.clear();
                cin.ignore(256, '\n');
                isFinished = false;
                break;
            case 'N':
            case 'n':
                cin.clear();
                cin.ignore(256, '\n');
                isFinished = true;
                break;
            default:
                cin.clear();
                cin.ignore(256, '\n');
                break;

        }

        if(tempResponse != 'Y' && tempResponse != 'y' && tempResponse != 'N' && tempResponse != 'n')
        {
            cout << "Invalid input. Please enter Y to play again, or N to quit." << endl
                 << "Please input your selection: ";
        }

    }while(tempResponse != 'Y' && tempResponse != 'y' && tempResponse != 'N' && tempResponse != 'n');

    return isFinished;
}

bool Tictactoe::getIsVictorious()
{
    isVictorious = false;
    if(!isDraw)
    {
        for(int i = 0; i < 3; i++)
        {
            // Column Check
            if((checkedBoard[i] == checkedBoard[i+3]) && (checkedBoard[i+3] == checkedBoard[i+6]) && (checkedBoard[i] == 1))
            {
                cout << p1Name << " has won the game!" << endl;
                p1Score++;
                isVictorious = true;
                return isVictorious;
            }
            if((checkedBoard[i] == checkedBoard[i+3]) && (checkedBoard[i+3] == checkedBoard[i+6]) && (checkedBoard[i] == 2))
            {
                cout << p2Name << " has won the game!" << endl;
                p2Score++;
                isVictorious = true;
                return isVictorious;
            }

        }

        for(int i = 0; i < 9; i+=3)
        {
            // Row check
            if((checkedBoard[i] == checkedBoard[i+1]) && (checkedBoard[i+1] == checkedBoard[i+2]) && (checkedBoard[i+2] == 1))
            {
                cout << p1Name << " has won the game!" << endl;
                p1Score++;
                isVictorious = true;
                return isVictorious;
            }
            if((checkedBoard[i] == checkedBoard[i+1]) && (checkedBoard[i+1] == checkedBoard[i+2]) && (checkedBoard[i+2] == 2))
            {
                cout << p2Name << " has won the game!" << endl;
                p2Score++;
                isVictorious = true;
                return isVictorious;
            }
        }

        // Diagonal Checks
        if((checkedBoard[0] == checkedBoard[4]) && (checkedBoard[4] == checkedBoard[8]) && (checkedBoard[8] == 1))
        {
            cout << p1Name << " has won the game!" << endl;
            p1Score++;
            isVictorious = true;
            return isVictorious;
        }
        if((checkedBoard[0] == checkedBoard[4]) && (checkedBoard[4] == checkedBoard[8]) && (checkedBoard[8] == 2))
        {
            cout << p2Name << " has won the game!" << endl;
            p2Score++;
            isVictorious = true;
            return isVictorious;
        }

        if((checkedBoard[2] == checkedBoard[4]) && (checkedBoard[4] == checkedBoard[6]) && (checkedBoard[6] == 1))
        {
            cout << p1Name << " has won the game!" << endl;
            p1Score++;
            isVictorious = true;
            return isVictorious;
        }
        if((checkedBoard[2] == checkedBoard[4]) && (checkedBoard[4] == checkedBoard[6]) && (checkedBoard[6] == 2))
        {
            cout << p2Name << " has won the game!" << endl;
            p2Score++;
            isVictorious = true;
            return isVictorious;
        }
    }
    else
    {
        cout << "The game ends in a draw. There is no winner for this round." << endl << endl;
        isVictorious = true;
        return isVictorious;
    }

    return isVictorious;
}

bool Tictactoe::checkMove()
{
        // Checks if the square is within the grid and is not already occupied
        int row = playerMove / 3;
        int column = playerMove % 3;

        switch(turn)
        {
            case 1:
                    if(checkedBoard[playerMove] == 0)
                    {
                        gameBoard[row][column] = 'x';
                        checkedBoard[playerMove] = 1;
                        isValid = true;
                        break;
                    } else
                    {
                        printBoard();
                        cout << "Invalid move! You cannot play there!" << endl << endl;
                        isValid = false;
                        break;
                    }
            case 2:
                    if(checkedBoard[playerMove] == 0)
                    {
                        gameBoard[row][column] = 'o';
                        checkedBoard[playerMove] = 2;
                        isValid = true;
                        break;
                    } else
                    {
                        printBoard();
                        cout << "Invalid move! You cannot play there!" << endl << endl;
                        isValid = false;
                        break;
                    }
            default:
                cout << "Something went wrong! Exiting program..." << endl << endl;
                exit(1);
                break;
        }

    return isValid;
}

void Tictactoe::printEndPlayerStats()
{
    int totalGames = p1Score + p2Score;
    cout << p1Name << " won " << (static_cast<double>(p1Score) / totalGames) * 100 << "% of the games played (" << p1Score << "/" << totalGames << ")." << endl
         << p1Name << " won " << (static_cast<double>(p2Score) / totalGames) * 100 << "% of the games played (" << p2Score << "/" << totalGames << ")." << endl << endl
         << "Thank you for playing my Tic-Tac-Toe game!" << endl << endl;

}












