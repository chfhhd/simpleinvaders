#include "raylib.h"

#include "game.h"
#include "config.h"
#include "Player.h"

void Game::Player::ProcessInput() {
    if (IsKeyDown(KEY_LEFT)) {
        if(pos.x >= 0)
            pos.x -= (float) this->speed;
    }
    if (IsKeyDown(KEY_RIGHT)) {
        if(pos.x <= (float) Game::ScreenWidth - (float) texture.width)
            pos.x += (float) this->speed;
    }

    if(IsKeyPressed(KEY_SPACE))
        if(fireCommand)
            fireCommand->execute(this);
}
