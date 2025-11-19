#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>

// Abstract Base Class
class Entity {
protected:
    int x, y;
    char icon;
    std::string name;

public:
    Entity(int startX, int startY, char sym, std::string n) 
        : x(startX), y(startY), icon(sym), name(n) {}

    virtual ~Entity() {}

    // Pure virtual function
    virtual void update() = 0;

    int getX() const { return x; }
    int getY() const { return y; }
    char getIcon() const { return icon; }

    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }
};

#endif
