#ifndef GAME_H
#define GAME_H

class Game {
private:
    Board* board;
    bool isContinue;

    void inputControl();
    void isAllOpen();

public:
    Game(int, int);
    ~Game();

    void setBoard();
    Board getBoard();


    void simuleEt();

};

#endif