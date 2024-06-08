#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

class Button
{
protected:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Color color;
    sf::Text text;
    sf::RectangleShape shape;

public:
    //konstruktor 1
    Button(sf::Vector2f position, sf::Vector2f size, sf::Color color);

    //konstruktor 2
    Button(sf::Vector2f position, sf::Vector2f size, sf::Color color, std::string text_for_button, sf::Font &font);

    virtual void draw(sf::RenderWindow &window);
    bool isMouseOver(sf::RenderWindow &window);
};

class IconButton : public Button
{
    sf::Texture icon;
    sf::Sprite sprite;

public:
    IconButton(sf::Vector2f position, sf::Vector2f size, sf::Color color, std::string path_to_icon_image);
    void draw(sf::RenderWindow &window) override;
};

class TextButton : public Button
{
public:
    TextButton(sf::Vector2f position, sf::Vector2f size, sf::Color color, std::string text_for_button, sf::Font &font);
};

#endif
