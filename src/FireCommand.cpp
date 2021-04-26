#include "Bullet.h"

#include "FireCommand.h"

void FireCommand::execute(Game::Sprite* sprite) {
    for (const auto &bullet : this->bullets) {
        if (!bullet->active) {
            bullet->active = true;
            bullet->pos.x = sprite->pos.x + (float) sprite->texture.width/2 - (float) bullet->texture.width/2;
            bullet->pos.y = sprite->pos.y;
            return;
        }
    }
}
