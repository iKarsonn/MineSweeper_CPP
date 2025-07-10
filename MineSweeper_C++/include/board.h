#ifndef BOARD_H
#define BOARD_H
#include "cell.h"

class Board {

private:
    
    int rows;     //Satir sayisi
    int cols;     //Sutun sayisi
    int mines;    //Mayin sayisi
    Cell** cells; //Mayin tarlamizin ilk sutun dizisini tutan pointer

    void randomMine();  //Tarlamiza mayinlari rastgele atayacak olan method

public:
    
    Board(int, int);
    ~Board();

    bool shoot(int, int); //Girilen satir ve sutunda mayin yoksa hucrenin durumu guncellenecek
    void flag(int, int);

    void displayBoard();

};

#endif