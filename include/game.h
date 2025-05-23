#ifndef GAME_H
#define GAME_H
#include "board.h"

class Game{
private:
    DrawBoard board;
    char player = 'X';
    char computer = 'O';
    void playerMove();
    void computerMove();
    bool checkWinner();
    bool checkTie();
public:
    void startGame();
};

#endif