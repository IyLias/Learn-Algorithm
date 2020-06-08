#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNUM	20

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

    // start position of 2 characters
    int minotaur_row;
    int minotaur_col;

    int my_row;
    int my_col;

    // exit position
    int exit_row;
    int exit_col;

    // method

    Puzzle(int r,int c,int exit_row,int exit_col,int mapInfo[r][c]){
       mapsize_row = r;
       mapsize_col = c;

       this->exit_row = exit_row;
       this->exit_col = exit_col;

       for(int i=0;i<MAXNUM;i++)
          for(int j=0;j<MAXNUM;j++)
             puzzleMap[i][j] = 15; // initialize with 15 which is all blocked!

       initMap(mapInfo);
    }

    // initialize map function
    // how about one number symbolizes position state?
    // ex) 0000=0 => all open , 1011=11 => only right open
    void initMap(int mapInfo[mapsize_row][mapsize_col]){
       
       for(int i=1;i<=mapsize_row;i++)
	  for(int j=1;j<=mapsize_col;j++)
	     puzzleMap[i][j] = mapInfo[i-1][j-1];
    }

    // move function of Minotaur
    void minotaurMove(){



    }

    // My move
    void myMove();

    // solve puzzle function
    // print solution of corresponding puzzle map
    void solvePuzzle();
   
};



int main(){
  
  // mapInfo order: left right top bottom
  // puzzle1 size: 8x9
  int puzzle1_mapInfo[8][9]={
     11,3,2,6,10,6,10,3,6,
     10,6,13,12,12,12,8,7,12,
     12,9,6,8,5,9,5,10,4,
     9,6,12,9,6,10,3,1,5,
     14,12,9,2,5,9,3,3,6,
     8,5,10,5,10,2,3,3,5,
     12,14,8,7,12,9,3,3,6,
     13,8,1,3,1,7,11,3,5
  };

  Puzzle minotaurPuzzle1(8,9,9,2,puzzle1_mapInfo);

  for(int i=0;i<MAXNUM;i++){
    for(int j=0;j<MAXNUM;j++)
       printf("%d ",minotaurPuzzle1.puzzleMap[i][j]);
    printf("\n");
  }


  // puzzle2 size: 8x9
  int puzzle2_mapInfo[8][9]={
//     {},{},{},{},{},{},{},{},{},
//     {},{},{},{},{},{},{},{},{},
//     {},{},{},{},{},{},{},{},{},
//     {},{},{},{},{},{},{},{},{},
//     {},{},{},{},{},{},{},{},{},
//     {},{},{},{},{},{},{},{},{},
//     {},{},{},{},{},{},{},{},{},
//     {},{},{},{},{},{},{},{},{}
  };

  // puzzle3 size: 8x8
  int puzzle3_mapInfo[8][8]={

  };

  // puzzle4 size: 9x14
  int puzzle4_mapInfo[9][14]={

  };

  // puzzle5 size: 9x14
  int puzzle5_mapInfo[9][14]={

  };

 return 0;
}

