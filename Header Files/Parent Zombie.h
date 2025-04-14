#pragma once
#include <iostream>
#include <cstdlib>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
using namespace std;

#include "Patch.h"

#ifndef Zombie_H
#define Zombie_H

class Zombie {
public:

	sf::Sprite zombie_sprite;
	int texture_num = 1;
	int number_of_textures;

	int health;
	float attack_damage;
	int attack_rate;

	int lane;
	float speed;

	float current_x;
	float current_y;

	bool exist;
	bool eating;

public:


	virtual void draw_zombie(sf::RenderWindow& window) {
		//window.draw(zombie_sprite);

	}
	void get_grid(patch grid[][9]) {



	}

	int getClosestXCoordinate(patch grid[][9]) {
		int closestX = 0;
		float minDistance = 999999; // Initialize minDistance to a large value

		// Iterate through the grid to find the closest x coordinate
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 9; j++) {
				float distance = abs(current_x - grid[i][j].getX()); // Calculate distance
				if (distance < minDistance) {
					minDistance = distance;
					closestX = grid[i][j].getX(); // Update closest x coordinate
				}
			}
		}
		return closestX;
	}
	int getClosestYCoordinate(patch grid[][9]) {
		int closestY = 0;
		float minDistance = 999999; // Initialize minDistance to a large value

		// Iterate through the grid to find the closest Y coordinate
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 9; j++) {
				float distance = abs(current_y - grid[i][j].getY()); // Calculate distance
				if (distance < minDistance) {
					minDistance = distance;
					closestY = grid[i][j].getY(); // Update closest Y coordinate
				}
			}
		}
		return closestY;
	}

};

#endif