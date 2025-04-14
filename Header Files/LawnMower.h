#pragma once
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Zombie Factoryr.h"
using namespace std;
using namespace sf;

class LawnMower
{
	int current_x;
	int current_y;
	Sprite Lawn_Mower;
	bool start;
public:
	LawnMower() {}
	LawnMower(int x, int y)
	{
		current_x = x;
		current_y = y;
		start = false;
		Image Lawn_Mower_image;
		Lawn_Mower_image.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/car.png");
		Texture Lawn_Mower_text;
		Lawn_Mower_text.loadFromImage(Lawn_Mower_image);
		Lawn_Mower.setTexture(Lawn_Mower_text);
		Lawn_Mower.setPosition(x, y);
	}
	int getX()
	{
		return current_x;
	}
	int getY()
	{
		return current_y;
	}
	void draw_on(RenderWindow& window, bool is_touched = false)
	{
		Image Lawn_Mower_image;
		Lawn_Mower_image.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/car.png");
		Texture Lawn_Mower_text;
		Lawn_Mower_text.loadFromImage(Lawn_Mower_image);
		Lawn_Mower.setTexture(Lawn_Mower_text);
		Lawn_Mower.setPosition(current_x, current_y);
		if (is_touched)
			start = true;
		if (start)
			current_x += 5;

		if (current_x > 1305) {
			current_x = 4000;
			current_y = 4000;

		}

		//cout << current_x << endl;
		window.draw(Lawn_Mower);
	}
	void update(RenderWindow& window, Zombie_Factory** zfacs, int types_of_zombies, patch grid[][9])
	{
		for (int i = 0; i < types_of_zombies; i++)
		{
			for (int j = 0; j < zfacs[i]->numZombies; j++)
			{
				if (getX() + 40 > zfacs[i]->zombies[j]->current_x - 40)
				{
					if (getY() == zfacs[i]->zombies[j]->current_y)
					{
						start = true;

						zfacs[i]->zombies[j]->exist = false;
						zfacs[i]->zombies[j]->current_x = 3000;
						zfacs[i]->zombies[j]->current_y = 3000;

					}
				}
			}
		}
	}

};