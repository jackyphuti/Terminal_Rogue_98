#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>

// Forward declaration (allows us to use Map inside Entity)
class Map;

class Entity {
protected:
    int x, y;
    char icon;
    std::string name;

public:
    Entity(int startX, int startY, char sym, std::string n) 
        : x(startX), y(startY), icon(sym), name(n) {}

    virtual ~Entity() {}

    // Updated: Now takes target coordinates and the map for collision
    virtual void update(int targetX, int targetY, const Map& map) = 0;

    int getX() const { return x; }
    int getY() const { return y; }
    char getIcon() const { return icon; }
    std::string getName() const { return name; }

    void setPosition(int newX, int newY) {
        x = newX;
        y = newY;
    }
};

#endif
