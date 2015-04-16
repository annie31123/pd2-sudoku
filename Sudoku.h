#include <iostream>
class Sudoku{
    public:
        Sudoku();
        void CreateSudoku();
        void GiveQuestion();
        void ReadIn();
        void Solve();
        static const int sudoku_size=12;
        void Backtracking(int m,int *prob[],int count);
        bool SudokuIsCorrect(int c,int* prob[],int m);
        int GetNextZero(int i,int j);
        bool Check(int [],int c);
        void NumberMayBe(int i);
        static const int init_map[sudoku_size][sudoku_size];
    
    private:
        
        int map[sudoku_size][sudoku_size];
        int CreatingSudoku[sudoku_size][sudoku_size];
        //int ans,a=0,b=0,c;
		int ans;
        bool NumberMayBe_array[9];

    };
