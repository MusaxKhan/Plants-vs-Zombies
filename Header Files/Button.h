#include <iostream>
#include <string.h>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
using namespace sf;
using namespace std;

#ifndef BUTTON_H
#define BUTTON_H



class Button
{
private:
    sf::RectangleShape button;
    sf::Text txt;
    int x_cord;
    int y_cord;

public:
    Button() {

    }

    Button(string t, int location_x, int location_y, int size_x, int size_y, sf::Color clr, sf::Font& fnt, sf::Color bgcolor, int character_size) {
        //button
        button.setPosition(location_x, location_y);
        button.setFillColor(bgcolor);
        button.setSize(sf::Vector2f(size_x, size_y));
        //Text
        txt.setFillColor(clr);
        txt.setString(t);
        txt.setCharacterSize(character_size);
        txt.setPosition(location_x + size_x / 3 + 60, location_y + size_y / 3);
        //txt.setStyle(sf::Text::Bold);

        txt.setFont(fnt);

        //Location
        x_cord = location_x;
        y_cord = location_y;
    }

    // Getters
    sf::RectangleShape getButton() {
        return button;
    }

    sf::Text getText() {
        return txt;
    }

    float getX() const {
        return x_cord;
    }

    float getY() const {
        return y_cord;
    }

    void setBorder()
    {
        button.setOutlineColor(Color::Black);
    }

    // Setters
    void setPosition(int new_pos_x, int new_pos_y) {
        button.setPosition(new_pos_x, new_pos_y);
    }

    void setText(sf::Text newText) {
        txt = newText;
    }

    void setlocation_button(int newlocation_x, int newlocation_y) {
        button.setPosition(newlocation_x, newlocation_y);
    }
    void setlocation_text(int newlocation_x, int newlocation_y) {
        txt.setPosition(newlocation_x, newlocation_y);
    }

    //Texture Gift
    void setTexture(Texture* txture) {
        button.setTexture(txture);
    }



    //Draw
    void drawTo(sf::RenderWindow& win) {
        win.draw(button);
        win.draw(txt);
    }

    //Mouse Hover
    bool on_button(sf::RenderWindow& win) {
        int mouse_x = sf::Mouse::getPosition(win).x;
        int mouse_y = sf::Mouse::getPosition(win).y;

        int btn_x = getX() + button.getLocalBounds().width;
        int btn_y = getY() + button.getLocalBounds().height;

        if (mouse_x < btn_x && mouse_x > getX() && mouse_y < btn_y && mouse_y > getY()) {
            if (button.getTexture()) {
                txt.setFillColor(Color::Red);
                button.setScale(1.1, 1.1);            }
            else {
                sf::Color myColor = sf::Color(0, 100, 0);
                button.setFillColor(myColor);
            }

            return true;
        }
        else {
            if (button.getTexture()) {
                txt.setFillColor(Color::Green);
                button.setScale(1, 1);
            }
            else {
                button.setFillColor(sf::Color::Green);
            }

            return false;

        }

    }

    bool on_click(sf::RenderWindow& win, string next_stage, string& stage, string& previous_stage) {

        if (on_button(win)) {
            previous_stage = stage;
            stage = next_stage;
            return true;
        }
        return false;
    }

    void increase_text_size(int x, int y)
    {
        txt.setCharacterSize(x);
    }


};
#endif // !BUTTON.H

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                                                                                                 ///
///                                                                                                                                 ///
///                                                  Home-Screen  Definations                                                       ///
///                                                                                                                                 ///
///                                                                                                                                 ///
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
