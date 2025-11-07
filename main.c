#include "include/raylib.h"
#include <stdio.h>

#define DEBUG 0

typedef enum direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
} dir_t;

typedef struct food_s {
    Color   clr;
    int     prob;
    int     hp;
} food_t;

food_t foods[2] = {
    { RED, 5, 1 },      // apple
    { YELLOW, 10, 2 }   // banana
};

int main() {
    const int screenWidth = 640;
    const int screenHeight = 640;

    // snake vars
    dir_t snakeMove;
    int snakeLength;

    InitWindow(screenWidth, screenHeight, "cSnake");

    int recX = screenWidth / 2;
    int recY = screenHeight / 2;

    SetTargetFPS(30);

    while (!WindowShouldClose()) {
        // logic begin
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
                recY -= 10; // what in the devils is the reason for up being -Y and down being +Y????
                break;
            case DOWN:
                recY += 10;
                break;
        }

        if(recX > 640) {
            recX = 0;
        }
        if(recY > 640) {
            recY = 0;
        }
        if(recX < 0) {
            recX = 640;
        }
        if(recY < 0) {
            recY = 640;
        }
        #ifdef DEBUG 1
            printf("%i, ", recX);
            printf("%i\n", recY);
        #endif


        // logic end

        BeginDrawing();

            ClearBackground(BLACK);

            DrawRectangle(recX, recY, 50, 50, GREEN);

            DrawText("Move the snake with the arrow keys or with WASD", 10, 10, 15, RAYWHITE);

        EndDrawing();
    }

    CloseWindow();
	return 0;
}