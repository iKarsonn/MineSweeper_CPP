#ifndef CELL_H
#define CELL_H

class Cell {

private:
    bool hasMine;
    bool isOpened;
    bool isFlagged;

public:
    Cell();
    ~Cell();

    void setHasMine(bool);
    void setIsOpened(bool);
    void setIsFlagged(bool);

    bool getHasMine();
    bool getIsOpened();
    bool getIsFlagged();
};

#endif
