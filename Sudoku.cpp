#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "Sudoku.h"

using namespace std;

const int Sudoku::init_map[sudoku_size][sudoku_size]={{4,2,6,8,0,3,9,5,1,-1,-1,-1},
                         {0,0,3,9,5,0,6,0,4,-1,-1,-1},
                         {9,0,1,6,2,4,8,0,0,-1,-1,-1},
                         {-1,-1,-1,1,3,2,0,8,7,9,5,0},
                         {-1,-1,-1,0,8,0,1,9,0,4,2,0},
                         {-1,-1,-1,4,9,6,2,3,5,8,0,1},
                         {1,0,0,0,4,0,-1,-1,-1,6,9,5},
                         {0,0,4,0,6,0,-1,-1,-1,1,3,7},
                         {6,9,5,0,1,7,-1,-1,-1,0,8,4},
                         {3,1,2,-1,-1,-1,7,0,4,5,0,9},
                         {7,8,4,-1,-1,-1,0,6,9,3,0,2},
                         {0,6,0,-1,-1,-1,3,1,0,7,0,8}};

Sudoku::Sudoku(){
    for(int i=0;i<sudoku_size;i++)
        for(int j=0;j<sudoku_size;j++)
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
}

void Sudoku::GiveQuestion(){
    //Sudoku();
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
    //Sodoku();   //耴箂'
    for(int i=0;i<12;i++)       //块计縒
        for(int j=0;j<12;j++)
            cin>>map[i][j];

}

void Sudoku::Solve(){
        static int count=0;
    int i,j;
    for( i=0;i<12;i++)
        for( j=0;j<12;j++)
            if (map[i][j]==0)
                 count++;
    
    int *prob[count];
    
    for( i=11;i>-1;i--)
        for( j=11;j>-1;j--)
            if (map[i][j]==0)
                prob[count-1]=&map[i][j];count--;
    
    ans=0;
    Backtracking(0,prob,count);
        for (int i=0;i<12;i++){
            for(int j=0;j<12;j++)
                cout<<map[i][j]<<" ";
            cout<<"\n";
        }
    if (ans==0)
        cout<<"0"<<endl;
    if (ans==1){
        cout<<"1"<<endl;
        for (int i=0;i<12;i++){
            for(int j=0;j<12;j++)
                cout<<map[i][j]<<" ";
            cout<<"\n";
        }
    }
    if(ans==2)
        cout<<"2"<<endl;


}




bool Sudoku::SudokuIsCorrect(int c,int* prob[],int m){
    bool check_result;
    int check_array[12]={0};
    int i ,j,a,b;
    for( a=0;a<12;a++)
        for( b=0;b<12;b++)
            if(&map[a][b]==prob[m])
                i=a;j=b;
    

    for(int h=0;h<12;h++)
        check_array[h]=map[i][h];
   
    check_result=Check(check_array,c);

    if (check_result==false)
        return false;


    for(int h=0;h<12;h++)
        check_array[h]=map[h][j];
    
    check_result=Check(check_array,c);

    if (check_result==false)
        return false;


    int i1=i%3,j1=j%3;
    for(int h=0;h<9;h++)
        check_array[h]=map[i-i1+h/3][j-j1+h%3];
    check_array[9]=0,check_array[10]=0,check_array[11]=0;
    check_result=Check(check_array,c);

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
void Sudoku::Backtracking(int m,int *prob[],int count){
 if (m==count){
   for(int i=11;i>-1;i--)
        for(int j=11;j>-1;j--)
            if (&map[i][j]==prob[m])
                map[i][j]=*prob[m];m--;
	ans++;   
 return;
 }
   //    ans++;
 //   if(ans>=2)
   //     return;
            
                for(int c=1;c<10;c++){
                    if(*prob[m]==0){
                        if (SudokuIsCorrect(c,prob,m)==true){
                            *prob[m]=c;
                            
                            Backtracking(m+1,prob,count);
                        }
                    


                }


            }



        




}


bool Sudoku::Check(int check_array[],int c){
    bool count_array[9];
    for(int k=0;k<9;k++)
        count_array[k]=false;
    for(int k=0;k<12;k++)
        if(check_array[k]!=0&&check_array[k]!=-1)
            count_array[check_array[k]-1]=true;

    

    if(count_array[c-1]==true)
        return false;
    

    return true;
}

void Sudoku::NumberMayBe(int i){

    for(int k=0;k<9;k++){
        NumberMayBe_array[k]=false;
        NumberMayBe_array[map[i][k]-1]=true;
    }
}
