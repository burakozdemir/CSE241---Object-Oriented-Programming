//
// Created by burki on 23.11.2017.
//

#ifndef HW5_CELL_H
#define HW5_CELL_H
#include <fstream>
#include <iostream>
using namespace std;

namespace  ConnectSpace {
    class Cell {
    public:
        Cell();

        Cell(char content, int row, int col, int cellcontent);

        inline char getContent() const { return content; }

        inline int getCol() const { return col; }

        inline int getRow() const { return row; }

        inline int getCellContent() const { return cellContent; }

        void setCellContent(int value) { cellContent = value; }

        void setContent(char value) { content = value; }

        void setCol(int value) { col = value; }

        void setRow(int value) { row = value; }
    private:
        char content;
        int col;
        int row;
        int cellContent;
    };

}

#endif //HW5_CELL_H
