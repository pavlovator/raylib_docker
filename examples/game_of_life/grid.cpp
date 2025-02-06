#include "grid.hpp"
#include <raylib.h>

void Grid::draw() {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            Color color = cells[i][j] ? Color{0, 255, 0, 255} : Color{55, 55, 55, 255};
            DrawRectangle(cell_size*i, cell_size*j, cell_size-1, cell_size-1, color);
        }
    }
}

bool Grid::isInBounds(int row, int column) {
    if (row >= 0 && column >= 0 && row < rows && column < columns) { 
        return true;
    }
    return false;
}

void Grid::setValue(int row, int column, int value) {
   if (isInBounds(row, column)) {
        cells[row][column] = value;
    }
}

int Grid::getValue(int row, int column) {
    if (isInBounds(row, column)) {
        return cells[row][column];
    }
    return 0;
}


int Grid::getRows() {
    return rows;
}

int Grid::getColumns() {
    return columns;
}

void Grid::fill_random() {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            int random_value = GetRandomValue(1, 4);
            cells[i][j] = (random_value == 4) ? 1 : 0;
        }
    }
}

void Grid::clear() {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            cells[i][j] = 0;
        }
    }
}


void Grid::toggle_cell(int row, int column) {
    if (isInBounds(row, column)) {
        cells[row][column] = !cells[row][column];
    }
}
