#pragma once
#include "grid.hpp"

class Simulation {
public:
    Simulation(int width, int height, int cell_size)
        : grid(width, height, cell_size)
        , tmp_grid(width, height, cell_size)
        , run(false) {}
    void draw();
    void setCellValue(int row, int column, int value);
    int countLiveNeighbours(int row, int column);
    void update();
    bool is_running() { return run;}
    void start() {run = true;}
    void stop() {run = false;}
    void clear_grid();
    void create_random_state();
    void toggle_cell(int row, int column);
private:
    Grid grid;
    Grid tmp_grid;
    bool run;
};
