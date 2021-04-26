#pragma once

#include <vector>
#include <memory>

#include "raylib.h"

#include "Screen.h"
#include "AlienShip.h"
#include "Player.h"
#include "AlienShipController.h"

namespace Game {
    class GameScreen : public Screen {
    private:
        Texture2D playerTexture{};
        Texture2D alienShipTexture{};

        std::vector<std::shared_ptr<Game::AlienShip>> alienShips;
        std::unique_ptr<Game::AlienShipController> alienShipController;

        std::shared_ptr<Game::Player> player;

        GameScreen();

    public:
        static Screen *getInstance() {
            static GameScreen instance;
            return &instance;
        }

        GameScreen(GameScreen const &) = delete;

        void operator=(GameScreen const &) = delete;

        ~GameScreen();

        void ProcessInput() override;

        void Update() override;

        void Draw() override;
    };
}
