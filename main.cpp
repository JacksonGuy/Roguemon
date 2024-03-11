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

#include "./src/Items/ArmorPad.h"

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

std::vector<Item*> passiveItemPool;

void combatWin(Player& player) {
    player.xp += 5;
    if (player.xp >= player.nextLevelXp) {
        int remainder = player.nextLevelXp - player.xp;
        player.xp = remainder;
        player.levelUp();
    }

    // TODO probably a memory leak here or something
    // Also just terrible code in general
    int itemDrop = rand() % passiveItemPool.size();
    Item* prefab = passiveItemPool[itemDrop];
    if (prefab->name == "Armor Pad") {
        ArmorPad* ref = (ArmorPad*)prefab;
        ArmorPad* newItem = new ArmorPad(ref);
        newItem->texture = SetTexture("./src/Items/textures/testArmor.png", 64, 64);
        player.addItem(newItem);
    }       
}

void combatLoop(Player& player, Enemy& enemy) {
    bool displayAbilities = true;
    bool displayItems = false;
    bool playerTurn = true;
    bool combatOver = false;
    bool victory = false;

    Button abl1((Vector2){350, 520}, player.abilities[0].c_str());
    Button abl2((Vector2){350, 560}, player.abilities[1].c_str());
    Button abl3((Vector2){500, 520}, player.abilities[2].c_str());
    Button abl4((Vector2){500, 560}, player.abilities[3].c_str());

    Button combatButtons[] = {abl1, abl2, abl3, abl4};
    
    char playerHealth[256];
    char enemyHealth[256];
    char victoryText[256];

    Item* newItem;

    while (true) {
        if (IsKeyPressed(KEY_ENTER) && combatOver) {
            return;
        }

        if (!playerTurn && !enemy.IsDead()) {
            enemy.CalculateEffects();

            if (enemy.IsDead()) {
                combatWin(player);
                combatOver = true;
                victory = true;
            } else {
                std::string choice = enemy.combatAI(player);
                std::cout << "Enemy used: " << choice << std::endl; 
                abilities[choice](enemy, player);

                // TODO Do something else here in the future
                if (player.IsDead()) {
                    std::cout << "You Died!" << std::endl;
                    //combatOver = true;
                    exit(0);
                }

                player.CalculateEffects();

                // TODO
                if (player.IsDead()) {
                    std::cout << "You Died!" << std::endl;
                    //combatOver = true;
                    exit(0);
                }

                playerTurn = true;
            }
        }

        Vector2 mpos = GetMousePosition();
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && playerTurn && !combatOver) {
            for (Button abl : combatButtons) {
                if (CheckCollisionPointRec(mpos, abl.rect)) {
                    abilities[abl.text](player, enemy);
                    playerTurn = false;
                    
                    if (enemy.IsDead()) {
                        combatWin(player);
                        combatOver = true;
                        victory = true;
                    }
                }
            }
        }

        BeginDrawing();
        ClearBackground(WHITE);
            DrawRectangle(0, 500, 800, 100, GRAY); // Bottom Menu Bar

            if (combatOver) {
                if (victory) {
                    newItem = player.items[player.items.size()-1]; 
                    DrawText("VICTORY!!!", 350, 30, 20, BLACK);
                    sprintf(victoryText, "You Win! You gained an item: %s", newItem->name.c_str());
                    DrawText(victoryText, 100, 540, 20, WHITE);
                    DrawText("Press enter to continue...", 100, 570, 20, WHITE);
                    DrawTexture(newItem->texture, 700, 100, WHITE);
                } else {
                    DrawText("DEFEAT!!!", 350, 30, 20, BLACK);
                    DrawText("Press enter to exit...", 100, 570, 20, WHITE);
                }
            } else {
                DrawText("BATTLE!!!", 350, 30, 20, BLACK);
                DrawTexture(enemy.texture, 700, 100, WHITE);
                DrawText(enemyHealth, 700, 80, 20, BLACK);
                sprintf(enemyHealth, "HP: %d/%d", enemy.health, enemy.maxHealth);

                DrawText("Abilities", 50, 520, 20, WHITE);
                DrawText("Items", 50, 560, 20, WHITE);
                abl1.Draw();
                abl2.Draw();
                abl3.Draw();
                abl4.Draw();
            }

            DrawTexture(player.texture, 100, 400, WHITE);

            sprintf(playerHealth, "HP: %d/%d", player.health, player.maxHealth);
            DrawText(playerHealth, 100, 380, 20, BLACK);

        EndDrawing();
    }
}

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    const int agroRange = 250;

    srand(time(0)); // Random number generator seed
                    // Only call this once

    InitWindow(screenWidth, screenHeight, "Roguémon");
    SetTargetFPS(60);
    SetExitKey(KEY_NULL);

    passiveItemPool.push_back(new ArmorPad);

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

    char positionText[256];
    char healthText[256];
    char xpText[256];

    // Create ESC menu for settings
    bool showEscMenu = false;
    Texture2D EscMenuBackground = SetTexture("./content/default_menu.png", 128, 256);
    Button QuitButton((Vector2){screenWidth - 150, 230}, "Quit Game");

    bool showInventory = false;
    Texture2D InventoryBackground = SetTexture("./content/default_menu.png", 256, 512);

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

        if (IsKeyPressed(KEY_ESCAPE)) {
            showEscMenu = !showEscMenu;
        }

        if (IsKeyPressed(KEY_I)) {
            showInventory = !showInventory;
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

        sprintf(xpText, "XP: %d/%d", player.xp, player.nextLevelXp);
        DrawText(xpText, 10, 60, 20, BLACK);

        if (showEscMenu) {
            DrawTexture(EscMenuBackground, screenWidth - 160, 25, WHITE);
            DrawText("Settings", screenWidth - 150, 35, 20, WHITE);
            QuitButton.Draw();

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                if (CheckCollisionPointRec(mpos, QuitButton.rect)) {
                    CloseWindow();
                    return 0;
                }
            }
        }

        if (showInventory) {
            DrawTexture(InventoryBackground, screenWidth - 266, 25, WHITE);
            DrawText("Inventory", screenWidth - 256, 35, 20, WHITE);
        
            int ypos = 55;
            for (Item* item : player.inventory) {
                DrawText(item->name.c_str(), screenWidth - 256, ypos, 20, WHITE);
                ypos += 20;
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
