#include "include/raylib.h"
#include <stdio.h>

typedef enum direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
 } dir_t;

int main() {
    const int screenWidth = 640;
    const int screenHeight = 640;

    dir_t snakeMove;

    InitWindow(screenWidth, screenHeight, "cSnake");

    int recX = screenWidth / 2;
    int recY = screenHeight / 2;

    SetTargetFPS(30);

    while (!WindowShouldClose()) {

        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) snakeMove = RIGHT;
        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) snakeMove = LEFT;
        if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) snakeMove = UP;
        if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) snakeMove = DOWN;

        switch(snakeMove) {
            case RIGHT:
                recX += 10;
                break;
            case LEFT:
                recX -= 10;
                break;
            case UP:
                recY -= 10;
                break;
            case DOWN:
                recY += 10;
                break;
        }

        if (recX >= 640) {
            recX = screenWidth / 2;
        }

        BeginDrawing();

            ClearBackground(BLACK);

            DrawRectangle(recX, recY, 50, 50, GREEN);

            DrawText("Move the snake with the arrow keys or with WASD", 10, 10, 15, RAYWHITE);

        EndDrawing();
    }

    CloseWindow();
	return 0;
}
