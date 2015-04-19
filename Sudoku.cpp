#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "Sudoku.h"

using namespace std;

const int Sudoku::init_map[sudoku_size][sudoku_size]={{0, 0, 0, 0, 0, 0, 9, 0, 1, -1, -1, -1,}, 
{8 ,0 ,0 ,0 ,0 ,1 ,0 ,2 ,0 ,-1, -1 ,-1}, 
{0 ,5 ,1 ,0 ,0 ,4 ,0 ,0 ,0 ,-1 ,-1 ,-1}, 
{-1 ,-1, -1 ,0 ,0 ,2 ,0 ,0 ,7 ,0 ,5 ,6}, 
{-1 ,-1 ,-1 ,7 ,0 ,0 ,1 ,0, 6, 0 ,2 ,0 },
{-1 ,-1 ,-1 ,0 ,9 ,0 ,2 ,3 ,0, 0, 0 ,1 },
{0 ,0 ,7 ,2 ,0 ,0 ,-1 ,-1 ,-1 ,0 ,9 ,0 },
{0 ,8 ,0 ,5 ,0 ,0 ,-1, -1 ,-1, 0, 3, 0},
{0 ,0 ,5 ,0 ,1 ,0 ,-1 ,-1 ,-1 ,2 ,0 ,0},
{3, 0, 0 ,-1 ,-1 ,-1 ,0 ,4 ,0 ,5 ,0 ,9 },
{0 ,0 ,0 ,-1 ,-1 ,-1 ,5 ,0 ,0 ,3 ,0 ,2}, 
{0 ,6 ,0 ,-1 ,-1 ,-1 ,0 ,0 ,2 ,0 ,4 ,0}};




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
    
    
    for( i=0;i<12;i++)
        for( j=0;j<12;j++)
            map2[i][j]=map[i][j];
	int m=count;
    int *temp1[m],*temp2[m];
    
    for( i=11;i>-1;i--)
        for( j=11;j>-1;j--)
            if (map[i][j]==0)
                {temp1[m-1]=&map[i][j];
                *temp1[m-1]=0;
				m--;}
    m=count;
    for( i=11;i>-1;i--)
        for( j=11;j>-1;j--)
            if (map2[i][j]==0)
                {
                 temp2[m-1]=&map2[i][j];   
				
				*temp2[m-1]=0;
				m--;}
    
    ans=0;
    Backtracking(0,temp1,count);
	

    if(ans==1){
	
		ans=0;
        ReBacktracking(0,temp2,count);
        
        for(i=0;i<count;i++){
        if(*temp1[i]!=*temp2[i])
            { cout<<2<<endl;
		return;
            }
	}
	cout<<1<<endl;
        for (int i=0;i<12;i++){
            for(int j=0;j<12;j++)
                cout<<map[i][j]<<" ";
            cout<<"\n";
        }
    }
    else
	cout<<0<<endl;

    
   

}




bool Sudoku::SudokuIsCorrect(int c,int z[12][12],int* prob[],int m){
    bool check_result;
    int check_array[12]={0};
    int i ,j,a,b;
    for( a=0;a<12;a++)
        for( b=0;b<12;b++)
            if(&z[a][b]==prob[m])
                {i=a;j=b;/*cout<<a<<"  "<<b<<endl;*/}
    

    for(int h=0;h<12;h++)
        check_array[h]=z[i][h];
   
    check_result=Check(check_array,c);

    if (check_result==false)
        return false;


    for(int h=0;h<12;h++)
        check_array[h]=z[h][j];
    
    check_result=Check(check_array,c);

    if (check_result==false)
        return false;


    int i1=i%3,j1=j%3;
    for(int h=0;h<9;h++)
        check_array[h]=z[i-i1+h/3][j-j1+h%3];
    check_array[9]=0,check_array[10]=0,check_array[11]=0;
    check_result=Check(check_array,c);

    if (check_result==false)
        return false;

    return true;
}


void Sudoku::Backtracking(int m,int *temp1[],int count){
    if (m==count){ans++;   return; }
            
    for(int c=1;c<10;c++){
     	 if(*temp1[m]==0){
 
            if (SudokuIsCorrect(c,map,temp1,m)==true){
               *temp1[m]=c;
         
               Backtracking(m+1,temp1,count);
       		
	       if(ans==0)
	       	    *temp1[m]=0;		
		if (ans==1)
                    return;

                }
         }
    }
}


void Sudoku::ReBacktracking(int m,int *temp2[],int count){
    if (m==count){ ans++; return;}
            
    for(int c=9;c>0;c--){
        if(*temp2[m]==0){
 
           if (SudokuIsCorrect(c,map2,temp2,m)==true){
              *temp2[m]=c;
              ReBacktracking(m+1,temp2,count);
      	      
		if(ans==0)
		*temp2[m]=0;		
		if (ans>0)
                    return;

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
