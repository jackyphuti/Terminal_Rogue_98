#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Entity.h"
#include "Map.h"

// Derived Player Class
class Player : public Entity {
public:
    Player(int x, int y) : Entity(x, y, '@', "Hero") {}

    void update() {
        // Player update logic if needed
    }
};

// Helper to clear screen (Linux/Mac)
void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    const int WIDTH = 20;
    const int HEIGHT = 10;
    bool running = true;
    char input;

    // Setup Memory
    Map dungeon(WIDTH, HEIGHT);
    // Pointer to base class (Polymorphism)
    Entity* player = new Player(WIDTH / 2, HEIGHT / 2);

    while (running) {
        clearScreen();
        std::cout << "--- C++98 ROGUE ---" << std::endl;
        std::cout << "Controls: w (up), s (down), a (left), d (right), q (quit)" << std::endl;
        
        // Render
        dungeon.render(player->getX(), player->getY(), player->getIcon());

        // Input
        std::cout << "> ";
        std::cin >> input;

        int dx = 0; 
        int dy = 0;

        if (input == 'q') running = false;
        else if (input == 'w') dy = -1;
        else if (input == 's') dy = 1;
        else if (input == 'a') dx = -1;
        else if (input == 'd') dx = 1;

        // Collision Detection & Move
        int newX = player->getX() + dx;
        int newY = player->getY() + dy;

        if (!dungeon.isWall(newX, newY)) {
            player->move(dx, dy);
        }
    }

    // Clean up memory (Rule of C++98)
    delete player;

    return 0;
}
