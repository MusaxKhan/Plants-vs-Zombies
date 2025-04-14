#pragma once
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Static_Sun
{
	Sprite sun;
	int x;
	int y;
public:
	Static_Sun(RenderWindow& window, int initial_x, int initial_y)
	{
		Image sun_i;
		sun_i.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/sun.png");
		Texture sun_t;
		sun_t.loadFromImage(sun_i);
		sun.setTexture(sun_t);
		x = initial_x;
		y = initial_y;
		sun.setPosition(x, y);
	}
	Sprite getSprite()
	{
		return sun;
	}
	void spawn_Sun(RenderWindow& win)
	{
		Image sun_i;
		sun_i.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/sun.png");
		Texture sun_t;
		sun_t.loadFromImage(sun_i);
		sun.setTexture(sun_t);
		sun.setPosition(x, y);
		win.draw(sun);
	}
	bool isTouched(int x, int y, Sprite sun)
	{
		x -= 343;
		y -= 217;
		int length = sun.getGlobalBounds().height;
		int width = sun.getGlobalBounds().width;
		if (x >= sun.getPosition().x - 2 && x <= sun.getPosition().x + width + 1 && y >= sun.getPosition().y - 2 && y < sun.getPosition().y + length + 1)
		{
			return true;
		}
		else
			return false;
	}
};