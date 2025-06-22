#include <iostream>
#include "Board.h"

int main() {
    TicTacToe game;
    char playAgain;

    do {
        game.reset();

        while (true) {
            std::cout << "\n--- TIC-TAC-TOE ---\n";
            game.drawBoard();

            if (game.getCurrentPlayer() == game.getPlayerSymbol()) {
                game.playerMove();
            } else {
                game.computerMove();
            }

            if (game.checkWin(game.getCurrentPlayer())) {
                std::cout << "\n--- GAME OVER ---\n";
                game.drawBoard();

                if (game.getCurrentPlayer() == game.getPlayerSymbol()) {
                    std::cout << "\nCongratulations! You (" << game.getPlayerSymbol() << ") win!\n";
                } else {
                    std::cout << "\nThe Computer (" << game.getComputerSymbol() << ") wins! Better luck next time.\n";
                }
                break;
            }

            if (game.isFull()) {
                std::cout << "\n--- GAME OVER ---\n";
                game.drawBoard();
                std::cout << "\nIt's a draw!\n";
                break;
            }

            game.switchCurrentPlayer();
        }

        std::cout << "\nPlay again? (y/n): ";
        std::cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    std::cout << "\nThanks for playing!\n";
    return 0;
}

/*
    mkdir build
    cd build
    cmake .. build .
*/