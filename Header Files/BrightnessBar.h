#pragma once
#include <iostream>
#include <string.h>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
using namespace sf;
using namespace std;

#ifndef BRIGHTNESS_H
#define BRIGHTNESS_H
class BrightnessBar
{

private:
    Vector2f m_position;
    Vector2f m_size;
    Color m_fillColor;
    Color m_outlineColor;
    float m_outlineThickness;
    float m_maxBrightness;
    float m_brightness;
    RectangleShape m_bar;

public:
    BrightnessBar(float x, float y, float width, float height, Color fillColor, Color outlineColor, float maxBrightness) :
        m_position(x, y),
        m_size(width, height),
        m_fillColor(fillColor),
        m_outlineColor(outlineColor),
        m_maxBrightness(maxBrightness),
        m_brightness(1.0f)
    {
        m_outlineThickness = 1.0f;
        m_bar.setFillColor(m_fillColor);
        m_bar.setOutlineColor(m_outlineColor);
        m_bar.setOutlineThickness(m_outlineThickness);
        updateBar();
    }

    void drawTo(RenderWindow& window)
    {
        window.draw(m_bar);
    }

    void updateBar()
    {
        m_bar.setPosition(m_position);
        m_bar.setSize(Vector2f(m_size.x * m_brightness, m_size.y));
    }

    void adjustBrightness(float brightness)
    {
        m_brightness = std::max(0.0f, std::min(brightness, m_maxBrightness));
        updateBar();
    }

    float getBrightness() const
    {
        return m_brightness;
    }

    RectangleShape get_bar()
    {
        return m_bar;
    }

    Vector2f getPosition()
    {
        return m_position;
    }

    Vector2f getSize()
    {
        return m_size;
    }

    void setSize(int n, int height)
    {
        m_size.x= n;
        m_size.y = height;
        updateBar();
    }
};

#endif