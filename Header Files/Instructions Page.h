#pragma once
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
using namespace sf;
using namespace std;

#include  "Button.h"

void Backend_Instructions_Page(sf::RenderWindow& win,sf::Sprite background,Button back_btn) {
    back_btn.drawTo(win);
    back_btn.on_button(win);
    back_btn.on_click(win, previous_stage, currrent_stage, previous_stage);
    sf::Font font;
    if (!font.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Font Styles/Burbank Big Condensed Font.otf")) {
        std::cerr << "Failed to load font" << std::endl;
        return;
    }

    // Create text for instructions
    sf::Text instructions;
    instructions.setFont(font);
    instructions.setString(
        //"\n\n\n\n"
        "About the Game\n\n"
        "Plants vs Zombies is a popular tower defense game developed by E Developers in collaboration with FAST NUCES.\n"
        "In this game, players must defend their home from hordes of zombies by strategically placing various types of plants, "
        "each with unique abilities,\n to thwart the advancing undead.\n\n"
        "How to Play\n"
        "1. Objective: Protect your house from waves of zombies by placing defensive plants.\n\n"
        "2. Selecting Plants: Choose from a variety of plants, each with unique abilities.\n\n"
        "3. Placing Plants: Click or tap on the desired location in your backyard.\n\n"
        "4. Defending Against Zombies: Stop zombies from reaching your house by using your plants' abilities.\n\n"
        "5. Sun Collection: Collect sun to plant defensive plants. Sunflowers generate sun over time.\n\n"
        "6. Upgrades and Power-ups: Unlock new plants and abilities as you progress. Use power-ups strategically.\n\n"
        "7. Survival Mode: Challenge yourself in Survival Mode against increasingly difficult waves of zombies."
        "\n\n\nCredits\n"
        "- Developed by E Developers in collaboration with FAST NUCES\n"
        "- Game Design: Saad & Musa\n"
        "- Programming: Saad & Musa\n"
        "- Art and Animation: Saad & Musa\n"
        "- Music and Sound Effects: Saad & Musa\n"
        "- Special Thanks: Allah Almighty"
    );
    instructions.setCharacterSize(22);
    instructions.setFillColor(sf::Color::White);
    instructions.setPosition(20.f, 20.f);

    win.draw(instructions);
}