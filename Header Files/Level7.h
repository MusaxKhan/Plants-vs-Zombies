#pragma once
#pragma once
#include <iostream>
#include "Levels.h"
#include "Sun.h"
#include "Screen_class.h"
#include "Plant Factory.h"
#include "Football Zombie.h"
#include "Zombie Factoryr.h"
#include "Seed.h"
#include "Button.h"
#include "settingsh.h"
using namespace std;


class Level7 : public Levels
{
    Seed** seed;
    Screen* lawn;
    bool a;
    int score;

public:
    Level7(RenderWindow& window) : Levels(0, 4)
    {
        window.setFramerateLimit(60);
        types_of_zombies = 5;
        total_plants = 6;
        num_of_LawnMowers = 5;

        seed = new Seed * [total_plants];
        int seeds_x = 33;
        sf::Font font;
        /////////////////////////////////////////////Back Button//////////////////////////////////////////////////////
        Button Back_btn("", 1050, 0, 200, 100, sf::Color::Green, font, sf::Color::White, 28);
        Back_btn.setlocation_text(1110, 10);

        sf::Image back_btn_image;
        back_btn_image.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/back.png");

        sf::Texture back_btn_texture;
        back_btn_texture.loadFromImage(back_btn_image);

        Back_btn.setTexture(&back_btn_texture);

        /////////////////////////////////////////////Settings Page//////////////////////////////////////////////////////
        BrightnessBar brightnessBar(510, 280, 250, 25, Color(0, 128, 0), Color::White, 1.0f);
        BrightnessBar VolumeBar(525, 360, 220, 25, Color(0, 128, 0), Color::White, 1.0f);
        sf::Music Homescreen_Music;
        Homescreen_Music.openFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Music/Homescreen_Grasswalk.ogg");
        bool music_home = true;
        sf::RectangleShape brightnessRect(sf::Vector2f(window.getSize().x, window.getSize().y));
        brightnessRect.setFillColor(sf::Color(0, 0, 0, 0));

        /////////////////////////////////////////////        Seeds           //////////////////////////////////////////////////////
        seed[0] = new Seed("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/peacard.png", seeds_x, 110, "Pea");
        seed[1] = new Seed("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/sunflowercard.png", seeds_x, 203, "Sun");
        seed[2] = new Seed("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/repeatercard.png", seeds_x, 296, "Rep");
        seed[3] = new Seed("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/card_wallnut.png", seeds_x, 388, "Wall");
        seed[4] = new Seed("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/snowcard.png", seeds_x, 482, "Snow");
        seed[5] = new Seed("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/cherrycard.png", seeds_x, 575, "Cherry");
        a = true;
        bool settings_page = false;
        lawn = new Screen("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/Night.png");
        TextBox txt("", 30, (window.getSize().x - (300.0 / 2)), 30, 30, 300, Color::Black, font, Color::White, Color::Black, false);
        String Score = "";
        score = 500;

        Dancer_Zombie db(grid);
        while (a)
        {
            window.clear();
            Score = to_string(score);
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();
            }
            draw_BackGround(window);
            drawBar(window);

            txt.drawTo(window);
            txt.setText(Score);

            Back_btn.drawTo(window);
            Back_btn.on_button(window);
            Back_btn.on_click(window, "Settings Page", currrent_stage, previous_stage);
            if (currrent_stage == "Settings Page")
            {
                settings_page = true;

            }
            while (settings_page)
            {
                window.display();
                back_end_settings_page(window, brightnessBar, VolumeBar, event, Homescreen_Music, brightnessRect);
                if (currrent_stage == "Level 7")
                    settings_page = false;
                if (currrent_stage == "Homescreen")
                {
                    cout << "Home" << endl;
                    settings_page = false;
                    a = false;
                }
            }
            for (int i = 0;i < total_plants;i++)
            {
                seed[i]->draw_on(window);
                seed[i]->drag_seed();
                if (seed[i]->drop_seed() && seed[i]->enough(score))
                {
                    int* cor = set_Coordinates(Mouse::getPosition(window).x, Mouse::getPosition(window).y, grid);
                    if (seed[i]->getName() != "Wall")
                    {
                        if (can_be_placed(grid, cor))
                        {
                            seed[i]->Decrement_Score(score);
                            Run_Plant_Factory(i, window, cor);
                        }
                    }
                    else
                    {
                       // Revolving only for Wallnut
                        if (can_be_placed(grid, cor))
                        {
                            if (can_be_placed(grid, cor, 1))
                            {
                                seed[i]->Decrement_Score(score);
                                Run_Plant_Factory(i, window, cor);
                            }
                        }
                    }
                }
                draw_Plants(window, i, types_of_zombies, zfac, grid, score);
            }


            for (int i = 0; i < types_of_zombies; i++) {
                zfac[i]->run_factory(window);
            }


           // sfac.run_factory(window, score);

            for (int i = 0;i < num_of_LawnMowers;i++)
            {
                mowers[i]->draw_on(window);
                mowers[i]->update(window, zfac, types_of_zombies, grid);
            }

            if (level_timer.getElapsedTime().asSeconds() >= time) {
                a = false;
                level_timer.restart();
                currrent_stage = "Game Won";
            }

            zombie_interaction(zfac, pfac, types_of_zombies, total_plants, grid, a);

            window.display();
        }
    }
    void draw_BackGround(RenderWindow& window)
    {
        lawn->draw_on(window);
    }
    void Run_Plant_Factory(int plant_no, RenderWindow& window, int* cor)
    {
        pfac[plant_no]->Run_factory(window, cor);
    }
    void drawBar(RenderWindow& window)
    {
        bar_texture.loadFromImage(bar_image);
        bar.setTexture(bar_texture);
        bar.setScale(0.79, 0.77);
        bar.setPosition(bar_x, bar_y);
        window.draw(bar);
        window.draw(replace);
        window.draw(box);
    }
    void draw_Plants(RenderWindow& window, int a, int types_of_zombies, Zombie_Factory** zfac, patch grid[][9], int& score)
    {
        pfac[a]->draw_Factory(window, types_of_zombies, zfac, grid, score);
        pfac[a]->move_plant(window, grid);
    }


};