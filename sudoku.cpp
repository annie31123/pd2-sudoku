#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "sudoku.h"

using namespace std;

const int init_map[sudoku_size][sudoku_size]={4,2,6,8,0,3,9,5,1,-1,-1,-1,
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
        map[i][j]=0;
}

void Sudoku::CreateSudoku(){

     for (int i=0;i<sudoku_size;i++){   //计縒-1
        for (int j=0;j<sudoku_size;j++){
            CreatingSudoku[i][j]=init_map[i][j]-1;
            if(CreatingSudoku[i][j]==0)
                CreatingSudoku[i][j]=9;
            if(CreatingSudoku[i][j]==-1)
                CreatingSudoku[i][j]=0;
            if(CreatingSudoku[i][j]==-2)
                CreatingSudoku[i][j]=-1;
        }
     }

     srand(time(NULL));   //玻ネ繦诀计>>ユ传2舱
     int a=rand()%9+1,b=rand()%9+1;
     if(a==3)
        a=9;
     for (int i=0;i<sudoku_size;i++){
        for (int j=0;j<sudoku_size;j++){
            if (CreatingSudoku[i][j]==3)
                CreatingSudoku[i][j]=a;
            else if(CreatingSudoku[i][j]==a)
                CreatingSudoku[i][j]=3;
        }
     }

     if(b==5)
        b=7;
     for (int i=0;i<sudoku_size;i++){
        for (int j=0;j<sudoku_size;j++){
            if (CreatingSudoku[i][j]==5)
                CreatingSudoku[i][j]=b;
            else if(CreatingSudoku[i][j]==b)
                CreatingSudoku[i][j]=5;
     }

}

void Sudoku::GiveQuestion(){
    Sudoku();
    CreateSudoku();

    for(int i=0;i<sudoku_size;i++)
        for (int j=0;j<sudoku_size;j++)
            map[i][j]=CreatingSudoku[i][j];

    for (int i=0;i<12;i++){         //计縒
        for(int j=0;j<12;j++)
            cout<<map[i][j]<<" ";
        cout<<"\n";
    }
}

void Sudoku::ReadIn(){
    Sodoku();   //耴箂'
    for(int i=0;i<12;i++)       //块计縒
        for(int j=0;j<12;j++)
            cin<<map[i][j];

}

void Sudoku::solve(){
    int choose[12]={},count=0;
    int i,j;
    for( i=0;i<12;i++){

        for( j=0;j<12;j++){
            if (map[i][j]==0)
                 count++;

        }
        Backtracking(count,i);


        //耴箂
        count=0;
    }
}




bool Sudoku::SudokuIsCorrect(int k,int i,int j){
    bool check_result;
    int check_array[12];


    for(int h=0;h<12;h++)
        check_array[h]=map[i][h];
    check_array[j]=k;
    check_result=Check(check_array);

    if (check_result==false)
        return false;


    for(int h=0;h<12;h++)
        check_array[h]=map[h][j];
    check_array[i]=k;
    check_result=Check(check_array);

    if (check_result==false)
        return false;


    return true;
}

int Sudoku::GetNextZero(int i,int j){
    for(;j<12;j++)
        if (map[i][j]==0)
            return j;

    return 13;
}

void Sudoku::Backtracking(int count, int i,int j){

    if (count==0)
        return;
    r[count-1]=j;
    j=GetNextZero(i,j);
    if(j==13)
        return;


        for( k=1;k<10;k++){
            if (SudokuIsCorrect(k,i,j)==true){
                map[i][j]=k;
                count--;
                Backtracking(count,i,j);

            }
             i=r[count];
        }

}


bool Sudoku::Check(int check_array[]){
    int count_array[9]={0};
    for(int i=0;i<12;i++){
        if(check_array[i]!=-1){
            count_array[check_array[i]-1]++;

        }

    for(int j=0;j<12;j++)
        if(ckeck_array[j]==2)
        return false;
    }

    return true;
}


