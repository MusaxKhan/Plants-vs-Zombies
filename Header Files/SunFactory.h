#pragma once
#pragma once
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
using namespace sf;
using namespace std;

#include "Sun.h"

class Sun_Factory : public Sun
{
public:
	Sun** suns;
	sf::Clock sun_clock;

	int fall_interval;
	int num_suns;
	int size;

	float last_sun_time;
public:
	Sun_Factory(int fall_t = 10) {
		fall_interval = fall_t;
		last_sun_time = 0;
		suns = new Sun * [5];
		num_suns = 0;
		size = 5;
	}

	void run_factory(sf::RenderWindow& window, int& score) {
		float elapsedtime = sun_clock.getElapsedTime().asSeconds();
		if (elapsedtime - last_sun_time >= fall_interval) {
			last_sun_time = elapsedtime;
			if (num_suns >= size) {

				Sun** temp = new Sun * [size];
				for (int i = 0; i < size; i++)
				{
					temp[i] = suns[i];
				}
				delete[] suns;

				suns = new Sun * [size * 2];

				for (int i = 0; i < size; i++)
				{
					suns[i] = temp[i];
				}
				delete[] temp;


				size *= 2;


			}
			else {
				suns[num_suns] = new Sun;
				num_suns++;
			}

		}

		for (int i = 0; i < num_suns; i++)
		{
			suns[i]->draw_sun(window, score);
		}


	}
};