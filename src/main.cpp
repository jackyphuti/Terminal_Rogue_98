#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "Entity.h"
#include "Map.h"
#include "Player.h"
#include "Zombie.h"

void clearScreen() {
    // Quick console clear
    std::cout << "\033[2J\033[1;1H";
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    const int WIDTH = 30;
    const int HEIGHT = 15;
    bool running = true;
    char input;

    // 1. Setup World
    Map dungeon(WIDTH, HEIGHT);
    
    // 2. Setup Player
    Player* player = new Player(2, 2);

    // 3. Setup Enemies (Polymorphism in action)
    std::vector<Entity*> enemies;
    enemies.push_back(new Zombie(15, 5));
    enemies.push_back(new Zombie(20, 10));
    enemies.push_back(new Zombie(25, 12));

    while (running) {
        clearScreen();
        std::cout << "--- C++98 TERMINAL ROGUE ---" << std::endl;
        std::cout << "Controls: w/a/s/d to move, q to quit." << std::endl;
        
        // Render Everything
        dungeon.render(enemies, player);

        // Input
        std::cout << "> ";
        std::cin >> input;

        if (input == 'q') running = false;
        
        // Player Turn
        int dx = 0; int dy = 0;
        if (input == 'w') dy = -1;
        if (input == 's') dy = 1;
        if (input == 'a') dx = -1;
        if (input == 'd') dx = 1;
        
        if (dx != 0 || dy != 0) {
            player->tryMove(dx, dy, dungeon);
            
            // Enemy Turn (Only moves if player moves)
            for (size_t i = 0; i < enemies.size(); ++i) {
                enemies[i]->update(player->getX(), player->getY(), dungeon);
                
                // Simple "Game Over" check
                if (enemies[i]->getX() == player->getX() && 
                    enemies[i]->getY() == player->getY()) {
                    clearScreen();
                    std::cout << "\n!!! CHOMP !!!\n";
                    std::cout << "A Zombie ate you.\n";
                    std::cout << "GAME OVER\n\n";
                    running = false;
                    break;
                }
            }
        }
    }

    // Cleanup (Memory Management)
    delete player;
    for (size_t i = 0; i < enemies.size(); ++i) {
        delete enemies[i];
    }
    enemies.clear();

    return 0;
}
