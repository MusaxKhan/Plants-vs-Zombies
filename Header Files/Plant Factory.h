//#pragma once
//#include <iostream>
//#include "Plant.h"
//#include "PeaShooter.h"
//#include "Patch.h"
//#include "Screen_class.h"
//using namespace std;
//
//class PlantFactory
//{
//public:
//	Plant** plants;
//	int max;
//	int size_peaShooter;
//	string type;
//	int size;
//	patch** grid;
//	Clock move_time;
//public: 
//	PlantFactory(string plant, patch grids[][9], bool level = 0)
//	{
//		if (level)
//		{
//			grid = new patch*[6];
//			for (int i = 0;i < 6;i++)
//			{
//				grid[i] = new patch[9];
//				for (int j = 0;j < 9;j++)
//				{
//					grid[i][j] = grids[i][j];
//				}
//			}
//		}
//		else
//		{
//			grid = new patch * [5];
//			for (int i = 0;i < 6;i++)
//			{
//				grid[i] = new patch[9];
//				for (int j = 0;j < 9;j++)
//				{
//					grid[i][j] = grids[i][j];
//				}
//			}
//		}
//		size = 0;
//		type = plant;
//		max = 45;
//		plants = new Plant * [max];
//
//	}
//	void Run_factory(RenderWindow& window, int* cor)
//	{
//		if (size < max)
//		{
//			if (type == "SunFlower")
//			{
//				plants[size] = new Sunflower;
//				plants[size]->setCoordinates(cor);
//			}
//			else if (type == "PeaShooter")
//			{
//				plants[size] = new PeaShooter;
//				plants[size]->setCoordinates(cor);
//			}
//			else if (type == "Repeater")
//			{
//				plants[size] = new Repeater;
//				plants[size]->setCoordinates(cor);
//			}
//			else if (type == "Wallnut")
//			{
//				plants[size] = new Wallnut;
//				can_be_placed(grid, cor, 1);
//				cor[0] += 40;
//				cor[1] += 30;
//				plants[size]->setCoordinates(cor, true);
//
//			}
//			else if (type == "Snow Pea")
//			{
//				plants[size] = new SnowPea;
//				plants[size]->setCoordinates(cor);
//			}
//			else if (type == "Cherry Bomb")
//			{
//				plants[size] = new Cherry_Bomb;
//				plants[size]->setCoordinates(cor);
//			}
//			size++;
//		}
//	}
//	void draw_Factory(RenderWindow& window, int types_of_zombies, Zombie_Factory** zfac, patch grid[][9], int& score)
//	{
//		for (int i = 0; i < size; i++)
//		{
//			plants[i]->draw_on(window);
//		}
//		for (int i = 0;i < size;i++)
//		{
//			// Bullet Movement
//			if(plants[i]->exists)
//			plants[i]->update(window, zfac, types_of_zombies, grid, score);
//		}
//	}
//	void move_plant(RenderWindow& window, patch grid[][9])
//	{
//		for (int i = 0;i < size;i++)
//		{
//			if (plants[i]->getBool())
//			{
//				plants[i]->Start_Moving(window, grid);
//			}
//		}
//	}
//	bool getBool()
//	{}
//};
//

#pragma once
#include <iostream>
#include "Plant.h"
#include "PeaShooter.h"
#include "Patch.h"
#include "Screen_class.h"
using namespace std;

class PlantFactory
{
public:
	Plant** plants;
	int max;
	int size_peaShooter;
	string type;
	int size;
	patch** grid;
	Clock move_time;
public:
	PlantFactory(string plant, patch grids[][9], bool level = 0)
	{
		if (level)
		{
			grid = new patch * [6];
			for (int i = 0;i < 6;i++)
			{
				grid[i] = new patch[9];
				for (int j = 0;j < 9;j++)
				{
					grid[i][j] = grids[i][j];
				}
			}
		}
		else
		{
			grid = new patch * [5];
			for (int i = 0;i < 6;i++)
			{
				grid[i] = new patch[9];
				for (int j = 0;j < 9;j++)
				{
					grid[i][j] = grids[i][j];
				}
			}
		}
		size = 0;
		type = plant;
		max = 45;
		plants = new Plant * [max];
	}
	void Run_factory(RenderWindow& window, int* cor)
	{
		if (size < max)
		{
			if (type == "SunFlower")
			{
				plants[size] = new Sunflower;
				plants[size]->setCoordinates(cor);
			}
			else if (type == "PeaShooter")
			{
				plants[size] = new PeaShooter;
				plants[size]->setCoordinates(cor);
			}
			else if (type == "Repeater")
			{
				plants[size] = new Repeater;
				plants[size]->setCoordinates(cor);
			}
			else if (type == "Wallnut")
			{
				plants[size] = new Wallnut;
				can_be_placed(grid, cor, 1);
				//cout << cor[0] << " " << cor[1] << endl;

				//cor[0] += 40;
				//cor[1] += 30;
				plants[size]->setCoordinates(cor, true);

			}
			else if (type == "Snow Pea")
			{
				plants[size] = new SnowPea;
				plants[size]->setCoordinates(cor);
			}
			else if (type == "Cherry Bomb")
			{
				plants[size] = new CherryBomb;
				plants[size]->setCoordinates(cor);
			}
			size++;

		}
	}
	void draw_Factory(RenderWindow& window, int types_of_zombies, Zombie_Factory** zfac, patch grid[][9], int& score)
	{
		for (int i = 0; i < size; i++)
		{
			plants[i]->draw_on(window);
		}
		for (int i = 0;i < size;i++)
		{
			// Bullet Movement
			plants[i]->update(window, zfac, types_of_zombies, grid, score);
		}
	}


	void move_plant(RenderWindow& window, patch grid[][9])
	{
		for (int i = 0;i < size;i++)
		{
			if (plants[i]->getBool())
			{
				plants[i]->Start_Moving(window, grid);
			}
		}
	}

};