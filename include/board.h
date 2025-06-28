#ifndef BOARD_H
#define BOARD_H

class TicTacToe{
private:
    char cells[3][3];
    char playerSymbol = 'X';
    char computerSymbol = 'O';

    // helper function
    bool isMoveValid(int row, int col) const;
    
public:
    //constructor
    TicTacToe();

    // game setup and display
    void reset();
    void drawBoard() const;

    // move handling
    bool setCell(int row, int col, char symbol);
    bool isFull() const;
    bool checkWin(char symbol) const;

    // player and computer actions
    bool computerMove();
    bool playerMove();

    //accessor
    char getPlayerSymbol() const { return playerSymbol; }
    char getComputerSymbol() const { return computerSymbol; }
};





#endif
