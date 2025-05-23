#include<iostream>
#include "game.h"


void Game::startGame(){
    while(true){
        board.drawBoard();
        playerMove();

        if (checkWinner()) {
            board.drawBoard();
            break;
        } else if (checkTie()) {
            board.drawBoard();
            std::cout << "\nIt's a tie!\n";
            break;
        }

        computerMove();

        if (checkWinner()) {
            board.drawBoard();
            break;
        } else if (checkTie()) {
            board.drawBoard();
            std::cout << "\nIt's a tie!\n";
            break;
        }
    }
}

void Game::playerMove(){
    int move;
    while(true){
        std::cout << "Please enter a position (1-9) you want to place your symbol: ";
        if (!(std::cin >> move)){
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            std::cout << "Invalid input, please insert a number from 1 - 9";
        }
        move = move - 1;
        if (move >= 0 && move < 9 && board.getSpaces(move) != 'X' && board.getSpaces(move) != 'O'){
            board.setSpaces(move,player);
            break;
        } else {
            std::cout << "Space already taken, please select a open space (1-9)\n";
        }
    }
}

void Game::computerMove() {
    int number;
    static bool seeded = false; //variable seeded is local to the function 
    if (!seeded) {
        srand(time(0));
        seeded = true;
    }

    while (true){
        number = rand() % 9;
        if (board.getSpaces(number) != 'X' && board.getSpaces(number) != 'O'){
            board.setSpaces(number,computer);
            break;
        }
    }
}

bool Game::checkWinner(){
        const int winPatterns[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8}, // rows
        {0,3,6}, {1,4,7}, {2,5,8}, // columns
        {0,4,8}, {2,4,6}           // diagonals
    };
    for (auto& pattern : winPatterns) {
        char a = board.getSpaces(pattern[0]);
        char b = board.getSpaces(pattern[1]);
        char c = board.getSpaces(pattern[2]);
        if (a == b && b == c && a != ' ') {
            if (a == player){
                std::cout << "\nYou won!\n";
            } else {
                std::cout << "\nYou have lost!\n";
            }
            return true;
        }
    }
    return false;
}

bool Game::checkTie(){
    for (int i = 0; i < 9; i++){
        if (board.getSpaces(i) != 'X' && board.getSpaces(i) != 'O'){
            return false;
        }
    }
    return true;
}