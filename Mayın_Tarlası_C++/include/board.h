#ifndef BOARD_H
#define BOARD_H
#include "cell.h"

class Board {

private:
    
    int rows;     //Satir sayisi
    int cols;     //Sutun sayisi
    int mines;    //Mayin sayisi
    Cell** cells; //Mayin tarlamizin ilk sutun dizisini tutan pointer

    void randomMine(int);

public:
    
    Board(int, int);
    ~Board();

    void DisplayBoard();

};

#endif