// Code taken from https://github.com/educ8s/CPP-Game-Of-Life-with-raylib

#include <raylib.h>
#include "simulation.hpp"

int main() {
    Color GREY = {29, 29, 29, 255};
    const int WINDOW_WIDTH = 1000;
    const int WINDOW_HEIGHT = 1000;
    const int CELL_SIZE = 5;
    int FPS = 12;
    Simulation simulation(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(FPS);
    // Simulation Loop
    while (!WindowShouldClose()) {
        // 1. Event Handling
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            Vector2 mouse_position = GetMousePosition();
            int row = mouse_position.x / CELL_SIZE;
            int column = mouse_position.y / CELL_SIZE;
            simulation.toggle_cell(row, column);
        }

        if (IsKeyPressed(KEY_ENTER)) {
            simulation.start();
            SetWindowTitle("Game of Life is running.");
        } else if (IsKeyPressed(KEY_SPACE)) {
            simulation.stop();
            SetWindowTitle("Game of Life has stopped.");
        } else if (IsKeyPressed(KEY_F)) {
            FPS += 2;
            SetTargetFPS(FPS);
        } else if (IsKeyPressed(KEY_S)) {
            if (FPS > 5) {
                FPS -= 2;
                SetTargetFPS(FPS);
            }
        } else if (IsKeyPressed(KEY_R)) {
            simulation.create_random_state();
        } else if (IsKeyPressed(KEY_C)) {
            simulation.clear_grid();
        }

        // 2. Updating State
        simulation.update();
        
        // 3. Drawing Objects
        BeginDrawing();
	    ClearBackground(GREY);
        simulation.draw();
    
        DrawText(TextFormat("Target FPS: %i \nCurrent FPS: %i", FPS, GetFPS()), 20, 20, 30, RED);
        EndDrawing();
    }    

    CloseWindow();
}
