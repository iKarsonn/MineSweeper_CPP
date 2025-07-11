#include "cell.h"
    
Cell::Cell(){
    this->hasMine = false;
    this->isOpened = false;
    this->isFlagged = false;
    this->surroundingMines = 0;
}
    
Cell::~Cell(){
    //Nesne silinirken yapilacak bir islem olmadigindan bos kalacak
}

void Cell::setHasMine(bool boolean){
    this->hasMine = boolean;
}

void Cell::setIsOpened(bool boolean){
    this->isOpened = boolean;
}

void Cell::setIsFlagged(bool boolean){
    this->isFlagged = boolean;
}

void Cell::setSurroundingMines(int surroundingMines){
    this->surroundingMines = surroundingMines;
}

bool Cell::getHasMine(){
    return this->hasMine;
}

bool Cell::getIsOpened(){
    return this->isOpened;
}

bool Cell::getIsFlagged(){
    return this->isFlagged;
}

int Cell::getSurroundingMines(){
    return this->surroundingMines;
}