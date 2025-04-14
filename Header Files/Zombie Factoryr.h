#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
using namespace sf;
using namespace std;

#include "Parent Zombie.h"
#include "Football Zombie.h"
#include "Simple Zombie.h"
#include "Conehead Zombie.h"
#include "Dancer Zombie.h"
#include "Ballon Zombie.h"

#ifndef ZOMBIE_FACTORY
#define ZOMBIE_FACTORY


class Zombie_Factory {
public:
    Zombie** zombies;
    int capacity = 5;
    int numZombies = 0;

    // Variables to track time for Football Zombie creation
    sf::Clock zombieClock;
    float lastZombieTime = 0;
    float zombieCreationInterval = 1.0f; // Interval in seconds

    string type;
    patch grid[5][9];

public:
    Zombie_Factory(patch grd[][9], string typ = "Simple Zombie", int time = 5) {

        capacity = 5;
        numZombies = 0;
        lastZombieTime = 0;
        type = typ;
        zombieCreationInterval = time;

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 9; j++) {
                grid[i][j] = grd[i][j];
            }
        }

        zombies = new Zombie * [capacity];
        for (int i = 0; i < capacity; ++i) {
            zombies[i] = nullptr;
        }

    }

    void run_factory(sf::RenderWindow& window) {
        float elapsedTime = zombieClock.getElapsedTime().asSeconds();
        if (elapsedTime - lastZombieTime >= zombieCreationInterval) {
            lastZombieTime = elapsedTime; // Update last creation time

            if (numZombies >= capacity) {
                // Resize the array if needed
                Zombie** temp = new Zombie * [capacity * 2];
                for (int i = 0; i < capacity; ++i) {
                    temp[i] = zombies[i];
                }
                delete[] zombies;
                zombies = new Zombie * [capacity * 2];
                for (int i = 0; i < capacity; ++i) {
                    zombies[i] = temp[i];
                }
                capacity *= 2;

                delete[] temp;
            }

            if (type == "Simple Zombie") {
                zombies[numZombies] = new Simple_Zombie(grid);

            }
            else if (type == "Football Zombie") {
                zombies[numZombies] = new Football_Zombie(grid);
            }
            else if (type == "Conehead Zombie") {
                zombies[numZombies] = new Conehead_Zombie(grid);
            }
            else if (type == "Dancer Zombie") {
                zombies[numZombies] = new Dancer_Zombie(grid);
            }
            else if (type == "Ballon Zombie") {
                zombies[numZombies] = new Ballon_Zombie(grid);
            }
            numZombies++;

        }

        // Draw all zombies
        for (int i = 0; i < numZombies; i++) {
            if (zombies[i]->health < 0) {
                zombies[i]->exist = false;
                zombies[i]->current_x = zombies[i]->current_y = 10000;
                //zombies[i]->zombie_sprite.setPosition(-1000, -1000);
            }

            zombies[i]->draw_zombie(window);
        }


    }


};
#endif // !ZOMBIE_FACTORY