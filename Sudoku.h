#include <iostream>
class Sudoku{
    public:
        Sudoku();
        void CreateSudoku();
        void GiveQuestion();
        void ReadIn();
        void Solve();
        static const int sudoku_size=12;
        void Backtracking(int count);
        bool SudokuIsCorrect(int k,int i,int j);
        int GetNextZero(int i,int j);
        bool Check(int [],int c);
        void NumberMayBe(int i);
        static const int init_map[sudoku_size][sudoku_size];

    private:

        int map[sudoku_size][sudoku_size];
        int CreatingSudoku[sudoku_size][sudoku_size];
        int ans,a,b,c;
        bool NumberMayBe_array[9];

    };
