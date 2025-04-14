#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <ctime>

#include  "Button.h"
#include  "Stages.h"
using namespace sf;
using namespace std;


void createBackground_Homescreen(RenderWindow& window) {
	// Drawing the background
	Image map_image;
	map_image.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/homescreen2.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setScale(float(window.getSize().x) / map_image.getSize().x, float(window.getSize().y) / map_image.getSize().y); // Scale to window size
	s_map.setPosition(0, 0);
	window.draw(s_map);
}

void backend_homescreen(sf::RenderWindow& window, Button& play_btn, Button& Settings_btn, Button& Instruction_btn) {
	//Side By Side Running Functions
	createBackground_Homescreen(window);
	play_btn.on_button(window);
	//Levels_btn.on_button(window);
	Settings_btn.on_button(window);
	Instruction_btn.on_button(window);

	//Drawing Buttons
	play_btn.drawTo(window);
	//Levels_btn.drawTo(window);
	Settings_btn.drawTo(window);
	Instruction_btn.drawTo(window);

	//Clicking Buttons
	play_btn.on_click(window, "Login", currrent_stage, previous_stage);
	//Levels_btn.on_click(window,"Levels Page", currrent_stage, previous_stage);
	Settings_btn.on_click(window, "Settings Page", currrent_stage, previous_stage);
	Instruction_btn.on_click(window, "Instruction Page", currrent_stage, previous_stage);
}
void backend_homescreen(sf::RenderWindow& window, Button& play_btn, Button& Settings_btn, Button& Instruction_btn, Texture map_image[509], int& frame_num, Clock& frameClock) {
	//Side By Side Running Functions
	//createBackground_Homescreen(window);

	Sprite my_sprite;
	if (frameClock.getElapsedTime().asMilliseconds() >= 100) {
		// Reset the clock
		frameClock.restart();

		// Increment frame number
		if (frame_num >= 509)
			frame_num = 0;
		else
			frame_num++;
	}


	my_sprite.setTexture(map_image[frame_num]);

	window.draw(my_sprite);


	play_btn.on_button(window);
	//Levels_btn.on_button(window);
	Settings_btn.on_button(window);
	Instruction_btn.on_button(window);

	//Drawing Buttons
	play_btn.drawTo(window);
	//Levels_btn.drawTo(window);
	Settings_btn.drawTo(window);
	Instruction_btn.drawTo(window);

	//Clicking Buttons
	play_btn.on_click(window, "Login", currrent_stage, previous_stage);
	//Levels_btn.on_click(window,"Levels Page", currrent_stage, previous_stage, previous_stage_2);
	Settings_btn.on_click(window, "Settings Page", currrent_stage, previous_stage);
	Instruction_btn.on_click(window, "Instruction Page", currrent_stage, previous_stage);
}