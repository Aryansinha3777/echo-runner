#include "raylib.h"

int main() {
    InitWindow(800, 600, "Echo Runner");
    SetTargetFPS(60);

    Vector2 player = {400, 300};
    const float speed = 4.0f;

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) player.x += speed;
        if (IsKeyDown(KEY_LEFT)  || IsKeyDown(KEY_A)) player.x -= speed;
        if (IsKeyDown(KEY_DOWN)  || IsKeyDown(KEY_S)) player.y += speed;
        if (IsKeyDown(KEY_UP)    || IsKeyDown(KEY_W)) player.y -= speed;

        BeginDrawing();
        ClearBackground(DARKGRAY);
        DrawRectangleV(player, {32, 32}, SKYBLUE);
        DrawText("Echo Runner", 10, 10, 20, RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}