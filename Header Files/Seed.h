#pragma once
#include <iostream>
#include <string.h>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
using namespace sf;
using namespace std;
#ifndef SEED_H
#define SEED_H

class Seed
{
	string type;
	Sprite seed;
	Image seed_image;
	Texture seed_texture;
	int point_x;
	int point_y;
	int start_x;
	int start_y;
	int pos1;
	int pos2;
	bool picked;
public:
	Seed(string path, int x, int y, string name)
	{
		type = name;
		picked = false;
		Image seed_i;
		seed_i.loadFromFile(path);
		point_x = x;
		point_y = y;
		start_x = x;
		start_y = y;
		seed_image = seed_i;
		pos1 = 0;
		pos2 = 0;
	}
	void draw_on(RenderWindow& window)
	{
		seed_texture.loadFromImage(seed_image);
		seed.setTexture(seed_texture);
		seed.setPosition(point_x, point_y);
		seed.setScale(1.1, 1);
		window.draw(seed);
	}
	void setPosition(int x, int y)
	{
		point_x = x;
		point_y = y;
	}
	int getX()
	{
		return point_x;
	}
	int getY()
	{
		return point_y;
	}
	string getName()
	{
		return type;
	}
	bool inRange(int x, int y)
	{
		x -= 328;
		y -= 210;
		if (x >= seed.getPosition().x && x <= seed.getPosition().x + seed.getGlobalBounds().width)
		{
			if (y >= seed.getPosition().y && y <= seed.getPosition().y + seed.getGlobalBounds().height)
			{
				pos1 = x;
				pos2 = y;
				return true;
			}
		}
		return false;
	}
	void pick_Seed()
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (inRange(Mouse::getPosition().x, Mouse::getPosition().y))
			{
				picked = true;
			}
		}
	}
	void drag_seed()
	{
		if(!picked)
		    pick_Seed();
		if (picked)
		{
			setPosition(Mouse::getPosition().x - 328 + (start_x-pos1), Mouse::getPosition().y - 210 + (start_y-pos2));
		}
	}
	bool drop_seed()
	{
	    if (!Mouse::isButtonPressed(Mouse::Left) && picked)
	    {
			setPosition(start_x, start_y);
			picked = false;
			return true;
	    }
		return false;
	}
	bool isPicked()
	{
		if (picked)
			return true;
		else
			return false;
	}
	void Decrement_Score(int& score)
	{
		if (type == "Pea")
			score -= 100;
		else if (type == "Snow")
			score -= 150;
		else if (type == "Wall")
			score -= 50;
		else if (type == "Sun")
			score -= 50;
		else if (type == "Rep")
			score -= 200;
		else if (type == "Cherry")
			score -= 150;
	}
	bool enough(int score)
	{
		if (type == "Pea")
		{
			if (score >= 100)
				return true;
			else
				return false;
		}
		else if (type == "Snow")
		{
			if (score >= 150)
				return true;
			else
				return false;
		}
		else if (type == "Wall")
		{
			if (score >= 50)
				return true;
			else
				return false;
		}
		else if (type == "Sun")
		{ 
			if (score >= 50)
				return true;
			else
				return false;
		}
		else if (type == "Rep")
		{ 
			if (score >= 200)
				return true;
			else
				return false;
		}
		else if (type == "Cherry")
		{
			if (score >= 150)
				return true;
			else
				return false;
		}
	}
};
#endif
