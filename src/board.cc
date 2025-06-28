#include "board.h"
#include <iostream>
#include <cstdlib>   // rand, srand
#include <limits>    // for numeric_limits


TicTacToe::TicTacToe() {
   reset();
}


void TicTacToe::reset() {
   for (int row = 0; row < 3; ++row)
       for (int col = 0; col < 3; ++col)
           cells[row][col] = ' ';
}


void TicTacToe::drawBoard() const {
   std::cout << '\n';
   for (int row = 0; row < 3; ++row) {
       std::cout << "     |     |     \n";
       for (int col = 0; col < 3; ++col) {
           std::cout << "  " << cells[row][col] << "  ";
           if (col < 2) std::cout << "|";
       }
       std::cout << '\n';
       if (row < 2)
           std::cout << "_____|_____|_____\n";
       else
           std::cout << "     |     |     \n";
   }
}


bool TicTacToe::isMoveValid(int row, int col) const {
   return row >= 0 && row < 3 && col >= 0 && col < 3 && cells[row][col] == ' ';
}


bool TicTacToe::setCell(int row, int col, char symbol) {
   if (isMoveValid(row, col)) {
       cells[row][col] = symbol;
       return true;
   }
   return false;
}


bool TicTacToe::isFull() const {
   for (int row = 0; row < 3; ++row)
       for (int col = 0; col < 3; ++col)
           if (cells[row][col] == ' ') return false;
   return true;
}


bool TicTacToe::checkWin(char symbol) const {
   for (int row = 0; row < 3; ++row)
       if (cells[row][0] == symbol && cells[row][1] == symbol && cells[row][2] == symbol)
           return true;


   for (int col = 0; col < 3; ++col)
       if (cells[0][col] == symbol && cells[1][col] == symbol && cells[2][col] == symbol)
           return true;


   return (cells[0][0] == symbol && cells[1][1] == symbol && cells[2][2] == symbol) ||
          (cells[0][2] == symbol && cells[1][1] == symbol && cells[2][0] == symbol);
}


bool TicTacToe::playerMove() {
   int position;
   while (true) {
       std::cout << "Player " << playerSymbol << ", enter your move (1-9): ";
       std::cin >> position;


       if (std::cin.fail() || position < 1 || position > 9) {
           std::cout << "Invalid input. Enter a number from 1 to 9.\n";
           std::cin.clear();
           std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
           continue;
       }


       int row = (position - 1) / 3;
       int col = (position - 1) % 3;


       if (setCell(row, col, playerSymbol)) {
           return true;
       } else {
           std::cout << "That spot is taken. Try again.\n";
       }
   }
}


bool TicTacToe::computerMove() {
   if (isFull()) return false;


   while (true) {
       int row = rand() % 3;
       int col = rand() % 3;
       if (setCell(row, col, computerSymbol)) {
           std::cout << "Computer placed '" << computerSymbol << "' at (" << row << ", " << col << ").\n";
           return true;
       }
   }
}
