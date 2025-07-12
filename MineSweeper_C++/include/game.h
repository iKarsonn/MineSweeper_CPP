#ifndef GAME_H
#define GAME_H
#include "board.h"

class Game {
private:
    Board* board;
    bool isContinue;  //Oyun devam kosullari saglaniyor mu

    void inputControl();  //Vurulan noktanın kontrolunu gerceklestiren method
    void isAllOpen();  //Mayin bulunmayan tum noktalar acildi mi

public:
    Game(int, int);
    ~Game();

    void setBoard(Board*);
    void setIsContinue(bool);
    Board* getBoard();
    bool getIsContinue();

    void simulate();  //Oyunu simule eden method

};

#endif