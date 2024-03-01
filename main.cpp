#include <iostream>
#include <cmath>
#include "./raylib.h"

#include "./src/util.h"
#include "./src/Player.h"
#include "./src/Item.h"
#include "./src/Enemy.h"
#include "./src/Creature.h"
#include "./src/Menu.h"
#include "./src/Button.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Roguémon");
    SetTargetFPS(60);

    Player player = {50.0f, 50.0f};
    player.texture = SetTexture("./content/player.png");

    Enemy testEnemy = {250.f, 250.f};
    testEnemy.texture = SetTexture("./content/test.png");

    Camera2D camera;
    camera.target = player.position;
    camera.offset = (Vector2){screenWidth/2, screenHeight/2};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    char positionText[100]; // This is probably bad

    bool showEscMenu = false;
    Menu EscMenu;
    EscMenu.position = (Vector2){screenWidth-150, 20};
    EscMenu.width = 75;
    EscMenu.height = 175;
    
    Button ReturnButton;

    while (!WindowShouldClose()) {
        player.move();
        Vector2 playerPos = player.position;
        camera.target = playerPos;

        if (IsKeyPressed(KEY_ESCAPE)) {
            showEscMenu = !showEscMenu;
        }

        BeginDrawing();
        ClearBackground(WHITE);
        DrawFPS(0,0);
        
        sprintf(positionText, "X: %.0f, Y: %.0f", playerPos.x, playerPos.y);
        DrawText(positionText, 10, screenHeight - 30, 20, BLACK);

        if (showEscMenu) {
            EscMenu.Draw();
            EscMenu.checkButtons();
        }

        BeginMode2D(camera);
            player.Draw();
            testEnemy.Draw();
            DrawRectangle(300, 20, 50, 50, RED);
        EndMode2D();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
