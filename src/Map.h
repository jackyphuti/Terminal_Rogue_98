#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

class Map {
private:
    int width, height;
    std::vector<std::string> grid;

public:
    Map(int w, int h) : width(w), height(h) {
        generate();
    }

    void generate() {
        grid.clear();
        for (int y = 0; y < height; ++y) {
            std::string row = "";
            for (int x = 0; x < width; ++x) {
                // Borders are always walls
                if (x == 0 || x == width - 1 || y == 0 || y == height - 1) {
                    row += '#';
                } 
                // 10% chance of random obstacle
                else if (rand() % 10 == 0) {
                    row += '#'; 
                } 
                else {
                    row += '.'; 
                }
            }
            grid.push_back(row);
        }
    }

    bool isWall(int x, int y) const {
        if (x < 0 || x >= width || y < 0 || y >= height) return true;
        return grid[y][x] == '#';
    }

    void render(const std::vector<class Entity*>& entities, const Entity* player) const {
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                bool drawn = false;

                // 1. Check Player
                if (player->getX() == x && player->getY() == y) {
                    std::cout << player->getIcon();
                    drawn = true;
                }

                // 2. Check Enemies
                if (!drawn) {
                    for (size_t i = 0; i < entities.size(); ++i) {
                        if (entities[i]->getX() == x && entities[i]->getY() == y) {
                            std::cout << entities[i]->getIcon();
                            drawn = true;
                            break;
                        }
                    }
                }

                // 3. Draw Map
                if (!drawn) {
                    std::cout << grid[y][x]; 
                }
            }
            std::cout << std::endl;
        }
    }
};

#endif
