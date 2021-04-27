#pragma once

#include <vector>
#include <memory>

#include "Command.h"
#include "Bullet.h"

class FireCommand : public Command {
public:
    explicit FireCommand(std::vector<std::shared_ptr<Game::Bullet>> &bullets, Vector2 defaultBulletDirection) : bullets(bullets),
                                                                                                                defaultBulletDirection(defaultBulletDirection) {}

    void execute(Game::Sprite* source) override;

private:
    std::vector<std::shared_ptr<Game::Bullet>> &bullets;
    Vector2 defaultBulletDirection = {0.0, 0.0};
};