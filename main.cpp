#include <iostream>
#include <cmath>
#include "./raylib.h"

#include "./src/util.h"
#include "./src/Player.h"
#include "./src/Item.h"
#include "./src/Enemy.h"
#include "./src/Creature.h"

void combatLoop(Player& player, Enemy& enemy) {
    bool displayAbilities = true;
    bool displayItems = false;
    
    while (true) {
        if (IsKeyPressed(KEY_SPACE)) {
            return;
        }

        BeginDrawing();
        ClearBackground(WHITE);

        DrawTexture(player.texture, 100, 400, WHITE);
        DrawTexture(enemy.texture, 700, 100, WHITE);
        DrawText("BATTLE!!!", 350, 30, 20, BLACK);
        
        DrawRectangle(0, 500, 800, 100, GRAY);
        DrawText("Abilities", 50, 520, 20, WHITE);
        DrawText("Items", 50, 560, 20, WHITE);

        DrawText("Ability 1", 350, 520, 20, WHITE);
        DrawText("Ability 2", 350, 560, 20, WHITE);
        DrawText("Ability 3", 500, 520, 20, WHITE);
        DrawText("Ability 4", 500, 560, 20, WHITE);

        EndDrawing();
    }
}

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    const int agroRange = 250;

    InitWindow(screenWidth, screenHeight, "Roguémon");
    SetTargetFPS(60);

    Player player = {50.0f, 50.0f};
    player.texture = SetTexture("./content/player.png", 64, 64);

    std::vector<Enemy> enemies;
    Enemy testEnemy = {250.f, 250.f};
    testEnemy.texture = SetTexture("./content/test.png", 64, 64);
    enemies.push_back(testEnemy);

    // Define camera
    Camera2D camera;
    camera.target = player.position;
    camera.offset = (Vector2){screenWidth/2, screenHeight/2};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    char positionText[100]; // This is probably bad

    // Create ESC menu for settings
    bool showEscMenu = false;
    Texture2D EscMenuBackground = SetTexture("./content/default_menu.png", 128, 256);
    Rectangle QuitRect = {screenWidth - 150, 230, 9*20, 20};

    while (!WindowShouldClose()) {
        Vector2 mpos = GetMousePosition();

        // Get player input and update camera position
        player.move();
        Vector2 playerPos = player.position;
        camera.target = playerPos;

        for (int i = 0; i < enemies.size(); i++) {
            Enemy e = enemies[i];
            if (getDist(e.position, player.position) <= agroRange) {
                std::cout << "Enemy Engaged!" << std::endl;
                combatLoop(player, e);
                enemies.erase(enemies.begin() + i);
            }
        }

        if (IsKeyPressed(KEY_TAB)) {
            showEscMenu = !showEscMenu;
        }

        // Start drawing
        BeginDrawing();
        ClearBackground(WHITE); // Clear screen

        // Draw relative to the camera
        // Aka non-UI elements
        BeginMode2D(camera);
            player.Draw();
            testEnemy.Draw(); // Change this 
        EndMode2D();

        DrawFPS(0,0);                                                           // Draw FPS
        sprintf(positionText, "X: %.0f, Y: %.0f", playerPos.x, playerPos.y);    // Player coordinates
        DrawText(positionText, 10, screenHeight - 30, 20, BLACK);               // Draw coordinates 

        if (showEscMenu) {
            DrawTexture(EscMenuBackground, screenWidth - 160, 25, WHITE);
            DrawText("Settings", screenWidth - 150, 35, 20, WHITE);
            DrawText("Quit Game", screenWidth - 150, 230, 20, WHITE);

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                if (CheckCollisionPointRec(mpos, QuitRect)) {
                    CloseWindow();
                    return 0;
                }
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
