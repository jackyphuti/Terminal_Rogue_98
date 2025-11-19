#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Entity.h"
#include "Map.h"
#include <cmath>

class Zombie : public Entity {
public:
    Zombie(int x, int y) : Entity(x, y, 'Z', "Zombie") {}

    // AI Logic: Simple Manhattan Chaser
    void update(int targetX, int targetY, const Map& map) {
        int dx = 0;
        int dy = 0;

        // Determine direction towards target (Player)
        if (x < targetX) dx = 1;
        else if (x > targetX) dx = -1;
        
        if (y < targetY) dy = 1;
        else if (y > targetY) dy = -1;

        // Try X movement
        if (dx != 0 && !map.isWall(x + dx, y)) {
            x += dx;
        }
        // Else Try Y movement (simple obstacle avoidance)
        else if (dy != 0 && !map.isWall(x, y + dy)) {
            y += dy;
        }
    }
};

#endif
