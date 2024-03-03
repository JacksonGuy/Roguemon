#include <iostream>
#include <cmath>
#include <functional>
#include "./raylib.h"

#include "./src/util.h"
#include "./src/Player.h"
#include "./src/Item.h"
#include "./src/Enemy.h"
#include "./src/Creature.h"
#include "./src/testAbilities.h"
#include "./src/Button.h"

std::vector<std::string> abilityPool = {
    "Test 1",
    "Test 2",
    "Test 3",
    "Test 4"
};

typedef std::map<std::string, std::function<void(Creature&, Creature&)>> FunctionMap;

FunctionMap abilities = {
    {"Test 1", test1},
    {"Test 2", test2},
    {"Test 3", test3},
    {"Test 4", test4}
};

void combatLoop(Player& player, Enemy& enemy) {
    bool displayAbilities = true;
    bool displayItems = false;
    bool playerTurn = true;

    Button abl1((Vector2){350, 520}, player.abilities[0].c_str());
    Button abl2((Vector2){350, 560}, player.abilities[1].c_str());
    Button abl3((Vector2){500, 520}, player.abilities[2].c_str());
    Button abl4((Vector2){500, 560}, player.abilities[3].c_str());

    Button combatButtons[] = {abl1, abl2, abl3, abl4};
    
    char playerHealth[100];
    char enemyHealth[100];

    while (true) {
        if (IsKeyPressed(KEY_SPACE)) {
            return;
        }

        if (!playerTurn) {
            std::string choice = enemy.combatAI(player);
            std::cout << "Enemy used: " << choice << std::endl; 
            abilities[choice](enemy, player);

            // TODO Do something else here in the future
            if (player.IsDead()) {
                std::cout << "You Died!" << std::endl;
                exit(0);
            }

            playerTurn = true;
        }

        Vector2 mpos = GetMousePosition();
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && playerTurn) {
            // Some high quality code here
            for (Button abl : combatButtons) {
                if (CheckCollisionPointRec(mpos, abl.rect)) {
                    abilities[abl.text](player, enemy);
                    playerTurn = false;
                    if (enemy.IsDead()) {
                        // TODO things after enemy killed
                        return;
                    }
                }
            }
        }

        BeginDrawing();
        ClearBackground(WHITE);

            DrawTexture(player.texture, 100, 400, WHITE);
            DrawTexture(enemy.texture, 700, 100, WHITE);
            DrawText("BATTLE!!!", 350, 30, 20, BLACK);

            sprintf(playerHealth, "HP: %d/%d", player.health, player.maxHealth);
            sprintf(enemyHealth, "HP: %d/%d", enemy.health, enemy.maxHealth);
            DrawText(playerHealth, 100, 380, 20, BLACK);
            DrawText(enemyHealth, 700, 80, 20, BLACK);

            DrawRectangle(0, 500, 800, 100, GRAY);
            DrawText("Abilities", 50, 520, 20, WHITE);
            DrawText("Items", 50, 560, 20, WHITE);

            abl1.Draw();
            abl2.Draw();
            abl3.Draw();
            abl4.Draw();

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
    player.GetRandomAbilities(abilityPool);

    std::vector<Enemy> enemies;
    Enemy testEnemy = {250.f, 250.f};
    testEnemy.texture = SetTexture("./content/test.png", 64, 64);
    testEnemy.GetRandomAbilities(abilityPool);
    enemies.push_back(testEnemy);

    // Define camera
    Camera2D camera;
    camera.target = player.position;
    camera.offset = (Vector2){screenWidth/2, screenHeight/2};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    char positionText[100]; // This is probably bad
    char healthText[100];

    // Create ESC menu for settings
    bool showEscMenu = false;
    Texture2D EscMenuBackground = SetTexture("./content/default_menu.png", 128, 256);
    //Rectangle QuitRect = {screenWidth - 150, 230, 9*20, 20};
    Button QuitButton((Vector2){screenWidth - 150, 230}, "Quit Game");

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
            for (Enemy e : enemies) {
                e.Draw();
            } 
        EndMode2D();

        DrawFPS(0,0);                                                           // Draw FPS
        sprintf(positionText, "X: %.0f, Y: %.0f", playerPos.x, playerPos.y);    // Player coordinates
        DrawText(positionText, 10, screenHeight - 30, 20, BLACK);               // Draw coordinates 
        
        sprintf(healthText, "HP: %d/%d", player.health, player.maxHealth);
        DrawText(healthText, 10, 30, 20, BLACK);

        if (showEscMenu) {
            DrawTexture(EscMenuBackground, screenWidth - 160, 25, WHITE);
            DrawText("Settings", screenWidth - 150, 35, 20, WHITE);
            //DrawText("Quit Game", screenWidth - 150, 230, 20, WHITE);
            QuitButton.Draw();

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                if (CheckCollisionPointRec(mpos, QuitButton.rect)) {
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
