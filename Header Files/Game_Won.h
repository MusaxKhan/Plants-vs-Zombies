#pragma once
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Button.h"
using namespace std;
using namespace sf;

void back_end_game_won(RenderWindow& window)
{
	Image BackGround;
	BackGround.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/Won.png");
	Texture bg_t;
	bg_t.loadFromImage(BackGround);
	Sprite bg;
	bg.setTexture(bg_t);
	bg.setScale(0.835, 0.5);

	RectangleShape duller(Vector2f(window.getSize().x, window.getSize().y));
	duller.setFillColor(sf::Color(0, 0, 0, 128));

	Image Won_Text;
	Won_Text.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/You Won Text.png");
	Texture won_t;
	won_t.loadFromImage(Won_Text);
	Sprite won;
	won.setTexture(won_t);
	won.setScale(0.7, 0.7);
	won.setPosition(450, -10);

	sf::Font font;
	font.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Font Styles/Burbank Big Condensed Font.otf");

	Button Main_Menu("", 180, 90, 220, 200, sf::Color::Green, font, sf::Color::White, 28);
	Main_Menu.setlocation_text(1110, 650);
	sf::Image  Main_Menu_image;
	Main_Menu_image.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/menu.png");
	sf::Texture  Main_Menu_texture;
	Main_Menu_texture.loadFromImage(Main_Menu_image);
	Main_Menu.setTexture(&Main_Menu_texture);

	Button Play_Again("", 920, 150, 200, 70, sf::Color::Green, font, sf::Color::White, 28);
	Play_Again.setlocation_text(1110, 650);
	sf::Image Play_Again_image;
	Play_Again_image.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/play_again.png");
	sf::Texture Play_Again_texture;
	Play_Again_texture.loadFromImage(Play_Again_image);
	Play_Again.setTexture(&Play_Again_texture);

	Button Exit("", 560, 400, 200, 160, sf::Color::Green, font, sf::Color::White, 28);
	Exit.setlocation_text(1110, 650);
	sf::Image Exit_image;
	Exit_image.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/exit.png");
	sf::Texture Exit_texture;
	Exit_texture.loadFromImage(Exit_image);
	Exit.setTexture(&Exit_texture);

	Image won1;
	won1.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/won_1.png");
	Texture won_1t;
	won_1t.loadFromImage(won1);
	Sprite won_1s;
	won_1s.setTexture(won_1t);

	Image lost3;
	lost3.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/lost3.png");
	Texture lost3t;
	lost3t.loadFromImage(lost3);
	Sprite lost3s;
	lost3s.setTexture(lost3t);

	lost3s.setPosition(850, 280);
	won_1s.setPosition(40, 280);

	Exit.on_button(window);
	Main_Menu.on_button(window);
	Play_Again.on_button(window);
	window.draw(bg);
	window.draw(duller);
	window.draw(won);
	window.draw(won_1s);
	window.draw(lost3s);
	Main_Menu.drawTo(window);
	Play_Again.drawTo(window);
	Exit.drawTo(window);
	Exit.on_click(window, "Exit", currrent_stage, previous_stage);
	Main_Menu.on_click(window, "Homescreen", currrent_stage, previous_stage);
	Play_Again.on_click(window, "Levels Page", currrent_stage, previous_stage);
}