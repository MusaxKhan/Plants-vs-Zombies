#pragma once
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
using namespace sf;
using namespace std;

#include "Button.h"
#include "TextBox.h"
#include "HomeScreen.h"
#include "Stages.h"
#include "Player.h"
void back_end_loginPage(RenderWindow& window, Button Back_btn, Event& event, TextBox& txt, player& admin)
{
	createBackground_Homescreen(window);
	Font font;
	if (!font.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Font Styles/Atop-R99O3.ttf"))
	{
		cout << "Error loading font file\n";
		return;
	}
	Texture backgroundTexture;
	if (!backgroundTexture.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/PopUp.png"))
	{
		cout << "Error loading background image\n";
		return;
	}
	Sprite backgroundSprite(backgroundTexture);
	backgroundSprite.setPosition((window.getSize().x - backgroundSprite.getLocalBounds().width) / 2,
		(window.getSize().y - backgroundSprite.getLocalBounds().height) / 2);

	Button submitButton("", 10000, 370, 155, 52, Color::White, font, Color::White, 20);
	submitButton.setlocation_text(10000, 370);

	sf::Image submit_button_image;
	submit_button_image.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/submit.png");

	sf::Texture submit_button_texture;
	submit_button_texture.loadFromImage(submit_button_image);

	submitButton.setTexture(&submit_button_texture);


	Text Prompt;
	Prompt.setFont(font);
	Prompt.setCharacterSize(30);
	Prompt.setFillColor(Color::Black);
	Prompt.setString("Enter Name:");
	Prompt.setPosition((window.getSize().x - Prompt.getLocalBounds().width) / 2, 280);

	Text inputText;
	inputText.setFont(font);
	inputText.setCharacterSize(30);
	inputText.setFillColor(Color::Black);
	inputText.setString("");
	inputText.setPosition(500, 345);
	if (event.type == Event::TextEntered)
	{
		txt.TakeInput(event, window);
	}
	if (Keyboard::isKeyPressed(Keyboard::Enter))
	{
		admin.setPlayer(txt.getString());
		currrent_stage = "Levels Page";
		previous_stage = "Login";
	}

	RectangleShape inputBox(Vector2f(300, 50));
	inputBox.setPosition((window.getSize().x - inputBox.getSize().x) / 2, 340);
	inputBox.setFillColor(Color::White);
	inputBox.setOutlineColor(Color::Black);
	inputBox.setOutlineThickness(1);

	Back_btn.drawTo(window);
	Back_btn.on_button(window);

	Back_btn.on_click(window, "Homescreen", currrent_stage, previous_stage);

	window.draw(backgroundSprite);
	window.draw(Prompt);
	window.draw(inputBox);
	window.draw(inputText);
	txt.drawTo(window);

	submitButton.on_click(window, "Levels Page", currrent_stage, previous_stage);
	submitButton.drawTo(window);



}
