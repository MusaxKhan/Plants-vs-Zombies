#pragma once
#include <iostream>
#include "Pea.h"
#include "Zombie Factoryr.h"
using namespace std;

#ifndef PLANT_H
#define PLANT_H
class Plant
{
public:
	int health;
	int cost;
	int x;
	int y;
	int texture_num;

	bool is_placed;
	bool move;

public:
	bool exists = true;
	Plant() :exists(1) {}
	void virtual attack() = 0;
	void virtual disappear() = 0;
	void virtual draw_on(RenderWindow& win) = 0;
	Sprite virtual get_Sprite() = 0;
	void virtual update(RenderWindow& window, Zombie_Factory** zfacs, int types_of_zombies, patch grid[][9], int& score) = 0;
	void virtual setCoordinates(int* cor, bool alpha = false) = 0;
	void virtual Start_Moving(RenderWindow& window, patch grid[][9]) = 0;
	void setX(int set_x)
	{
		x = set_x;
	}
	void setY(int set_y)
	{
		y = set_y;
	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	bool getBool()
	{
		return move;
	}
	void setBool(bool a)
	{
		move = a;
	}
	void Score(int& score)
	{
		score += 50;
	}
};
#endif