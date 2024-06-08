SUDOKU SOLVER
-------------
###Autor: Pola Dudek
### Krakow 2024
-------------

## Opis projektu:

Program służy do rozwiązywania poprawnie wprowadzonych plansz Sudoku. Plansza powinna zostać interaktywnie uzupełniona przez użytkownika.

## Najważniejsze elementy projektu:

Program podzielony jest na trzy moduły: `SudokuGrid`, `Buttons` oraz `SudokuApp`.

 * SudokuGrid:

Moduł ten zawiera abstrakcyjną klasę bazową `SudokuGrid`, po której dziedziczy klasa pochodna `SudokuFinished`. Klasa `SudokuFinished` ma następnie dwie klasy pochodne: `BacktrackingSolver` oraz `RandomFillSolver`.

- `SudokuGrid`: Zapewnia implementację planszy Sudoku.
- `SudokuFinished`: Odpowiada za wypełnioną wersję planszy.
- `BacktrackingSolver`: Implementuje algorytm backtrackingu rozwiązujący Sudoku, który zapewnia 100% poprawność zwracanych plansz.
- `RandomFillSolver`: Implementuje alternatywny "algorytm wypełniania planszy", powstal w celu lepszego zoobrazowania polimorfizmu.

Metoda `solve()` odpowiedzialna za wypełnianie planszy klasy `SudokuGrid` jest metodą czysto wirtualną, która zostaje nadpisana w klasach `BacktrackingSolver` oraz `RandomFillSolver`, używających różnych algorytmów.

* Buttons:

Moduł ten zawiera klasę bazową `Buttons`, posiadającą dwa różne konstruktory, oraz dwie klasy pochodne: `TextButton` i `ImageButton`. Obie klasy pochodne korzystają z jednego z dostępnych konstruktorów.

* SudokuApp:

Moduł odpowiada za GUI programu, napisany przy użyciu biblioteki SFML.

## Uruchomienie programu:

Aby skompilować i uruchomić program, należy użyć pliku CMake.

1. Nalezy otworzyc terminal i przejsc do folderu `SudokuSolver`.
2. Nastepnie nalezy przejsc do podfolderu `build`.
3. Kolejno nalezy wywolac CMake komenda "cmake ..".
4. Nastepnie nalezy skompilowac program, komenda "make":
5. Koncowo uruchomic program komenda "./sudoku".

## Projekt wymaga:

- standardu C++17
- CMake
- Bibliotekii SFML

