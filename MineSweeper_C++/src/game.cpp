#include <iostream>
#include "game.h"
#include "board.h"

Game::Game(int row, int col){
    this->board = new Board(row, col);
}
    
Game::~Game(){
    delete board;
}

void Game::inputControl(){
    std::cout << "Vurmak istediginiz satiri giriniz: ";
    int row;
    std::cin >> row;
    std::cout << "Vurmak istediginiz sutunu giriniz: ";
    int col;
    std::cin >> col;
    
    if (board->shoot(row, col) == true)
    {
        std::cout << "Mayina bastiniz...";
        isContinue = false;
    }
    
}

void Game::isAllOpen(){
    
}

void Game::simuleEt(){
    while (isContinue)
    {
        inputControl();
    }
    
}