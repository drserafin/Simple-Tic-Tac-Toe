#include <iostream>
#include "board.h"

int main() {
    TicTacToe game;
    char playAgain;

    do {
        game.reset();
        while (true) {
            std::cout << "\n--- TIC-TAC-TOE ---";
            game.drawBoard();
            if (!game.playerMove())
                continue;

            if (game.checkWin(game.getPlayerSymbol())) {
                game.drawBoard();
                std::cout << "You win!\n";
                break;
            }

            if (game.isFull()) {
                game.drawBoard();
                std::cout << "It's a draw!\n";
                break;
            }

            game.computerMove();

            if (game.checkWin(game.getComputerSymbol())) {
                game.drawBoard();
                std::cout << "Computer wins!\n";
                break;
            }

            if (game.isFull()) {
                game.drawBoard();
                std::cout << "It's a draw!\n";
                break;
            }
        }

        std::cout << "Play again? (y/n): ";
        std::cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    std::cout << "Thanks for playing!\n";
    return 0;
}
