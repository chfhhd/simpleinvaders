#include "raylib.h"

#include "Player.h"

void Game::Player::ProcessInput() {
    if (IsKeyDown(KEY_LEFT)) this->pos.x -= (float) this->speed;
    if (IsKeyDown(KEY_RIGHT)) this->pos.x += (float) this->speed;
}
