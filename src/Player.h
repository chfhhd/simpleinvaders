#pragma once

#include "Sprite.h"
#include "Command.h"
#include "FireCommand.h"

namespace Game {
    struct Player : public Sprite {
    public:
        using Sprite::Sprite;

        std::unique_ptr<FireCommand> fireCommand = nullptr;

        int lives = 3;
        int speed = 5;

        void ProcessInput();
    };
}
