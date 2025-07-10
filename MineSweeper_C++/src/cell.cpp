#include "cell.h"
    
Cell::Cell(){
    this->hasMine = false;
    this->isOpened = false;
    this->isFlagged = false;
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


bool Cell::getHasMine(){
    return this->hasMine;
}

bool Cell::getIsOpened(){
    return this->isOpened;
}

bool Cell::getIsFlagged(){
    return this->isFlagged;
}