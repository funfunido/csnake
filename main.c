#include "include/raylib.h"
#include <stdio.h>

int main() {
	printf("hello cs class\n");

    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 740;
    const int screenHeight = 740;

    InitWindow(screenWidth, screenHeight, "cSnake");

    //Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };

    int recX = screenWidth / 2;
    int recY = screenHeight / 2;

    Image bg = LoadImage("img/grid.png");
    Texture2D bgtexture = LoadTextureFromImage(bg); 
    UnloadImage(bg);

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) {   // Detect window close button or ESC key
        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) recX += 2.0f;
        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) recX -= 2.0f;
        if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) recY -= 2.0f;
        if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) recY += 2.0f;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawTexture(bgtexture, screenWidth, screenHeight, WHITE);

            //DrawCircleV(ballPosition, 50, MAROON);
            DrawRectangle(recX, recY, 50, 50, GREEN);

            DrawText("Move the snake with the arrow keys or with WASD", 10, 10, 15, DARKGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

	return 0;
}
