#include <iostream>
class Sudoku{
    public:
        Sudoku();
        void CreateSudoku(const int init_map[]);
        
        void setMap();
        void GiveQuestion();
        void ReadIn();
        void solve();
        static const int sudoku_size=144;

        
    private:

    int map[sudoku_size];
    int CreatingSudoku[sudoku_size];
    
    
    };

