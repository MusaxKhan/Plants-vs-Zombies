#pragma once
#include <iostream>
#include <cstdlib>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
using namespace sf;
using namespace std;

#include "Patch.h"
#include "Parent Zombie.h"
#include "Backup Dancer Zombie.h"

#ifndef DANCER_ZOMBIE
#define DANCER_ZOMBIE



class Dancer_Zombie : public Zombie {
public:
	sf::Texture zombie_texture[14];
	sf::Clock textureClock;
	sf::Clock lane_timer;
	sf::Clock backup_timer;

	Backup_Dancer_Zombie backup_zombies[4];

public:

	Dancer_Zombie(patch grid[][9],
		string path =  "C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/Zombies/dancer zombie/dancer ("
	) {

		//srand(time(0));
		number_of_textures = 14;
		for (int i = 0; i < number_of_textures; i++)
		{
			string pathe = path + to_string(i + 1) + ").png";
			zombie_texture[i].loadFromFile(pathe);
		}

		zombie_sprite.setTexture(zombie_texture[0]);


		do {
			lane = rand() % 5;
		} while (!grid[lane][0].isvalid());

		current_x = 1400;
		current_y = grid[lane][8].getY();

		zombie_sprite.setPosition(current_x, current_y);

		health = 200;
		attack_damage = 0.35;
		speed = 0.3;


		zombie_sprite.setOrigin(zombie_sprite.getLocalBounds().width / 2, zombie_sprite.getLocalBounds().height / 2);
		zombie_sprite.setScale(1, 0.8);

		for (int i = 0; i < 4; i++) {
			backup_zombies[i].current_x = 10000;
			backup_zombies[i].current_y = 10000;
		}

	}


	void move_zombie() {
		current_x -= speed;
		zombie_sprite.setPosition(current_x, current_y);

		if (textureClock.getElapsedTime().asSeconds() >= 0.15f) {
			// Change texture
			if (texture_num == number_of_textures)
				texture_num = 0;

			zombie_sprite.setTexture(zombie_texture[texture_num++]);
			if (texture_num == number_of_textures)
				texture_num = 0;

			// Reset the texture clock
			textureClock.restart();
		}
		if (lane_timer.getElapsedTime().asSeconds() >= 5) {
			// Change lane
			int luck = rand() % 2;

			if (luck == 0) {
				if (current_y <= 471)
					current_y += 124;
			}
			else {
				if (current_y > 99)
					current_y -= 124;
			}

			// Reset the  clock
			lane_timer.restart();
		}

		if (backup_timer.getElapsedTime().asSeconds() >= 20) {
			backup_zombies[0].current_x = current_x + 102;
			backup_zombies[0].current_y = current_y;

			backup_zombies[1].current_x = current_x;
			backup_zombies[1].current_y = current_y + 124;

			backup_zombies[2].current_x = current_x - 102;
			backup_zombies[2].current_y = current_y;

			backup_zombies[3].current_x = current_x;
			backup_zombies[3].current_y = current_y - 124;
		}



	}

	void draw_zombie(sf::RenderWindow& window) {
		if (!eating && exist)
			move_zombie();

		if (!exist)
			zombie_sprite.setPosition(10000, 10000);

		for (int i = 0; i < 4; i++)
		{
			if (exist) {
				backup_zombies[i].zombie_sprite.setPosition(backup_zombies[i].current_x, backup_zombies[i].current_y);
				backup_zombies[i].draw_zombie(window);
			}
		}

		window.draw(zombie_sprite);
	}

	Dancer_Zombie& operator=(const Dancer_Zombie& other) {
		if (this != &other) { // Check for self-assignment
			// Copy primitive member variables
			health = other.health;
			attack_damage = other.attack_damage;
			attack_rate = other.attack_rate;
			lane = other.lane;
			speed = other.speed;
			current_x = other.current_x;
			current_y = other.current_y;

			// Copy textures
			for (int i = 0; i < number_of_textures; i++)
			{
				zombie_texture[i] = other.zombie_texture[i];
			}
			// Copy sprite
			zombie_sprite = other.zombie_sprite;
		}
		return *this; // Return a reference to the modified object
	}

};
#endif