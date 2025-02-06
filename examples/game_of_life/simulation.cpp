#include "simulation.hpp"
#include <vector>
#include <utility>

void Simulation::draw() {
    grid.draw();
}

void Simulation::setCellValue(int row, int column, int value) {
    grid.setValue(row, column, value);
}

int Simulation::countLiveNeighbours(int row, int column) {
    std::vector<std::pair<int, int>> offsets = 
    {
        {-1,-1},
        {-1, 0},
        {-1, 1},
        {0, -1},
        {0, 1},
        {1, -1},
        {1, 0},
        {1, 1}
    };

    int count = 0;
    for (const auto& offset : offsets) {
        int neighbour_row = (row + offset.first + grid.getRows()) % grid.getRows();
        int neighbour_column = (column + offset.second + grid.getColumns()) % grid.getColumns();
        count += grid.getValue(neighbour_row, neighbour_column);
    }
    return count;
}

void Simulation::update() {
    if (run == false) {
        return;
    }
    for (int i=0; i<grid.getRows(); i++) {
        for (int j=0; j<grid.getColumns(); j++) {
            int live_neighbours = countLiveNeighbours(i, j);
            int cell_value = grid.getValue(i, j);
            if (cell_value == 1) {
                if (live_neighbours < 2 || live_neighbours > 3) {
                    tmp_grid.setValue(i, j, 0);
                } else {
                    tmp_grid.setValue(i, j, 1);
                }
            } else {
                if (live_neighbours == 3) {
                    tmp_grid.setValue(i, j, 1);
                } else {
                    tmp_grid.setValue(i, j, 0);
                }
            }
        }
    }
    grid = tmp_grid;
}

void Simulation::clear_grid() {
    if (!is_running()) {
        grid.clear();
    }
}

void Simulation::create_random_state() {
    if (!is_running()) {
        grid.fill_random();
    }
}

void Simulation::toggle_cell(int row, int column) {
    if (!is_running()) {
        grid.toggle_cell(row, column);
    }
}
