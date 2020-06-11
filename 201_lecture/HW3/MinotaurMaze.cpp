#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAXNUM	20
#define MAX_SOLUTION_LENGTH	500
#define MINOTAUR_MOVE_TIME	2

#define LEFT	0
#define RIGHT 	1
#define TOP	2
#define BOTTOM	3
#define STAY	4

using namespace std;

class Puzzle{

 public:

    // *** every idx starts from 1 and position also apply this!! ***

    // stores puzzle size
    int mapsize_row;
    int mapsize_col;

    // puzzle map
    // each map value contains current position state
    // ex) 11 means 1011 => only right is open 
    int puzzleMap[MAXNUM][MAXNUM];

    const int totalDirection[5][2]={{0,-1},{0,1},{-1,0},{1,0},{0,0}};
    const int horizon[2][2]={{0,-1},{0,1}};
    const int vertical[2][2] = {{-1,0},{1,0}};

    const char dir[5] = {'L','R','U','D','S'};
    char solution[MAX_SOLUTION_LENGTH];

    // start position of 2 characters
    int minotaur_row;
    int minotaur_col;

    int my_row;
    int my_col;

    // exit position
    int exit_row;
    int exit_col;

    // method

    Puzzle(int r,int c,int my_row,int my_col,int minotaur_row,int minotaur_col,int exit_row,int exit_col,int** mapInfo){
       mapsize_row = r;
       mapsize_col = c;

       this->my_row = my_row;
       this->my_col = my_col;

       this->minotaur_row = minotaur_row;
       this->minotaur_col = minotaur_col;

       this->exit_row = exit_row;
       this->exit_col = exit_col;

       for(int i=0;i<MAX_SOLUTION_LENGTH;i++)
	  solution[i]=0;

       for(int i=0;i<MAXNUM;i++)
          for(int j=0;j<MAXNUM;j++)
             puzzleMap[i][j] = 15; // initialize with 15 which is all blocked!

       initMap(mapInfo);
    }

    // initialize map function
    // how about one number symbolizes position state?
    // ex) 0000=0 => all open , 1011=11 => only right open
    void initMap(int** mapInfo){
       
       for(int i=1;i<=mapsize_row;i++)
	  for(int j=1;j<=mapsize_col;j++)
	     puzzleMap[i][j] = mapInfo[i-1][j-1];
    }

    void printSolution(){
	for(int i=0;solution[i];i++){
	   printf("%c",solution[i]);
	   if(i%10 == 0) printf("\n");
	}
	printf("\n");
    }

    int distance(int r1,int c1,int r2,int c2){
       return (r1-r2)*(r1-r2) + (c1-c2)*(c1-c2);
    }

    bool isGameOver(){
       if((my_row==minotaur_row) && (my_col==minotaur_col))
	   return true;
       else 
	   return false;
    }

    bool isGameClear(){
       if((my_row==exit_row) && (my_col == exit_col))
	   return true;
       else
	   return false;
    }

    // move function of Minotaur
    void minotaurMove(){

       bool isMoved=false;

       for(int i=0;i<MINOTAUR_MOVE_TIME;i++){
 
          // 1) first check left and right direction
	  for(int j=0;j<2;j++)
	  // left direction => not blocked by wall? and this move get close to me?
	    if(!(puzzleMap[minotaur_row][minotaur_col] & (1<<(3-j))) && 
         (distance(my_row,my_col,minotaur_row,minotaur_col) > distance(my_row,my_col,minotaur_row+horizon[j][0],minotaur_col+horizon[j][1]))){
	      isMoved = true;	
	      minotaur_row += horizon[j][0],minotaur_col += horizon[j][1];
	  } 

	  // 2) second check top and bottom direction	
	  for(int j=0;j<2;j++)
	     // left direction => not blocked by wall? and this move get close to me?
	     if(!(puzzleMap[minotaur_row][minotaur_col] & (1<<(1-j))) && 
         (distance(my_row,my_col,minotaur_row,minotaur_col) > distance(my_row,my_col,minotaur_row+vertical[j][0],minotaur_col+vertical[j][1]))){
	       isMoved = true;	
	       minotaur_row += vertical[j][0],minotaur_col += vertical[j][1];
	  } 

	  // if neither 1) and 2) case, then skip its turn
	  if(isMoved == false)
	     break;
       }


	printf("minotaur pos after move: %d %d\n",minotaur_row,minotaur_col);
    }

    // My move
    void myMove(int direction){

       switch(direction){

         case LEFT:
	    my_col-=1;
	    break;
	 case RIGHT:
	    my_col+=1;
	    break;
         case TOP:
	    my_row-=1;
	    break;
         case BOTTOM:
	    my_row+=1;
	    break;
	 case STAY:
	    break;
       }
    }

    // solve puzzle function
    // print solution of corresponding puzzle map
    void solvePuzzle(int moveTimes,int direction){

      myMove(direction);
      minotaurMove();
      
      if(isGameClear() == true){
	solution[moveTimes] = dir[direction];
        return;	      
      } 

      if(isGameOver() == false){
	solution[moveTimes] = dir[direction];
        
        for(int i=0;i<5;i++){
	  int randomDir = rand()%5;
       	  if(!(puzzleMap[my_row][my_col] & (randomDir!=4 ? (1 << (3-randomDir)) : 0))) 
	    solvePuzzle(moveTimes+1,randomDir);
	}
      }

    }

   
};



int main(){
  
  srand((unsigned int)time(NULL));

// ------------------------------------- puzzle 1 -------------------------------------------

  // mapInfo order: left right top bottom
  // puzzle1 size: 8x9
  int puzzle1_mapData[8][9]={
     11,3,2,6,10,6,10,3,6,
     10,6,13,12,12,12,8,7,12,
     12,9,6,8,5,9,5,10,4,
     9,6,12,9,6,10,3,1,5,
     14,12,9,2,5,9,3,3,6,
     8,5,10,5,10,2,3,3,5,
     12,14,8,7,12,9,3,3,6,
     13,8,1,3,1,7,11,3,5
  };

  int** puzzle1_mapInfo = (int**)malloc(8*sizeof(int*));
  for(int i=0;i<8;i++){
     puzzle1_mapInfo[i] = (int*)malloc(9*sizeof(int));
     puzzle1_mapInfo[i] = puzzle1_mapData[i];
  }

  Puzzle minotaurPuzzle1(8,9,1,1,3,3,9,2,puzzle1_mapInfo);

  for(int i=1;i<9;i++){
    for(int j=1;j<10;j++)
       printf("%d ",minotaurPuzzle1.puzzleMap[i][j]);
    printf("\n");
  }

  printf("1<<0 ? : %d\n",1<<0);

  printf("Puzzle1\n");
  // print solution of puzzle1
  minotaurPuzzle1.solvePuzzle(0,RIGHT);
  minotaurPuzzle1.printSolution();



// ------------------------------------ puzzle 2 --------------------------------------

  // puzzle2 size: 8x9
  int puzzle2_mapData[8][9]={
     11,3,2,0,2,3,2,2,6,
     10,2,0,0,0,2,0,0,4,
     0,0,0,1,0,0,0,0,4,
     12,9,4,14,8,0,0,4,12,
     12,10,0,0,0,0,0,5,12,
     12,8,0,0,0,0,0,6,12,
     8,0,0,1,0,0,0,4,12,
     9,1,1,3,1,1,1,1,5
  };

  int** puzzle2_mapInfo = (int**)malloc(8*sizeof(int*));
  for(int i=0;i<8;i++){
     puzzle2_mapInfo[i] = (int*)malloc(9*sizeof(int));
     puzzle2_mapInfo[i] = puzzle2_mapData[i];
  }

  Puzzle minotaurPuzzle2(8,9,1,9,1,1,0,4,puzzle2_mapInfo);

  for(int i=1;i<9;i++){
    for(int j=1;j<10;j++)
       printf("%d ",minotaurPuzzle2.puzzleMap[i][j]);
    printf("\n");
  }

  printf("Puzzle2\n");
  // print solution of puzzle1
  minotaurPuzzle2.solvePuzzle(0,LEFT);
  minotaurPuzzle2.printSolution();


// ------------------------------------ puzzle 3 --------------------------------------


  // puzzle3 size: 8x8
  int puzzle3_mapInfo[8][8]={

  };


// ------------------------------------ puzzle 4 --------------------------------------


  // puzzle4 size: 9x14
  int puzzle4_mapInfo[9][14]={

  };



// ------------------------------------ puzzle 5 --------------------------------------


  // puzzle5 size: 9x14
  int puzzle5_mapInfo[9][14]={

  };

 return 0;
}

