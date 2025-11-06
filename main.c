#include "include/raylib.h"
#include <stdio.h>

int main() {
	printf("hello cs class\n");

    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "cSnake");

    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) {   // Detect window close button or ESC key
        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) ballPosition.x += 2.0f;
        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) ballPosition.x -= 2.0f;
        if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) ballPosition.y -= 2.0f;
        if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) ballPosition.y += 2.0f;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("Move the snake with the arrow keys or with WASD", 10, 10, 15, DARKGRAY);

            DrawCircleV(ballPosition, 50, MAROON);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

	return 0;
}
