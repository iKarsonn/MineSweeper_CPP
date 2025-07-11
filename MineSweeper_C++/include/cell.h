#ifndef CELL_H
#define CELL_H

class Cell {

private:
    bool hasMine;  //Hucredeki mayin bilgisini tutan degisken
    bool isOpened;  //Hucrenin acik mi kapali mi oldugu bilgisini tutan degisken
    bool isFlagged;  //Hucrenin bayrakli mi bayraksiz mi oldugu bilgisini tutan degisken
    int surroundingMines;  //Bir hucrenin cevresindeki hucrelerde bulunan mayin sayisini tutan degisken

public:
    Cell();
    ~Cell();

    void setHasMine(bool);
    void setIsOpened(bool);
    void setIsFlagged(bool);
    void setSurroundingMines(int);

    bool getHasMine();
    bool getIsOpened();
    bool getIsFlagged();
    int getSurroundingMines();
};

#endif
