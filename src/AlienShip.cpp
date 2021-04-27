#include "AlienShip.h"

void Game::AlienShip::fire() {
    if(fireCommand)
        fireCommand->execute(this);
}
