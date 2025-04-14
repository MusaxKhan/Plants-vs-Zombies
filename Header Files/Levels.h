#pragma once
#include <iostream>
#include "Plant Factory.h"
#include "Zombie Factoryr.h"
#include "SunFactory.h"
#include "Patch.h"
#include "LawnMower.h"
#include "Stages.h"
using namespace std;

#ifndef LEVELS_H
#define LEVELS_H
class Levels
{
public:
	Sprite bar;
	Image bar_image;
	Texture bar_texture;

	int bar_x;
	int bar_y;
	int total_plants;
	int types_of_zombies;
	int num_of_LawnMowers;

	PlantFactory** pfac;
	Zombie_Factory** zfac;
	LawnMower** mowers;
	Sun_Factory sfac;
	patch grid[5][9];

	RectangleShape box;
	RectangleShape replace;
	Clock level_timer;
	int time;

	Levels(int a, int b) :total_plants(6), types_of_zombies(5)
	{
		time = 300;
		setPatch(grid);
		enable_rows(grid, a, b);
		num_of_LawnMowers = 6;
		pfac = new PlantFactory * [total_plants];
		mowers = new LawnMower * [num_of_LawnMowers];

		zfac = new Zombie_Factory * [types_of_zombies];

		for (int i = 0;i < total_plants;i++)
		{
			if (i == 0)
				pfac[i] = new PlantFactory("PeaShooter", grid);
			else if (i == 1)
				pfac[i] = new PlantFactory("SunFlower", grid);
			else if (i == 2)
				pfac[i] = new PlantFactory("Repeater", grid);
			else if (i == 3)
				pfac[i] = new PlantFactory("Wallnut", grid);
			else if (i == 4)
				pfac[i] = new PlantFactory("Snow Pea", grid);
			else if (i == 5)
				pfac[i] = new PlantFactory("Cherry Bomb", grid);


			bar_image.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/bar.png");
			bar_x = -355;
			bar_y = -70;
		}
		sf::RectangleShape box2(sf::Vector2f(80, 87));
		box2.setPosition(127.5, 17.5);
		box2.setFillColor(sf::Color(181, 101, 29));
		sf::RectangleShape box3(sf::Vector2f(85, 92));
		box3.setPosition(125, 15);
		box3.setFillColor(sf::Color(255, 255, 0));
		box = box2;
		replace = box3;
		for (int i = 0;i < types_of_zombies;i++)
		{
			if (i == 0)
				zfac[i] = new Zombie_Factory(grid, "Simple Zombie", 14);
			else if (i == 1)
				zfac[i] = new Zombie_Factory(grid, "Conehead Zombie", 20);
			else if (i == 2)
				zfac[i] = new Zombie_Factory(grid, "Football Zombie", 25);
			else if (i == 3)
				zfac[i] = new Zombie_Factory(grid, "Ballon Zombie", 15);
			else if (i == 4)
				zfac[i] = new Zombie_Factory(grid, "Dancer Zombie", 25);
		}
		int start_x = 245;
		int start_y = 99;

		int diff_x = 102;
		int diff_y = 124;
		for (int i = 0;i < num_of_LawnMowers;i++)
		{
			if (i == 0)
				mowers[i] = new LawnMower(start_x, start_y);
			else if (i == 1)
				mowers[i] = new LawnMower(start_x, start_y);
			else if (i == 3)
				mowers[i] = new LawnMower(start_x, start_y);
			else if (i == 2)
				mowers[i] = new LawnMower(start_x, start_y);
			else if (i == 4)
				mowers[i] = new LawnMower(start_x, start_y);
			else if (i == 5)
				mowers[i] = new LawnMower(start_x, start_y);
			start_y += diff_y;
		}


	}
	void virtual draw_BackGround(RenderWindow&) = 0;
	void virtual Run_Plant_Factory(int, RenderWindow&, int*) = 0;
	void virtual drawBar(RenderWindow& window) = 0;
	void virtual draw_Plants(RenderWindow& window, int a, int types_of_zombies, Zombie_Factory** zfac, patch grid[][9], int& score) = 0;
};

void zombie_interaction(Zombie_Factory** zfacs, PlantFactory** pfacs, int num_zombie_factories, int num_plant_factories, patch grid[][9], bool& a) {


	for (int i = 0; i < num_zombie_factories; i++) {

		for (int j = 0; j < zfacs[i]->numZombies; j++) {

			zfacs[i]->zombies[j]->eating = false;

			if (zfacs[i]->zombies[j]->current_x <= 221) {
				a = false;
				currrent_stage = "Game Lost";
			}

			for (int k = 0; k < num_plant_factories; k++) {

				for (int l = 0; l < pfacs[k]->size; l++) {

					if (zfacs[i]->zombies[j]->getClosestXCoordinate(grid) + 50 == pfacs[k]->plants[l]->getX() + 50) {
						if (zfacs[i]->zombies[j]->getClosestYCoordinate(grid) == pfacs[k]->plants[l]->getY()) {

							zfacs[i]->zombies[j]->eating = true;

							pfacs[k]->plants[l]->health -= zfacs[i]->zombies[j]->attack_damage;
							cout << pfacs[k]->plants[l]->health << endl;
							if (pfacs[k]->plants[l]->health <= 0) {


								int x_y[2];
								x_y[0] = pfacs[k]->plants[l]->getX();
								x_y[1] = pfacs[k]->plants[l]->getY();
								can_be_placed(grid, x_y, 1);

								pfacs[k]->plants[l]->setX(-2000);
								pfacs[k]->plants[l]->setY(-2000);


							}

						}

					}
				}

			}

		}

	}
}
#endif
