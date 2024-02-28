#include <iostream>
#include "./raylib.h"

#include "./src/Player.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Roguémon");
    SetTargetFPS(60);

    Player player(Vector2(50, 50));
    player.setTexture(LoadTexture("./content/player.png"));

    Camera2D camera;
    camera.target = player.getPosition();
    camera.offset = (Vector2){screenWidth/2, screenHeight/2};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawText("This is some text", 20, 20, 20, BLACK);
        
        BeginMode2D(camera);
            Vector2 playerPos = player.getPosition();
            DrawTexture(player.getTexture(), playerPos.x, playerPos.y, WHITE);
        EndMode2D();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}