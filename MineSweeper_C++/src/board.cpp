#include <iostream>
#include <cstdlib>
#include "board.h"

void Board::randomMine(){ //Girilen mayin sayisina gore mayin tarlamizi olusturan metod
    int row, col;
    for (int i = 0; i < this->mines; i++)
    {
        
    }
    
}

Board::Board(int row, int col){
    this->rows = row;
    this->cols = col;
    this->mines = (rows*cols/6); //Mayin sayisi hesaplandi (Hucre sayisinin 1/6sı kadar)

    cells = new Cell*[rows]; //Satirlari tutacak bir dizi olusturduk
    for (int i = 0; i < rows; i++)
    {
        cells[i] = new Cell[cols];
    }

    randomMine();
}

Board::~Board(){
    for (int i = 0; i < this->rows; i++)
    {
        delete[] cells[i];  //Ilk sutunun tuttugu satir dizilerini siler
    }
    delete[] cells;  //Ilk sutun dizisini siler
}

bool Board::shoot(int row, int col){  //Girilen hücre bilgileri tahtada mevcut mu
    if (row < 0 || row > this->rows-1 || col < 0 || col > this->cols-1)
    {
        return false; //Mevcut degil ise metodu sonlandir
    } 
    
    this->cells[row][col].setIsOpened(true); //Mevcut ise hücrenin durumunu acildi yap

    if (this->cells[row][col].getHasMine() == true) //Acilan hücrede mayin var ise true döndür
    {
        return true;
    }
    return false;

}

void Board::flag(int row, int col){
    if (row < 0 || row > this->rows-1 || col < 0 || col > this->cols-1)
        return; //Mevcut degil ise metodu sonlandir
    
    this->cells[row][col].setIsFlagged(!this->cells[row][col].getIsFlagged()); //Hucrenin durumunu tersle
    
}

void Board::displayBoard(){
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            if (cells[i][j].getHasMine() == true)
            {
                std::cout << "1 ";
            }
            else if(cells[i][j].getHasMine() == false){
                std::cout << "0 ";
            }
        }
        std::cout << std::endl;
    }
    
}