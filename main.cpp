#include <iostream>
#include "tictactoe.h"

using namespace std;

int main()
{
    Tictactoe fullGame;
    fullGame.setPlayerNames();

    do{
        fullGame.selectFirst();
        fullGame.resetBoard();
        fullGame.printBoard();
        do{
            fullGame.makeMove();
            fullGame.printBoard();
        }while(!fullGame.getIsVictorious());

        fullGame.showScore();
    }while(!fullGame.getIsFinished());

    fullGame.printEndPlayerStats();

    return 0;
}
