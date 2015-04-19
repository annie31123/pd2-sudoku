#include <iostream>
class Sudoku{
    public:
        
        void CreateSudoku();
        void GiveQuestion();
        void ReadIn();
        void Solve();
        static const int sudoku_size=12;
        void Backtracking(int m,int *prob[],int count);
        void ReBacktracking(int m,int *prob[],int count);
        bool SudokuIsCorrect(int c,int z[12][12],int* prob[],int m);
        bool Check(int [],int c);
        static const int init_map[sudoku_size][sudoku_size];
    
    private:
        
        int map[sudoku_size][sudoku_size];
      	int map2[sudoku_size][sudoku_size];
        int CreatingSudoku[sudoku_size][sudoku_size];
        int ans;
        

    };
