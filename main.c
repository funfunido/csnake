#include "include/raylib.h"
#include <stdio.h>


int main() {
    const int screenWidth = 640;
    const int screenHeight = 640;

    InitWindow(screenWidth, screenHeight, "cSnake");

    int recX = screenWidth / 2;
    int recY = screenHeight / 2;

    SetTargetFPS(30);

    // Main game loop
    while (!WindowShouldClose()) {   // Detect window close button or ESC key
        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) recX += 2;
        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) recX -= 2;
        if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) recY -= 2;
        if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) recY += 2;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);

            DrawRectangle(recX, recY, 50, 50, GREEN);

            DrawText("Move the snake with the arrow keys or with WASD", 10, 10, 15, RAYWHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

	return 0;
}
