#include <vector>
#include <fstream>
#include "sudoku.h"

using namespace std;
const int init_map[144]={4,2,6,8,0,3,9,5,1,-1,-1,-1,
                         0,0,3,9,5,0,6,0,4,-1,-1,-1,
                         9,0,1,6,2,4,8,0,0,-1,-1,-1,
                         -1,-1,-1,1,3,2,0,8,7,9,5,0,
                         -1,-1,-1,0,8,0,1,9,0,4,2,0,
                         -1,-1,-1,4,9,6,2,3,5,8,0,1,
                         1,0,0,0,4,0,-1,-1,-1,6,9,5,
                         0,0,4,0,6,0,-1,-1,-1,1,3,7,
                         6,9,5,0,1,7,-1,-1,-1,0,8,4,
                         3,1,2,-1,-1,-1,7,0,4,5,0,9,
                         7,8,4,-1,-1,-1,0,6,9,3,0,2,
                         0,6,0,-1,-1,-1,3,1,0,7,0,8};
Sudoku::Sudoku(){
    for(int i=0;i<sudoku_size;i++)
        map[i]=0;
}

void CreateSudoku(const int init_map[]){

     for (int i=0;i<sudoku_size;i++){
        CreatingSudoku[i]=init_map-1;
        if(CreatingSudoku[i]==0)
            CreatingSudoku[i]=9;
        if(CreatingSudoku[i]==-1)
            CreatingSudoku[i]=0;
        if(CreatingSudoku[i]==-2)
            CreatingSudoku[i]=-1;
     }

     srand(time(NULL));
     int a=rand()%9+1;
     if(a==3)
        a=9;
     for (int i=0;i<sudoku_size;i++){
        if (CreatingSudoku[i]==3)
            CreatingSudoku[i]=a;
        else if(CreatingSudoku[i]==a)
            CreatingSudoku[i]=3;
     }

}
void Sudoku::GiveQuestion(){
    


}
void Sudoku::ReadIn(){


}
void Sudoku::solve(){


}

