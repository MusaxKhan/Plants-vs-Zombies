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
#include "Parent Zombie.h"

class Football_Zombie : public Zombie
{
public:
	sf::Texture football_zombie_textue[29];

public:

	Football_Zombie(patch grid[][9],
		string path1 = "C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/Zombies/football zombie/footbll ("
	) {

		//srand(time(0));
		number_of_textures = 29;
		for (int i = 0; i < number_of_textures; i++) {
			string path = path1 + to_string(i + 1) + ").png";

			football_zombie_textue[i].loadFromFile(path);
		}


		do {
			lane = rand() % 5;
		} while (!grid[lane][0].isvalid());

		current_x = 1400;
		current_y = grid[lane][8].getY();

		zombie_sprite.setPosition(current_x, current_y - 30);

		health = 250;
		attack_damage = 0.5;
		speed = 0.4;
		exist = true;


		zombie_sprite.setOrigin(107, 96);
	}

	void move_zombie() {
		current_x -= speed;
		zombie_sprite.setPosition(current_x, current_y);

		if (current_x < 300)
			exist = false;


		if (texture_num == number_of_textures)
			texture_num = 1;

		zombie_sprite.setTexture(football_zombie_textue[texture_num++]);
		if (texture_num == number_of_textures)
			texture_num = 1;


	}

	void draw_zombie(sf::RenderWindow& window) {
		if (!eating && exist)
			move_zombie();

		if (!exist)
			zombie_sprite.setPosition(10000, 10000);

		window.draw(zombie_sprite);
	}


	Football_Zombie& operator=(const Football_Zombie& other) {
		if (this != &other) { // Check for self-assignment
			// Copy primitive member variables
			health = other.health;
			attack_damage = other.attack_damage;
			attack_rate = other.attack_rate;
			lane = other.lane;
			speed = other.speed;
			current_x = other.current_x;
			current_y = other.current_y;
			texture_num = other.texture_num;

			// Copy textures
			for (int i = 0; i < number_of_textures; i++) {
				football_zombie_textue[i] = other.football_zombie_textue[i];
			}

			// Copy sprite
			zombie_sprite = other.zombie_sprite;
		}
		return *this; // Return a reference to the modified object
	}


};