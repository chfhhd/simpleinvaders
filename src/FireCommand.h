#pragma once

#include <vector>

#include "Command.h"
#include "Bullet.h"

class FireCommand : public Command {
public:
    explicit FireCommand(std::vector<std::shared_ptr<Game::Bullet>> &bullets) : bullets(bullets) {}

    void execute(Game::Sprite* sprite) override;

private:
    std::vector<std::shared_ptr<Game::Bullet>> &bullets;
};