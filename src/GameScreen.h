#pragma once

#include <vector>
#include <memory>

#include "raylib.h"

#include "Screen.h"
#include "AlienShip.h"
#include "Player.h"
#include "Bullet.h"
#include "AlienShipController.h"

namespace Game {
    class GameScreen : public Screen {
    private:
        const int numberOfBullets = 100;

        Texture2D playerTexture{};
        Texture2D alienShipTexture{};
        Texture2D bulletTexture{};

        std::vector<std::shared_ptr<Game::AlienShip>> alienShips;
        std::unique_ptr<Game::AlienShipController> alienShipController;

        std::shared_ptr<Game::Player> player;

        std::vector<std::shared_ptr<Game::Bullet>> bullets;

        GameScreen();

        void LoadTextures();

        void InitPlayer();

        void InitBullets();

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
