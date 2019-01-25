//
// Created by burki on 23.11.2017.
//

#include "Cell.h"

namespace ConnectSpace {
    Cell::Cell() : col(0), row(0), content('*'), cellContent(0) {
    }

    Cell::Cell(char content, int row, int col, int cellcontent) :
            content(content), row(row), col(col), cellContent(cellcontent) {

    }

}
