#include <iostream>
#include "board.h"

void randomMine(int mines){
    
}

Board::Board(int row, int col){
    this->rows = row;
    this->cols = col;
    this->mines = (rows*cols/6); //Mayin sayisi hesaplandi

    cells = new Cell*[rows]; //Satirlari tutacak bir dizi olusturduk
    for (int i = 0; i < rows; i++)
    {
        cells[i] = new Cell[cols];
    }

    randomMine(mines);
}

Board::~Board(){
    for (int i = 0; i < this->rows; i++)
    {
        delete[] cells[i];  //Ilk sutunun tuttugu satir dizilerini siler
    }
    delete[] cells;  //Ilk sutun sizisini siler
}

void Board::DisplayBoard(){
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