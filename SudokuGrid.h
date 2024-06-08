#ifndef SUDOKU_H
#define SUDOKU_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <random>

class SudokuGrid // klasa abstrakcyjna
{
private:
    std::vector<std::vector<int>> grid_;
    int full_square_size_ = 9;
    int smaller_squares_size_ = 3;

public:
    SudokuGrid(); 
    ~SudokuGrid() {}
    SudokuGrid(const SudokuGrid &other);

    int &operator()(int row, int col); // przeciazanie operatorow
    int operator()(int row, int col) const;
    void printingGrid() const;
    virtual bool solve() = 0; // metoda czysto wirtualna
    void clearingGrid();

protected:

    friend class SudokuApp; // deklaracja przyjaciela
};

class SudokuFinished : public SudokuGrid // dziedziczenie 
{
public:
    virtual bool solve() override = 0;
};

class BacktrackingSolver : public SudokuFinished
{
public:
    bool solve() override;
    int gettingCellValue(int row, int col) const;

private:
    bool findingEmptySpots(int &row, int &col) const;
    bool isValid(int row, int col, int num) const;
};

class RandomFillSolver : public SudokuFinished
{
public:
    bool solve() override; // polimorfizm
};

#endif
