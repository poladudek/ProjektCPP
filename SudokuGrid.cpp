#include "SudokuGrid.h"

SudokuGrid::SudokuGrid() : grid_(9, std::vector<int>(9, 0)) {}

SudokuGrid::SudokuGrid(const SudokuGrid &other) : 
grid_(other.grid_), full_square_size_(other.full_square_size_), smaller_squares_size_(other.smaller_squares_size_) {}

int &SudokuGrid::operator()(int row, int col)
{ 
    return grid_[row][col];
}

int SudokuGrid::operator()(int row, int col) const
{ 
    return grid_[row][col];
}

void SudokuGrid::printingGrid() const
{
    for (const auto &row : grid_) // petla zakresowa
    {
        for (int num : row)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

void SudokuGrid::clearingGrid()
{
    for (auto& row : grid_)
    {
        for (auto it = row.begin(); it != row.end(); ++it) // jawny iterator
        {
            *it = 0; /* zgodnie z konwencja; 0 na planszy oznacza ze dana komorka jest pusta */
        }
    }
}

bool BacktrackingSolver::isValid(int row, int col, int num) const /* funkcja sprawdza czy wpisana liczba jest zgodna z zasadami sudoku */
{
    for (int i = 0; i < 9; ++i)
    {
        if ((*this)(row, i) == num || (*this)(i, col) == num) /* sprawdzam czy liczba do wpisania istnieje juz w danym wierszu i kolumnie */
        {
            return false;
        }
    }
    /* sprawdzam w mniejszym kwadracie  */
    int startRow = row - (row % 3);
    int startCol = col - (col % 3);

    for (int i = startRow; i < startRow + 3; ++i)
    {
        for (int j = startCol; j < startCol + 3; ++j)
        {
            if ((*this)(i, j) == num)
            {
                return false; 
            }
        }
    }

    return true;
}

bool BacktrackingSolver::solve() // funkcja solve() jako implementacja algorytmu backtrackingu
{
    int row, col;

    if (findingEmptySpots(row, col) == false)
    {
        return true; /* <--- konczy dzialanie funkcji solve() */
    }

    for (int num = 1; num <= 9; ++num)
    {
        if (isValid(row, col, num)) 
        {
            (*this)(row, col) = num; 

            if (solve()) /* rekurencyjne wywolanie */
            {
                return true;
            }
            (*this)(row, col) = 0; 
        }
    }
    return false; /* jezeli nie mozna wstawic zadnej liczby algorytm "cofa sie" */
}

int BacktrackingSolver::gettingCellValue(int row, int col) const
{
    return (*this)(row, col);
}

bool BacktrackingSolver::findingEmptySpots(int &row, int &col) const
{
    for (row = 0; row < 9; ++row)
    {
        for (col = 0; col < 9; ++col)
        {
            if ((*this)(row, col) == 0)
            {
                return true;
            }
        }
    }
    return false; /* jezeli nie znajduja sie juz zadne! puste komorki funkcja zwraca falsz */
}

// W celu lepszego ukazania poliformizmu; funkcja ktora wypelnia sudoku ale szansa poprawnej planszy praktycznie nieistnieje
bool RandomFillSolver::solve() 
{
    std::vector<int> numbers(9);
    int helper = 1;

    for (int i = 0; i < 9; ++i)
    {
        numbers[i] = helper;
        ++helper;
    }

    std::random_device seed; /* generowanie ziarna dla MT */
    std::mt19937 generating(seed()); /* Mersenne Twister  */
    std::shuffle(numbers.begin(), numbers.end(), generating); // algorytm std::

    int index = 0;
    for (int row = 0; row < 9; ++row)
    {
        for (int col = 0; col < 9; ++col)
        {
            (*this)(row, col) = numbers[index];
            index = (index + 1) % 9; /* poruszanie sie po indeksach jak po buforze cyklicznym */
        }
    }
    return true;
}
