SUDOKU SOLVER
-------------
Pola Dudek, Krakow 2024

## Opis projektu:

Program sluzy do rozwiazywania poprawnie wprowadzonych plansz Sudoku. Plansza powinna zostac interaktywnie uzupelniona przez uzytkownika (wiecej informacji znajduje sie w przycisku "Pomoc" widocznym w programie).

## Glowne elementy projektu:

Program podzielony jest na trzy moduly: `SudokuGrid`, `Buttons` oraz `SudokuApp`.

 * SudokuGrid:

Modul ten zawiera abstrakcyjna klase bazowa SudokuGrid (z metoda czysto-wirtualna solve()), po ktorej hierarchicznie dziedziczy klasa pochodna SudokuFinished, nastepnie klasy BacktrackingSolver oraz RandomFillSolver.

- `SudokuGrid`: zapewnia implementacje pustej planszy Sudoku.
- `SudokuFinished`: odpowiada za wypelniona wersje planszy Sudoku.
- `BacktrackingSolver`: implementuje algorytm "backtrackingu" rozwiazujacy Sudoku, ktory zapewnia 100% poprawnosc zwracanych plansz.
- `RandomFillSolver`: implementuje alternatywny "algorytm wypełniania planszy"; klasa powstala przede wszytskim w celu lepszego zoobrazowania polimorfizmu.

* Buttons:

Modul ten zawiera klase bazowa `Buttons` oraz dwie klasy pochodne: `TextButton` i `ImageButton`, ktore odpowiadaja za przyciski uzywane w interfejsie programu.
W tym module znajduja sie funkcje "ladujace" pliki obrazow dla przyciskow -> Pliki te znajduja sie w folderze build.

* SudokuApp:

Modul odpowiada za GUI programu, napisany jest w oparciu o biblioteke SFML.

## Uruchomienie programu:

Aby skompilowac i uruchomic program, nalezy uzyc pliku CMake.

1. Nalezy otworzyc terminal i przejsc do folderu SudokuSolver np. komenda `"cd SudokuSolver"`.
2. Nastepnie nalezy przejsc do podfolderu build uzywajac komendy `"cd build"`.
3. Kolejno nalezy wywolac CMake komenda `"cmake .."`.
4. Nastepnie nalezy skompilowac program, komenda `"make"`:
5. Koncowo uruchomic program komenda `"./sudoku"`.
(Kroki 3, 4 i 5 powinny byc wciaz wykonywane w podfolderze build).

## Projekt wymaga:

- standardu C++17
- CMake 3.0
- Biblioteki SFML 2.5

