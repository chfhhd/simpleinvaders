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
        // number of ships in alien fleet
        const int shipsPerRow = 11;
        const int numberOfRows = 5;

        // horizontal and vertical margin between ships
        const float marginHorizontal = 17.0;
        const float marginVertical = 17.0;

        // alien ship position (initialized with first ships position)
        const Vector2 startPosition = {0.0f, 0.0f};

        std::vector<std::shared_ptr<Game::AlienShip>> & alienShips;

        Texture2D alienShipTexture{};

        Vector2 alienShipsSpeed = {17.0f, 5.0f};
    };
}