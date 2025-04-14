#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
using namespace sf;
using namespace std;


#include "HomeScreen.h"
#include "Level_Page.h"
#include "Instructions Page.h"
#include "LoginPage.h"
#include "Settingsh.h"
#include "BrightnessBar.h"
#include "Game.h"
#include "Patch.h"
#include "Sun.h"
#include "TextBox.h"
#include "Lost ending.h"


#include "Level1.h"
#include "Levels.h"
#include "Football Zombie.h"
//#include "E_Devs.h"

int main()
{
    srand(time(0));
    Game* play;
    // Create a window, n*n
    RenderWindow window(VideoMode(1280, 720), "Plants Vs Zombies", Style::Titlebar | Style::Close | Style::Resize);
    // Game icon
    Image icon;
    if (!icon.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/icon.png"))
    {
        return 1;
    }

    sf::Font font;
    if (!font.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Font Styles/Burbank Big Condensed Font.otf")) {
        std::cerr << "Failed to load font" << std::endl;
        return 69;
    }

    window.setIcon(32, 32, icon.getPixelsPtr());


    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///                                                                                                                                 ///
    ///                                                                                                                                 ///
    ///                                                  Home-Screen  Definations                                                       ///
    ///                                                                                                                                 ///
    ///                                                                                                                                 ///
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Button play_btn("Play", 530, 600, 200, 50, sf::Color::White, font, sf::Color::Green, 28);
    play_btn.setlocation_text(610, 610);

    Button Intruction_btn("Instruction", 100, 600, 200, 50, sf::Color::White, font, sf::Color::Green, 28);
    Intruction_btn.setlocation_text(150, 610);

    /*Button Levels_btn("Levels", 100, 600, 200, 50, sf::Color::White, font, sf::Color::Green, 28);
    Levels_btn.setlocation_text(170, 610);*/

    Button Settings_btn("Settings", 1000, 600, 200, 50, sf::Color::White, font, sf::Color::Green, 28);
    Settings_btn.setlocation_text(1060, 610);

    Texture map_image[509];
    int frame_num = 0;
    Clock frame_clock;


    string path = "C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/snaps/mainmenu- (";

    //for (int i = 0; i < 509; i++)
    //{
    //    string pathee = path + to_string(i + 1) + ").png";

    //    map_image[i].loadFromFile(pathee);
    //}



    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///                                                                                                                                 ///
    ///                                                                                                                                 ///
    ///                                                  Loading Screen  Definations                                                    ///
    ///                                                                                                                                 ///
    ///                                                                                                                                 ///
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    sf::Image e_dev_image;
    e_dev_image.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/Logo2.png");

    sf::Texture bg_texture;
    bg_texture.loadFromImage(e_dev_image);

    sf::Sprite e_dev_bg_sprite;
    e_dev_bg_sprite.setTexture(bg_texture);

    e_dev_bg_sprite.setScale(float(window.getSize().x) / e_dev_image.getSize().x, float(window.getSize().y) / e_dev_image.getSize().y);
    e_dev_bg_sprite.setPosition(0, 0);

    clock_t start = clock();

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///                                                                                                                                 ///
    ///                                                                                                                                 ///
    ///                                                  Levels Menu  Definations                                                       ///
    ///                                                                                                                                 ///
    ///                                                                                                                                 ///
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Background Image of Levels Screen
    sf::Image level_menu_image;
    level_menu_image.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/levels-menu.jpg");

    sf::Texture level_menu_texture;
    level_menu_texture.loadFromImage(level_menu_image);

    sf::Sprite level_menu_sprite;
    level_menu_sprite.setTexture(level_menu_texture);

    level_menu_sprite.setScale(float(window.getSize().x) / level_menu_image.getSize().x, float(window.getSize().y) / level_menu_image.getSize().y);
    level_menu_sprite.setPosition(0, 0);

    const int num_of_levels = 7;

    //Level Page Heading
    sf::Text levels_page_heading;
    levels_page_heading.setCharacterSize(40);
    levels_page_heading.setFillColor(sf::Color::Green);
    levels_page_heading.Bold;
    levels_page_heading.setLetterSpacing(2);
    levels_page_heading.setString("Choose a Level");
    levels_page_heading.setPosition(530, 30);
    levels_page_heading.setFont(font);

    // Level Icons

    Button Levels[num_of_levels] = {
        Button("", 150, 100, 174, 192, sf::Color::Green,font,sf::Color::White, 28),
        Button("", 350, 100, 174, 192, sf::Color::Green,font,sf::Color::White, 28),
        Button("", 550, 100, 174, 192, sf::Color::Green,font,sf::Color::White, 28),
        Button("", 750, 100, 174, 192, sf::Color::Green,font,sf::Color::White, 28),
        Button("", 950, 100, 174, 192, sf::Color::Green,font,sf::Color::White, 28),
        Button("", 150, 300, 174, 192, sf::Color::Green,font,sf::Color::White, 28),
        Button("", 350, 300, 174, 192, sf::Color::Green,font,sf::Color::White, 28),
    };

    sf::Image level1_icon_image;
    level1_icon_image.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/L1.png");
   
    sf::Image level2_icon_image;
    level2_icon_image.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/L2.png");
   
    sf::Image level3_icon_image;
    level3_icon_image.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/L3.png");
   
    sf::Image level4_icon_image;
    level4_icon_image.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/L4.png");
   
    sf::Image level5_icon_image;
    level5_icon_image.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/L5.png");

    sf::Image level6_icon_image;
    level6_icon_image.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/L6.png");

    sf::Image level7_icon_image;
    level7_icon_image.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/L7.png");



    sf::Texture level1_icon_texture;
    level1_icon_texture.loadFromImage(level1_icon_image);

    sf::Texture level2_icon_texture;
    level2_icon_texture.loadFromImage(level2_icon_image);

    sf::Texture level3_icon_texture;
    level3_icon_texture.loadFromImage(level3_icon_image);

    sf::Texture level4_icon_texture;
    level4_icon_texture.loadFromImage(level4_icon_image);

    sf::Texture level5_icon_texture;
    level5_icon_texture.loadFromImage(level5_icon_image);

    sf::Texture level6_icon_texture;
    level6_icon_texture.loadFromImage(level6_icon_image);

    sf::Texture level7_icon_texture;
    level7_icon_texture.loadFromImage(level7_icon_image);

    Levels[0].setTexture(&level1_icon_texture);
    Levels[1].setTexture(&level2_icon_texture);
    Levels[2].setTexture(&level3_icon_texture);
    Levels[3].setTexture(&level4_icon_texture);
    Levels[4].setTexture(&level5_icon_texture);
    Levels[5].setTexture(&level6_icon_texture);
    Levels[6].setTexture(&level7_icon_texture);


    //Back Button
    Button Back_btn("", 1050, 620, 200, 100, sf::Color::Green, font, sf::Color::White, 28);
    Back_btn.setlocation_text(1110, 650);

    sf::Image back_btn_image;
    back_btn_image.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/back.png");

    sf::Texture back_btn_texture;
    back_btn_texture.loadFromImage(back_btn_image);

    Back_btn.setTexture(&back_btn_texture);

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///                                                                                                                                 ///
    ///                                                                                                                                 ///
    ///                                                  Music   Definations                                                            ///
    ///                                                                                                                                 ///
    ///                                                                                                                                 ///
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    sf::Music Homescreen_Music;
    if (!Homescreen_Music.openFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Music/Homescreen_Grasswalk.ogg")) {
        std::cerr << "Failed to load background music" << std::endl;
        return 0;
    }
    bool music_home = true;


    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///                                                                                                                                 ///
    ///                                                                                                                                 ///
    ///                                                  Instructions   Definations                                                     ///
    ///                                                                                                                                 ///
    ///                                                                                                                                 ///
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    sf::Image instruction_menu_image;
    instruction_menu_image.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/masood.jpg");

    sf::Texture instruction_menu_texture;
    instruction_menu_texture.loadFromImage(instruction_menu_image);

    sf::Sprite instruction_menu_sprite;
    instruction_menu_sprite.setTexture(instruction_menu_texture);

    sf::Texture background_login_Texture;
    if (!background_login_Texture.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Images/PopUp.png"))
    {
        cout << "Error loading background image/n";
        return 0;
    }
    sf::Sprite background_login_Sprite(background_login_Texture);
// 
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///                                                                                                                                 ///
    ///                                                                                                                                 ///
    ///                                                     Settings Definations                                                        ///
    ///                                                                                                                                 ///
    ///                                                                                                                                 ///
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    BrightnessBar brightnessBar(510, 280, 250, 25, Color(0, 128, 0), Color::White, 1.0f);
    BrightnessBar VolumeBar(525, 360, 220, 25, Color(0, 128, 0), Color::White, 1.0f);

    sf::RectangleShape brightnessRect(sf::Vector2f(window.getSize().x, window.getSize().y));
    brightnessRect.setFillColor(sf::Color(0, 0, 0, 0)); // Dark semi-transparent color


    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///                                                                                                                                 ///
    ///                                                                                                                                 ///
    ///                                                     Settings Definations                                                        ///
    ///                                                                                                                                 ///
    ///                                                                                                                                 ///
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Button* slot = new Button[5]{
        Button("", 0, 0, 120, 75, sf::Color::White, font, sf::Color::White, 28),
        Button("", 0, 75, 120, 75, sf::Color::White, font, sf::Color::White, 28),
        Button("", 0, 150, 120, 75, sf::Color::White, font, sf::Color::White, 28),
        Button("", 0, 225, 120, 75, sf::Color::White, font, sf::Color::White, 28),
        Button("", 0, 300, 120, 75, sf::Color::White, font, sf::Color::White, 28),
    };



    Sun my_sun;


    // Create Patches for the game
    patch pat[5][9];
    setPatch(pat);

    // Array of pointers to Football Zombies
    int initialCapacity = 5;
    Football_Zombie** zombies = new Football_Zombie * [initialCapacity];
    int numZombies = 0;
    int capacity = initialCapacity;

    // Variables to track time for Football Zombie creation
    sf::Clock zombieClock;
    float lastZombieTime = 0;
    const float zombieCreationInterval = 2.0f; // Interval in seconds

    //////////////////////////////////////////////////////////////////////////////////

    // Array of pointers to Suns
    const int initialSunCapacity = 10;
    Sun** suns = new Sun * [initialSunCapacity];
    int numSuns = 0;
    int sunCapacity = initialSunCapacity;

    // Variables to track time for Sun creation
    sf::Clock sunClock;
    float lastSunTime = 0;
    const float sunCreationInterval = 7.0f; // Interval in seconds

    TextBox txt("", 30, (window.getSize().x - (300.0 / 2)), 330, 300, 300, Color::Black, font, Color::White, Color::Black, true);

    int level = 1;
    sf::Clock clock2;
    float lastTime = 0;
    Players p[3];
    while (window.isOpen())
    {
        window.setFramerateLimit(60);
        //currrent_stage = "";
        //playBackgroundMusic();
        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();

        // Check if 5 seconds have elapsed
        if ((clock() - start) / CLOCKS_PER_SEC < 5)
        {
            window.draw(e_dev_bg_sprite);
        }

        else if (currrent_stage == "Homescreen") {


            if (music_home) {
                Homescreen_Music.play();
                Homescreen_Music.setVolume(100);
                music_home = false;
            }
           // backend_homescreen(window, play_btn, Settings_btn,Intruction_btn,map_image,frame_num, frame_clock);
            backend_homescreen(window, play_btn, Settings_btn, Intruction_btn);
        }
        else if (currrent_stage == "Levels Page") {
            backend_Level_page(window, level_menu_sprite, levels_page_heading, Back_btn, Levels, admin, p);
        }
        else if (currrent_stage == "Instruction Page") {
            Backend_Instructions_Page(window, instruction_menu_sprite, Back_btn);
        }
        else if (currrent_stage == "Login") {
            back_end_loginPage(window, Back_btn, event, txt, admin);
        }
        else if (currrent_stage == "Settings Page") {
            back_end_settings_page(window, brightnessBar, VolumeBar, event, Homescreen_Music, brightnessRect);
        }
        else if (currrent_stage == "Level 1")
        {
            Game play(1, pat, window);
        }
        else if (currrent_stage == "Level 2")
        {
            Game play(2, pat, window);
        }
        else if (currrent_stage == "Level 3")
        {
            Game play(3, pat, window);
        }
        else if (currrent_stage == "Level 4")
        {
            Game play(4, pat, window);
        }
        else if (currrent_stage == "Level 5")
        {
            Game play(5, pat, window);
        }
        else if (currrent_stage == "Level 6")
        {
            Game play(6, pat, window);
        }
        else if (currrent_stage == "Level 7")
        {
            Game play(7, pat, window);
        }
        else if (currrent_stage == "Exit")
        {
            window.close();
        }
        else if (currrent_stage == "Game Won")
        {
            back_end_game_won(window);
        }
        else if (currrent_stage == "Game Lost")
        {
            backend_lost_game(window);
        }
        window.draw(brightnessRect);
        window.display();
    }









    //Dynamic memory Deletion
    delete[] slot;

    // Clean up allocated memory
    for (int i = 0; i < numZombies; ++i)
    {
        delete zombies[i];
    }
    delete[] zombies;

    //return 0;
}