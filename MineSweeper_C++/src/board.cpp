#include <iostream>
#include <cstdlib>
#include "board.h"

void Board::randomMine(){ //Girilen mayin sayisina gore mayin tarlamizi olusturan metod
    srand(time(0));

    int row, col;
    for (int i = 0; i < this->mines;)
    {
        row = rand() % this->rows;
        col = rand() % this->cols;

        if (!this->cells[row][col].getHasMine())
        {
            this->cells[row][col].setHasMine(true);
            i++;
        }
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
    calculateSurroundingMines();
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
        return false; //Mevcut degil ise metodu sonlandir
    
    if (this->cells[row][col].getIsOpened())  //Hucre acilmissa bisey yapma
        return false;
    
    this->cells[row][col].setIsOpened(true);  //Hucreyi ac
    
    if (this->cells[row][col].getHasMine())  //Mayin var ise oyunu bitir
        return true;
    
    if (this->cells[row][col].getSurroundingMines() == 0)  //Cevredeki hucreleri ac
    {
        shoot(row - 1, col - 1);
        shoot(row, col - 1);
        shoot(row + 1, col - 1);
        shoot(row - 1, col);
        shoot(row + 1, col);
        shoot(row - 1, col + 1);
        shoot(row, col + 1);
        shoot(row + 1, col + 1);
    }

    return false;
    
}

void Board::flag(int row, int col){
    if (row < 0 || row > this->rows-1 || col < 0 || col > this->cols-1)
        return; //Mevcut degil ise metodu sonlandir
    
    this->cells[row][col].setIsFlagged(!this->cells[row][col].getIsFlagged()); //Hucrenin durumunu tersle
    
}

void Board::calculateSurroundingMines(){
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int count = 0;  //Cevredeki mayin sayisini tutan gecici degisken


            //Cevredeki hucleler tarla sinirleri icinde ise ve mayin mevcutsa kontrolu
            if (i-1 >= 0 && j-1 >= 0 && cells[i-1][j-1].getHasMine()) count++;
            if (i-1 >= 0 && cells[i-1][j].getHasMine()) count++;
            if (i-1 >= 0 && j+1 < cols && cells[i-1][j+1].getHasMine()) count++;
            if (j-1 >= 0 && cells[i][j-1].getHasMine()) count++;
            if (j+1 < cols && cells[i][j+1].getHasMine()) count++;
            if (i+1 < rows && j-1 >= 0 && cells[i+1][j-1].getHasMine()) count++;
            if (i+1 < rows && cells[i+1][j].getHasMine()) count++;
            if (i+1 < rows && j+1 < cols && cells[i+1][j+1].getHasMine()) count++;

            this->cells[i][j].setSurroundingMines(count);  //En son bulunan mayin sayisi hucrenin degiskenine ataniyor
        }
    }
    
    
}

void Board::displayBoard(){
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            if (!this->cells[i][j].getIsOpened())  //Hucre acilmadi ise
            {
                if (this->cells[i][j].getIsFlagged())  //Bayrakli ise
                {
                    std::cout << "F" << " ";   
                }
                else {
                    std::cout << "*" << " ";  //Bayraksiz ise
                }   
            }
            else {
                if (!this->cells[i][j].getHasMine()) {   
                    std::cout << this->cells[i][j].getSurroundingMines() << " ";
                }
                else {
                    std::cout << "M" << " "; 
                }
            }
        }
        std::cout << std::endl;
    }
    
}

void Board::setRows(int row){
    this->rows = row;
}

void Board::setCols(int col){
    this->cols = col;
}

void Board::setMines(int mine){
    this->mines = mine;
}

void Board::uploadOpenedCells(){
    int openedCells = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (this->cells[i][j].getIsOpened()) //Hucre acilmis ise
            {
                openedCells += 1;
            }
        }
    }
    this->openedCells = openedCells;
}

int Board::getRows(){
    return this->rows;
}

int Board::getCols(){
    return this->cols;
}

int Board::getMines(){
    return this->mines;
}

int Board::getOpenedCells(){
    return this->openedCells;
}