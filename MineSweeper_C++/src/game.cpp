#include <iostream>
#include "game.h"
#include "board.h"

Game::Game(int row, int col){
    this->board = new Board(row, col);
    this->isContinue = true;
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
    
    if (board->shoot(row, col))
    {
        std::cout << "Mayina bastiniz...\n";
        isContinue = false;
    }
    
}

void Game::isAllOpen(){
    if (getBoard()->getMines() + getBoard()->getOpenedCells() == getBoard()->getRows() * getBoard()->getCols())
    {
        setIsContinue(false);
    }
    
}

void Game::setBoard(Board* board){
    this->board = board;
}

void Game::setIsContinue(bool isContinue){
    this->isContinue = isContinue;
}

Board* Game::getBoard(){
    return this->board;
}

bool Game::getIsContinue(){
    return this->isContinue;
}

void Game::simuleEt() {
    int row, col;
    char action;

    while (isContinue) {
        board->displayBoard();

        std::cout << "\n[O] Acmak, [F] Bayrak koymak/cikarmak\n";
        std::cout << "Seciminiz (O/F): ";
        std::cin >> action;

        std::cout << "Satir girin (0 - " << board->getRows() - 1 << "): ";
        std::cin >> row;

        std::cout << "Sutun girin (0 - " << board->getCols() - 1 << "): ";
        std::cin >> col;

        if (action == 'O' || action == 'o') {
            if (board->shoot(row, col)) {
                std::cout << "\n Mayina bastiniz! Oyun bitti.\n";
                isContinue = false;
            }
        } 
        else if (action == 'F' || action == 'f') {
            board->flag(row, col);
        } 
        else {
            std::cout << "Gecersiz islem. Lutfen sadece 'O' veya 'F' girin.\n";
            continue;
        }

        isAllOpen();

        system("cls");
    }

    // Oyun sonunda final tahtasını göster
    board->displayBoard();

    if (board->getMines() + board->getOpenedCells() == board->getRows() * board->getCols()) {
        std::cout << "\n🎉 Tebrikler! Tum guvenli hucreleri actiniz. Oyunu kazandiniz!\n";
    } else {
        std::cout << "\n😵 Kaybettiniz! Bir dahaki sefere daha dikkatli olun.\n";
    }
}
