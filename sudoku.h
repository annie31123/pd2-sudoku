#include <iostream>
class Sudoku{
    public:
        Sudoku();
        void CreateSudoku();

        void setMap();
        void GiveQuestion();
        void ReadIn();
        void solve();
        static const int sudoku_size=12;
        void Backtracking();
        bool SudokuIsCorrect(int k,int i,int j);
        int GetNextZero(int i,int j);
    private:

    int map[sudoku_size][sudoku_size];
    int CreatingSudoku[sudoku_size][sudoku_size];


    };

