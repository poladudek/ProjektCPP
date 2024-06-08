#include "Buttons.h"

Button::Button(sf::Vector2f position, sf::Vector2f size, sf::Color color) : position(position), size(size), color(color)
    {
    shape.setSize(size);
    shape.setPosition(position);
    shape.setFillColor(color);
    }

Button::Button(sf::Vector2f position, sf::Vector2f size, sf::Color color, std::string text_for_button, sf::Font &font)
    : Button(position, size, color)
    { 
    text.setString(text_for_button);
    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);
    text.setPosition(position.x + 10, position.y + 5); // odstep 10px od dolu i 5 od boku
    }

void Button::draw(sf::RenderWindow &window)
{
    window.draw(shape);
    window.draw(text);
}

bool Button::isMouseOver(sf::RenderWindow &window)
{
    sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
    return (mouse_position.x >= position.x && mouse_position.x <= position.x + size.x && mouse_position.y >= position.y && mouse_position.y <= position.y + size.y);
}

IconButton::IconButton(sf::Vector2f position, sf::Vector2f size, sf::Color color, std::string path_to_icon_image)
    : Button(position, size, color), icon(), sprite()
    {
        try // obsluga wyjatkow z uzyciem try i catch
        {
            if (!icon.loadFromFile(path_to_icon_image))
            {
                throw std::exception();
            }   
        }
        catch (const std::exception& the_exception)
        {
            std::cerr << "blad podczas ladowania pliku obrazu przycisku" << std::endl;
            exit(EXIT_FAILURE);
        }

    sprite.setTexture(icon);
    sprite.setScale(size.x / icon.getSize().x, size.y / icon.getSize().y);
    sprite.setPosition(position);
}

void IconButton::draw(sf::RenderWindow &window)
{
    Button::draw(window);
    window.draw(sprite);
}

TextButton::TextButton(sf::Vector2f position, sf::Vector2f size, sf::Color color, std::string text_for_button, sf::Font &font)
    : Button(position, size, color, text_for_button, font) {}
