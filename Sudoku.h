#include <iostream>
class Sudoku{
    public:
        
        void CreateSudoku();
        void GiveQuestion();
        void ReadIn();
        void Solve();
        static const int sudoku_size=12;
        bool Backtracking(int m,int *prob[],int count);
        bool ReBacktracking(int m,int *prob[],int count);
        bool SudokuIsCorrect(int c,int* prob[],int m);
        bool Check(int [],int c);
        static const int init_map[sudoku_size][sudoku_size];
    
    private:
        
        int map[sudoku_size][sudoku_size];
        int CreatingSudoku[sudoku_size][sudoku_size];
        int ans;
        

    };
