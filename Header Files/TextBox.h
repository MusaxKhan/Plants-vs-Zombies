#pragma 
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/OpenGL.hpp>
#include "Button.h"
#include <sstream>
using namespace sf;
using namespace std;

#ifndef TEXTBOX_H
#define TEXTBOX_H
//#define Enter 13
//#define Delete 8
//#define Escape 27
#define DELETE_KEY 8
#define ENTER_KEY 13

class TextBox
{
private:
    sf::Text txt;
    sf::RectangleShape shape;
    bool isSelected = false;
    bool hasLimit = false;
    int limit;
    ostringstream Text;

public:
    TextBox(string s, int size_txt, int x, int y, int length_b, int width_b, Color t_col, Font fo, Color fill_box, Color outline, bool se)
    {
        txt.setFont(fo);
        txt.setCharacterSize(size_txt);
        txt.setFillColor(t_col);
        txt.setString(s);
        txt.setPosition(826, 346);
        shape.setSize(sf::Vector2f(length_b, width_b));
        shape.setPosition(x - 10, y);
        shape.setFillColor(fill_box);
        shape.setOutlineColor(outline);
        shape.setOutlineThickness(1);
        hasLimit = true;
        isSelected = se;
        if (se)
        {
            txt.setString("_");
        }
        else
            txt.setString(" ");
    }
    void TakeInput(sf::Event& e, RenderWindow& window)
    {
        int character = e.text.unicode;
        if (character < 128)
        {
            InputChar(character);
        }
    }

    void InputChar(int character)
    {
        if ((character != DELETE_KEY) && (character != ENTER_KEY))
            Text << char(character);
        else if (character == DELETE_KEY)
        {
            if (Text.str().length() > 0)
            {
                BackspacePressed();
            }
        }
        txt.setString(Text.str() + "_");
    }

    void BackspacePressed()
    {
        string old = Text.str();
        string New = "";

        int length = old.length();

        for (int i = 0; i < length - 1; i++)
        {
            New += old[i];
        }
        Text.str("");
        Text << New;
        txt.setString(Text.str());
    }


    sf::Text getText() const
    {
        return txt;
    }

    void setText(const string& newText)
    {
        txt.setString(newText);
    }

    void setLimit(bool a)
    {
        hasLimit = a;
    }

    void setLimit(bool a, int b)
    {
        hasLimit = a;
        limit = b;
    }

    void set_select(bool a)
    {
        isSelected = a;
        if (!a)
        {
            string initial = Text.str();
            string new_s = "";
            for (int i = 0; i < initial.length() - 1; i++)
            {
                new_s = new_s + initial[i];
            }
            txt.setString(new_s);
        }
    }

    string getString()
    {
        return Text.str();
    }


    sf::Vector2f getPosition() const
    {
        return shape.getPosition();
    }

    void setPosition(float x, float y)
    {
        shape.setPosition(x, y);
        txt.setPosition(x, y);
    }

    void drawTo(RenderWindow& window)
    {
        sf::Font font;
        if (!font.loadFromFile("C:/Users/MK/OneDrive/Desktop/Plants vs Zombies/Project/Font Styles/Burbank Big Condensed Font.otf")) {
            std::cerr << "Failed to load font" << std::endl;
        }
        sf::Text txt2;
        txt2.setFont(font);
        txt2.setFillColor(sf::Color::Black);
        txt2.setPosition(500, 345);
        if (!isSelected)
        {
            txt2.setPosition(133, 30);
            txt2.setScale(1.5, 1.5);
        }
        txt2.setString(txt.getString());
        window.draw(txt2);
    }

    void add(char character)
    {
        if (hasLimit && Text.str().length() >= limit)
        {
            // Reached the limit, do not add more characters
            return;
        }

        Text << character;
        txt.setString(Text.str() + "_");
    }
};
#endif 
