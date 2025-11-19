#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Map.h"

class Player : public Entity {
public:
    Player(int x, int y) : Entity(x, y, '@', "Hero") {}

    // Player update is handled by Input in main(), so this is empty
    void update(int targetX, int targetY, const Map& map) {
        // In a complex engine, regeneration or status effects go here
    }

    // Helper for movement with collision
    void tryMove(int dx, int dy, const Map& map) {
        if (!map.isWall(x + dx, y + dy)) {
            x += dx;
            y += dy;
        }
    }
};

#endif
