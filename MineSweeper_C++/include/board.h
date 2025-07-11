#ifndef BOARD_H
#define BOARD_H
#include "cell.h"

class Board {

private:
    
    int rows;     //Satir sayisi
    int cols;     //Sutun sayisi
    int mines;    //Mayin sayisi
    int openedCells; //Acilmis hucre sayisi
    Cell** cells; //Mayin tarlamizin ilk sutun dizisini tutan pointer

    void randomMine();  //Tarlamiza mayinlari rastgele atayacak olan method

public:
    
    Board(int, int);
    ~Board();

    bool shoot(int, int); //Girilen satir ve sutunda mayin yoksa hucrenin durumu guncellenecek
    void flag(int, int);  //Bayrak koyma methodu
    void calculateSurroundingMines();  //Bir hucrenin cevresindeki hucrelerde bulunan mayin sayisini hesaplayan method


    void displayBoard();

    void setRows(int);
    void setCols(int);
    void setMines(int);
    void uploadOpenedCells();  //Acilmis hücre sayisini guncelleyen method
    int getRows();
    int getCols();
    int getMines();
    int getOpenedCells();

};

#endif