#ifndef SUDOAPP_H
#define SUDOAPP_H

#include <SFML/Graphics.hpp>
#include "SudokuGrid.h"
#include "Buttons.h"

class SudokuApp
{
private:
    BacktrackingSolver plansza;
    sf::RenderWindow window;
    sf::Font font;
    IconButton solveButton;
    TextButton helpButton;
    IconButton clearButton;
    sf::Vector2i selected_cell;
    int user_input_number;
    
public:
    SudokuApp();
    void run();

private:
    void processingEvents();
    void render();
    void handlingMouse(sf::Vector2i mousePos);
    void handlingInput(sf::Uint32 unicode);
    void displayingHelp();
};

#endif
