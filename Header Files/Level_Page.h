#pragma once
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
using namespace sf;
using namespace std;

#include  "Stages.h"
#include  "Button.h"
#include "Player.h"

void backend_Level_page(sf::RenderWindow& window, sf::Sprite level_menu_sprite, sf::Text levels_page_heading, Button back_btn, Button* Levels, player admin , Players p[3]) {

    Image name;
    name.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/bg.jpeg");
    Texture name_t;
    name_t.loadFromImage(name);
    Sprite name_s;
    name_s.setTexture(name_t);
    Sprite name_2_s;
    Sprite name_3_s;
    name_s.setScale(0.6, 0.45);
    name_2_s = name_3_s = name_s;


    Image newbie;
    newbie.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/newbie.png");
    Image veteran;
    veteran.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/veteran.png");
    Image master;
    master.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/conqueror.png");

    Texture newbie_text;
    newbie_text.loadFromImage(newbie);
    Texture veteran_text;
    veteran_text.loadFromImage(veteran);
    Texture master_text;
    master_text.loadFromImage(master);

    Sprite newbie_s;
    newbie_s.setTexture(newbie_text);
    Sprite veteran_s;
    veteran_s.setTexture(veteran_text);
    Sprite master_s;
    master_s.setTexture(master_text);

    sf::Font font;
    font.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Font Styles/Burbank Big Condensed Font.otf");

    Text name1;
    Text name2;
    Text name3;
    name1.setFont(font);
    name2.setFont(font);
    name3.setFont(font);

    bool adminUpdated = false;
    for (int i = 0; i < 3; i++) 
    {
        for (int i = 0;i < 3;i++)
        {
            if (admin.getName() == p[i].getname())
                adminUpdated = true;
        }
        if (admin.levelsUnlocked > p[i].getLevels() && !adminUpdated)
        {
            Players temp;
            Players temp2;
            temp = p[i];
            p[i].setname(admin.getName());
            p[i].setLevels(admin.levelsUnlocked);
            if (i < 2)
            {
                temp2 = p[i + 1];
                p[i + 1] = temp;
                if(i<1)
                    p[i + 2] = temp2;
            }
            adminUpdated = true;
        }
    }

    name1.setString(p[0].getname());
    name2.setString(p[1].getname());
    name3.setString(p[2].getname());
    name1.setFillColor(Color::White);
    name2.setFillColor(Color::White);
    name3.setFillColor(Color::White);

    // Locaton Settings of the badges
    newbie_s.setPosition(980, 280);
    newbie_s.setScale(0.4, 0.4);
    veteran_s.setPosition(700, 300);
    veteran_s.setScale(1, 1);
    master_s.setPosition(500, 300);
    master_s.setScale(0.5, 0.5);
    name_s.setPosition(510, 520);
    name_2_s.setPosition(750, 520);
    name_3_s.setPosition(1005, 520);
    name1.setPosition(546, 530);
    name2.setPosition(786, 530);
    name3.setPosition(1041, 530);

    window.draw(level_menu_sprite);
    window.draw(newbie_s);
    window.draw(veteran_s);
    window.draw(master_s);
    window.draw(name_s);
    window.draw(name_2_s);
    window.draw(name_3_s);
    window.draw(name1);
    window.draw(name2);
    window.draw(name3);

    //Font
    window.draw(levels_page_heading);

    //Back Button    
    back_btn.drawTo(window);
    back_btn.on_button(window);
    back_btn.on_click(window, previous_stage, currrent_stage, previous_stage);

    //Levels icon
   for (int i = 0; i < admin.levelsUnlocked; i++) {
    Levels[i].drawTo(window);
    Levels[i].on_click(window, ("Level " + to_string(i + 1)), currrent_stage, previous_stage);
   // Levels[i].on_button(window);

}

}