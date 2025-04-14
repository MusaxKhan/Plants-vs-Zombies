#pragma once
#include <iostream>
#include "Patch.h"
#include "Levels.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "level5.h"
#include "level6.h"
#include "Level7.h"
using namespace std;

#ifndef GAME_H
#define GAME_H
class Game
{
	int level;
	Levels* levels;
	patch grid[][9];
public:
	Game() :level(0) {}
	Game(int lvl, patch pat[][9], RenderWindow& window) :level(lvl)
	{
		if (level == 1)
		{
			levels = new Level1(window);
		}
		if (level == 2)
		{
			levels = new Level2(window);
		}
		if (level == 3)
		{
			levels = new Level3(window);
		}
		if (level == 4)
		{
			levels = new Level4(window);
		}
		if (level == 5)
		{
			levels = new Level5(window);
		}
		if (level == 6)
		{
			levels = new Level6(window);
		}
		if (level == 7)
		{
			levels = new Level7(window);
		}
	}
	~Game()
	{
		//delete[] lvl;
	}
};
#endif