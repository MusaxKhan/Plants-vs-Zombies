#pragma once
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
using namespace sf;
using namespace std;

#include "Screen_class.h"
#include "Button.h"
#include "Stages.h"

void backend_lost_game(sf::RenderWindow& window) {
	sf::Font font;
	if (!font.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Font Styles/Burbank Big Condensed Font.otf")) {
		std::cerr << "Failed to load font" << std::endl;
		return;
	}

	Screen bg("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/lawn.png");


	Screen txt("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/Menu/PvZ1ZombiesWon (1).png");

	sf::RectangleShape brightnessRect(sf::Vector2f(window.getSize().x, window.getSize().y));
	brightnessRect.setFillColor(sf::Color(0, 0, 0, 150)); // Dark semi-transparent color

	Button Levels_btn("Levels", 500, 600, 200, 50, sf::Color::White, font, sf::Color::Green, 28);
	Levels_btn.setlocation_text(570, 610);
	Levels_btn.on_click(window, "Levels Page", currrent_stage, previous_stage);


	bg.draw_on(window);

	window.draw(brightnessRect);

	txt.draw_on(window);

	Levels_btn.drawTo(window);
}