#pragma once
#include <raylib.h>
#include <vector>

class Grid {
public:
    Grid(int height, int width, int cell_size)
        : rows(height/cell_size)
        , columns(width/cell_size)
        , cell_size(cell_size)
        , cells(rows, std::vector<int>(columns, 0)) {};

    void draw();
    bool isInBounds(int row, int column);
    void setValue(int row, int column, int value);
    int getValue(int row, int column);
    int getRows();
    int getColumns();
    void fill_random();
    void clear();
    void toggle_cell(int row, int column);
private:
    int rows;
    int columns;
    int cell_size;
    std::vector<std::vector<int>> cells;

};
