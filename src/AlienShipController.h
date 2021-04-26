#pragma once

#include <memory>
#include <vector>

#include "AlienShip.h"

namespace Game {
    class AlienShipController {
    public:
        explicit AlienShipController(std::vector<std::shared_ptr<Game::AlienShip>> &alienShips, Texture2D alienShipTexture);

        ~AlienShipController();

        void Update();

    private:
        std::vector<std::shared_ptr<Game::AlienShip>> & alienShips;

        Texture2D alienShipTexture{};

        Vector2 alienShipsSpeed = {17.0f, 5.0f};

        // number of ships in alien fleet
        const int shipsPerRow = 11;
        const int numberOfRows = 5;

        // horizontal and vertical margin between ships
        const float margin_x = 17.0;
        const float margin_y = 17.0;

        // alien ship position (initialized with first ships position)
        const Vector2 startPosition = {0.0f, 0.0f};
    };
}