#include <stdio.h>
#include <vector>
#include <iostream>


using namespace std;


#define BOARD_SIZE 9


class SudokuSolver{

 public: 
   
  vector<vector<int>> sudokuMap{BOARD_SIZE,vector<int>(BOARD_SIZE)};

  SudokuSolver(vector<vector<int>> map){

     	  
     for(int i=0;i<BOARD_SIZE;i++)
	 for(int j=0;j<BOARD_SIZE;j++)
	     sudokuMap[i][j] = map[i][j];
  }


  void print_sudokuMap(){
     for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++)
	    printf("%d ",sudokuMap[i][j]);
	printf("\n");
     }

  }

  void solve(){




  }

};


int main(){

 vector<vector<int>> map(BOARD_SIZE,vector<int>(BOARD_SIZE));
 for(int i=0;i<BOARD_SIZE;i++)
    for(int j=0;j<BOARD_SIZE;j++){
	scanf("%d",&map[i][j]);
    }


 SudokuSolver* sudoku = new SudokuSolver(map);
 //sudoku->solve();

 sudoku->print_sudokuMap(); 

 return 0;
}
