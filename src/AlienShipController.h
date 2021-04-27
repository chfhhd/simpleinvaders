#pragma once

#include <memory>
#include <vector>
#include <sstream>
#include <string>

#include "AlienShip.h"

namespace Game {
    class AlienShipController {
    public:
        explicit AlienShipController(std::vector<std::shared_ptr<Game::AlienShip>> &alienShips, Texture2D alienShipTexture, std::vector<std::shared_ptr<Game::Bullet>> & bullets);

        void Update();

    private:
        // number of ships in alien fleet
        const int shipsPerRow = 11;
        const int numberOfRows = 5;

        // horizontal and vertical margin between ships
        const float marginHorizontal = 17.0;
        const float marginVertical = 17.0;

        // alien ship position (initialized with first ships position)
        const Vector2 startPosition = {0.0f, 0.0f};

        int fireFrequency = 50;

        std::vector<std::shared_ptr<Game::AlienShip>> & alienShips;

        Vector2 alienShipsSpeed = {13.0f, 5.0f};

        void MoveShips();

        void Fire();

        bool FreeToFire(int randomShipID);
    };
}