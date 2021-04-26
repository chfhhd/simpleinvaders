#include "game.h"

#include "Bullet.h"

bool Game::Bullet::IsOutOfScreen() {
    if (this->pos.y<0 || this->pos.y>(float) Game::ScreenHeight || this->pos.x<0 || this->pos.y>(float)
    ScreenWidth)
    return true;

    return false;
}

void Game::Bullet::move() {
    if (IsOutOfScreen()) {
        active = false;
    }

    if (direction.y > 0)
        pos.y = (pos.y + direction.y + speed);
    else
        pos.y = (pos.y - direction.y - speed);
}
