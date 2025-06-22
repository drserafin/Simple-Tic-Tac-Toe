#ifndef BOARD_H
#define BOARD_H

class TicTacToe {
private:
    char cells[3][3];
    char playerSymbol = 'X';
    char computerSymbol = 'O';
    char currentPlayer = 'X';

    // Helper functions
    bool isMoveValid(int row, int col) const;
    void translatePosition(int position, int& row, int& col) const;

public:
    // Constructor
    TicTacToe();

    // Game state management
    void reset();
    void drawBoard() const;

    // Cell interactions
    bool setCell(int row, int col, char symbol);
    bool getCell(int row, int col) const;

    // Game logic checks
    bool isFull() const;
    bool checkWin(char symbol) const;

    // Player and computer actions
    bool playerMove();
    bool computerMove();

    // Player turn management
    void switchCurrentPlayer(); 
    char getCurrentPlayer() const;

    // Getters for player/computer symbols
    inline char getPlayerSymbol() const { return playerSymbol; }
    inline char getComputerSymbol() const { return computerSymbol; }
};

#endif
