#include "Bullet.h"

#include "FireCommand.h"

void FireCommand::execute(Game::Sprite* source) {
    for (const auto &bullet : this->bullets) {
        if (!bullet->active) {
            bullet->active = true;
            bullet->pos.x = source->pos.x + (float) source->texture.width / 2 - (float) bullet->texture.width / 2;
            bullet->direction = defaultBulletDirection;

            if (bullet->direction.y > 0)
                bullet->pos.y = source->pos.y + source->texture.height;
            else
                bullet->pos.y = source->pos.y;
            return;
        }
    }
}
