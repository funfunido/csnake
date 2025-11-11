#include "include/raylib.h"
#include <stdio.h>
#include <time.h>

// #define DEBUG 

typedef enum direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
} dir_t;

int main() {
    const int screenWidth = 640;
    const int screenHeight = 640;
    Color foodColor = RED;

    Rectangle player = {screenWidth / 2, screenHeight / 2, 32, 32};

    int randFoodValueX = GetRandomValue(0, screenWidth);
    int randFoodValueY = GetRandomValue(0, screenHeight);
    Rectangle food = {randFoodValueX, randFoodValueY, 32, 32};

    // snake vars
    dir_t snakeMove;
    int snakeLength;

    InitWindow(screenWidth, screenHeight, "cSnake");

    SetTargetFPS(30);

    while (!WindowShouldClose()) {
        // logic begin
        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) snakeMove = RIGHT;
        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) snakeMove = LEFT;
        if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) snakeMove = UP;
        if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) snakeMove = DOWN;

        switch(snakeMove) {
            case RIGHT:
                player.x += 10;
                break;
            case LEFT:
                player.x -= 10;
                break;
            case UP:
                player.y -= 10; // what in the devils is the reason for up being -Y and down being +Y????
                break;
            case DOWN:
                player.y += 10;
                break;
        }

        if (player.x > 640) {
            player.x = 0;
        }
        if (player.y > 640) {
            player.y = 0;
        }
        if (player.x < 0) {
            player.x = 640;
        }
        if (player.y < 0) {
            player.y = 640;
        }

        if(CheckCollisionRecs(player, food)) {
            player.width *= 1.5;
            switch (GetRandomValue(0, 3)) {
                case 0:
                    foodColor = RED; 
                    break;

                case 1:
                    foodColor = YELLOW; //change to hex-code
                    break;

                case 2:
                    foodColor = BROWN;
                    break;

                case 3:
                    foodColor = ORANGE;
                    break;
            }

            food.x = GetRandomValue(0, screenWidth);
            food.y = GetRandomValue(0, screenHeight);
        }

        #ifdef DEBUG
            printf("%i, ", player.x);
            printf("%i\n", player.y);
        #endif


        // logic end

        BeginDrawing();

            ClearBackground(BLACK);

            DrawRectangle(player.x, player.y, player.width, player.height, GREEN);

            DrawRectangle(food.x, food.y, 32, 32, foodColor);

            DrawText("Move the snake with the arrow keys or with WASD", 10, 10, 15, RAYWHITE);

        EndDrawing();
    }

    CloseWindow();
	return 0;
}
