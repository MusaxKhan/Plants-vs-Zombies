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


class Sun {
public:

	sf::Image sun_image;
	sf::Texture sun_texture;
	sf::Sprite sun_sprite;
	sf::Clock expiration_counter;
	float expire_time;
	float last_sun_expire;

	float starting_x;
	float starting_y;

	float current_y;
	float current_x;

	float target_y;

	int points;
	int velocity;
	int start_time;

	bool exist;

public:

	Sun(string path = "C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/sun.png")
	{
		srand(time(0));
		points = 50;
		velocity = 3;
		expire_time = 7;
		last_sun_expire = 0;

		sun_image.loadFromFile(path);
		sun_texture.loadFromImage(sun_image);
		sun_sprite.setTexture(sun_texture);

		current_x = starting_x = (rand() % (1305 - 378)) + 378;
		//cout << starting_x << endl;
		starting_y = 0;
		current_y = 0;

		target_y = (rand() % (670 - 133)) + 133;

		exist = true;
	}

	void sun_onclick(sf::RenderWindow& window, int& score) {
		int mouse_x = sf::Mouse::getPosition(window).x;
		int mouse_y = sf::Mouse::getPosition(window).y;

		int sun_x = current_x + sun_sprite.getLocalBounds().width;
		int sun_y = current_y + sun_sprite.getLocalBounds().height;

		if (mouse_x < sun_x && mouse_x > current_x && mouse_y < sun_y && mouse_y > current_y) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				score += 50;
				exist = false;
			}
		}

	}

	void sun_fall() {
		if (current_y < target_y) {
			current_y += velocity;
			velocity += 0.08;
		}
		else {
			float elapsed_time = expiration_counter.getElapsedTime().asSeconds();
			if (elapsed_time - last_sun_expire >= expire_time) {
				last_sun_expire = elapsed_time;

				exist = false;
			}
		}
	}

	void draw_sun(sf::RenderWindow& window, int& score) {

		if (exist) {
			sun_fall();
			sun_onclick(window, score);
			sun_sprite.setPosition(current_x, current_y);
			window.draw(sun_sprite);
		}
		else {
			sun_sprite.setPosition(-1000, -1000);
		}

	}

};
				//C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/sun.png
//void spawn_Sun(RenderWindow& window)
//{
//
//}