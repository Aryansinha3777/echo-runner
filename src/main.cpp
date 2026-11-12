#include "raylib.h"
#include <vector>

int main() {
    InitWindow(800, 600, "Echo Runner");
    SetTargetFPS(60);

    Vector2 player = {400, 300};
    const float speed = 4.0f;

    std::vector<Vector2> recording;   // positions of the current run
    std::vector<Vector2> ghostPath;   // positions of the saved run
    size_t ghostFrame = 0;
    bool ghostActive = false;

    while (!WindowShouldClose()) {
        // Move player
        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) player.x += speed;
        if (IsKeyDown(KEY_LEFT)  || IsKeyDown(KEY_A)) player.x -= speed;
        if (IsKeyDown(KEY_DOWN)  || IsKeyDown(KEY_S)) player.y += speed;
        if (IsKeyDown(KEY_UP)    || IsKeyDown(KEY_W)) player.y -= speed;

        // Record this frame
        recording.push_back(player);

        // R = save this run as the ghost and restart
        if (IsKeyPressed(KEY_R)) {
            ghostPath = recording;
            recording.clear();
            ghostFrame = 0;
            ghostActive = true;
            player = {400, 300};
        }

        // Advance ghost
        if (ghostActive && ghostFrame < ghostPath.size()) ghostFrame++;

        BeginDrawing();
        ClearBackground(DARKGRAY);
        if (ghostActive && ghostFrame > 0 && ghostFrame <= ghostPath.size())
            DrawRectangleV(ghostPath[ghostFrame - 1], {32, 32}, Fade(WHITE, 0.4f));
        DrawRectangleV(player, {32, 32}, SKYBLUE);
        DrawText("Move: WASD  |  R: save run as ghost", 10, 10, 20, RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}