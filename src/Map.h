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
                // Create borders and random obstacles
                if (x == 0 || x == width - 1 || y == 0 || y == height - 1) {
                    row += '#';
                } else if (rand() % 10 == 0) {
                    row += '#'; // Random wall
                } else {
                    row += '.'; // Floor
                }
            }
            grid.push_back(row);
        }
    }

    bool isWall(int x, int y) const {
        if (x < 0 || x >= width || y < 0 || y >= height) return true;
        return grid[y][x] == '#';
    }

    // Render map and overlay the player
    void render(int pX, int pY, char pIcon) const {
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                if (x == pX && y == pY) {
                    std::cout << pIcon; // Draw Player
                } else {
                    std::cout << grid[y][x]; // Draw Map
                }
            }
            std::cout << std::endl;
        }
    }
};

#endif
