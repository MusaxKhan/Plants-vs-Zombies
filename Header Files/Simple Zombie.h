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

class Simple_Zombie : public Zombie {
public:
	sf::Texture zombie_texture[5];
	sf::Clock textureClock;
public:

	Simple_Zombie(patch grid[][9],
		string path ="C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/Zombies/simple"
	) {

		//srand(time(0));
		number_of_textures = 5;
		for (int i = 0; i < number_of_textures; i++)
		{
			string pathe = path + to_string(i + 1) + ".png";
			zombie_texture[i].loadFromFile(pathe);
		}

		zombie_sprite.setTexture(zombie_texture[0]);


		do {
			lane = rand() % 5;
		} while (!grid[lane][0].isvalid());

		current_x = 1400;
		current_y = grid[lane][8].getY();

		zombie_sprite.setPosition(current_x, current_y);

		health = 100;
		attack_damage = 0.25;
		speed = 0.2;

		exist = true;
		eating = false;


		zombie_sprite.setOrigin(zombie_sprite.getLocalBounds().width / 2, zombie_sprite.getLocalBounds().height / 2);
	}

	void move_zombie() {
		current_x -= speed;
		zombie_sprite.setPosition(current_x, current_y);

		if (textureClock.getElapsedTime().asSeconds() >= 0.3f) {
			// Change texture
			if (texture_num == number_of_textures)
				texture_num = 0;

			zombie_sprite.setTexture(zombie_texture[texture_num++]);
			if (texture_num == number_of_textures)
				texture_num = 0;

			// Reset the texture clock
			textureClock.restart();
		}
	}

	void draw_zombie(sf::RenderWindow& window) {
		if (health < 0)
			exist = false;

		if (!eating && exist)
			move_zombie();

		if (!exist)
			zombie_sprite.setPosition(10000, 10000);

		window.draw(zombie_sprite);
	}

	Simple_Zombie& operator=(const Simple_Zombie& other) {
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