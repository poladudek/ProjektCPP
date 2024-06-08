#include "SudokuApp.h"

SudokuApp::SudokuApp()
    : window(sf::VideoMode(450, 550), "Sudoku Solver", sf::Style::Close), /* tryb close - nie mozna powiekszac okna*/
    solveButton(sf::Vector2f(50, 480), sf::Vector2f(50, 50), sf::Color::White, "solverbutton.png"),
    clearButton(sf::Vector2f(150, 480), sf::Vector2f(50, 50), sf::Color::White, "clearbutton.png"), 
    helpButton(sf::Vector2f(250, 480), sf::Vector2f(120, 40), sf::Color::Black, "Pomoc", font), 
    selected_cell(-1, -1), user_input_number(-1)
    {
        if (!font.loadFromFile("Arial.ttf"))
        {
            std::cerr << "blad podczas ladowania czcionki." << std::endl;
        }

        /* poczatkowa inicjalizacja planszy gdy program jest uruchamiany pierwszy raz */
        plansza(0, 2) = 3; // pierwszy indeks wiersz, drugi kolumna
        plansza(0, 3) = 6;
        plansza(0, 5) = 5;
        plansza(0, 6) = 8;
        plansza(1, 1) = 7;
        plansza(1, 4) = 9;
        plansza(1, 7) = 2;
        plansza(2, 0) = 5;
        plansza(2, 4) = 3;
        plansza(2, 8) = 4;
        plansza(3, 0) = 6;
        plansza(3, 1) = 3;
        plansza(3, 4) = 8;
        plansza(3, 7) = 7;
        plansza(4, 2) = 7;
        plansza(4, 3) = 9;
        plansza(4, 5) = 1;
        plansza(5, 0) = 1;
        plansza(7, 2) = 8;
        plansza(6, 4) = 2;
        plansza(8, 4) = 4;
        plansza(6, 6) = 5;
        plansza(7, 7) = 9;
    }

void SudokuApp::run()
{
    while (window.isOpen())
    {
        processingEvents();
        render();
    }
}

void SudokuApp::processingEvents() /* obsluga eventow: zamkniecie + przyciski myszy + wprowadzanie z klawiatury */
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        } 
        else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) 
        {
            handlingMouse(sf::Mouse::getPosition(window));
        } 
        else if (event.type == sf::Event::TextEntered)
        {
            handlingInput(event.text.unicode);
        }
    }
}

void SudokuApp::render()
{
    sf::Color lightPowderPink(235, 214, 223); /* wartosci kolorow - RGB */
    sf::Color darkerBrown(92, 64, 51);
    sf::Color lightBrown(172, 133, 138);

    window.clear(sf::Color::White);
    const int size_of_cell = 50;
    
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            int value = plansza.gettingCellValue(i, j);
            sf::RectangleShape cell(sf::Vector2f(size_of_cell, size_of_cell)); 
            cell.setPosition(j * size_of_cell, i * size_of_cell);
            cell.setOutlineThickness(1);
            cell.setOutlineColor(darkerBrown);
            window.draw(cell);

            if (selected_cell.x == j && selected_cell.y == i)
            {
                cell.setFillColor(lightBrown);
                window.draw(cell);
            }

            if (value != 0) 
            {
                sf::Text text(std::to_string(value), font, 20);
                text.setFillColor(darkerBrown);
                text.setPosition(j * size_of_cell + 15, i * size_of_cell + 10);
                window.draw(text);
            }

            /* "pogrubianie" mniejszych kwadratow */
            if ((j + 1) % 3 == 0 && j != 9)
            {
                sf::RectangleShape thickLine(sf::Vector2f(3, size_of_cell * 9));
                thickLine.setPosition((j + 1) * size_of_cell - 2, 0);
                thickLine.setFillColor(darkerBrown);
                window.draw(thickLine);
            }
            if ((i + 1) % 3 == 0 && i != 9)
            {
                sf::RectangleShape thickLine(sf::Vector2f(size_of_cell * 9, 3));
                thickLine.setPosition(0, (i + 1) * size_of_cell - 2);
                thickLine.setFillColor(darkerBrown);
                window.draw(thickLine);
            }
        }
    }

    solveButton.draw(window);
    helpButton.draw(window);
    clearButton.draw(window);

    window.display();
}

void SudokuApp::handlingMouse(sf::Vector2i mouse_position)
{
    static const int size_of_cell = 50;
    if (solveButton.isMouseOver(window))
    {
        plansza.solve();
    }
    else if (clearButton.isMouseOver(window))
    {
        plansza.clearingGrid();
    } 
    else if (helpButton.isMouseOver(window))
    {
        displayingHelp();
    }
    else if (mouse_position.x >= 0 && mouse_position.x < 450 && mouse_position.y >= 0 && mouse_position.y < 450)
    {
        selected_cell.x = mouse_position.x / size_of_cell;
        selected_cell.y = mouse_position.y / size_of_cell;
    }
}

void SudokuApp::handlingInput(sf::Uint32 unicode) // 32 bity -> 4 bajty
{
    if (selected_cell.x >= 0 && selected_cell.y >= 0)
    {
        if (unicode >= '1' && unicode <= '9')
        {
            user_input_number = unicode - '0';
            plansza(selected_cell.y, selected_cell.x) = user_input_number;
        }
        else if (unicode == '0' || unicode == 8)
        {
            plansza(selected_cell.y, selected_cell.x) = 0;
        }
    }
}

void SudokuApp::displayingHelp()
{
    sf::RenderWindow helpWindow(sf::VideoMode(400, 300), "Pomoc", sf::Style::Close);
    
    if (!font.loadFromFile("Arial.ttf"))
    {
        std::cerr << "blad podczas ladowania czcionki" << std::endl;
    }

    sf::Text helpText;
    helpText.setFont(font);
    helpText.setCharacterSize(16);
    helpText.setString("SUDOKU SOLVER:\n\nProgram sluzy do rozwiazywania plansz sudoku.\n\nIkony kolejno pierwsza od lewej oznaczaja:\n roziwazanie planszy, wyczyszczenie planszy.\n\nAby wypelniac plansze nalezy zaznaczyc komorke,\na nastepnie uzywajac klawatury wprowadzic cyfre\n z zakresu 1-9.\n\nAby manualnie usunac cyfre\n nalezy wprowadzic na klawiaturze zero,\n badz uzyc przycisku delete/backspace\n w zaleznosci od klawiatury.\n\n");
    helpText.setPosition(20, 20);
    helpText.setColor(sf::Color::Black);

    while (helpWindow.isOpen())
    {
        sf::Event event;
        while (helpWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                helpWindow.close();
            }
        }
        helpWindow.clear(sf::Color::White);
        helpWindow.draw(helpText);
        helpWindow.display();
    }
}