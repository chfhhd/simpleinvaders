#pragma once

#include "Sprite.h"
#include "Command.h"
#include "FireCommand.h"

namespace Game {
    class Player : public Sprite {
    private:

    public:
        using Sprite::Sprite;

        std::unique_ptr<FireCommand> fireCommand = nullptr;

        void ProcessInput();

        int lives = 3;
        int speed = 5;
    };
}
