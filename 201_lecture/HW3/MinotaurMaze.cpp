#include <iostream>
#include <algorithm>

#define MAXNUM	20

using namespace std;


class Map{

 public:

    bool is_left_open;
    bool is_right_open;
    bool is_top_open;
    bool is_bottom_open;

};


class Puzzle{

 public:

    // stores puzzle size
    int mapsize_row;
    int mapsize_col;

    // puzzle map
    Map puzzleMap[MAXNUM][MAXNUM];

    // start position of 2 characters
    int minotaur_row;
    int minotaur_col;

    int my_row;
    int my_col;

    // exit position
    int exit_row;
    int exit_col;

    // method

    Puzzle(int r,int c,int exit_row,int exit_col){
       mapsize_row = r;
       mapsize_col = c;

       this->exit_row = exit_row;
       this->exit_col = exit_col;

       for(int i=0;i<MAXNUM;i++)
	 for(int j=0;j<MAXNUM;j++){
	    puzzleMap[i][j].is_left_open = false;
	    puzzleMap[i][j].is_right_open = false;
	    puzzleMap[i][j].is_top_open = false;
	    puzzleMap[i][j].is_bottom_open = false;
	 }
    }

    // initialize map function
    // how about one number symbolizes position state?
    // ex) 0000=0 => all open , 1011=11 => only right open
    void initMap(int mapInfo[][4]);

    // move function of Minotaur
    void minotaurMove();

    // My move
    void myMove();

    // solve puzzle function
    // print solution of corresponding puzzle map
    void solvePuzzle();
   
};

int main(){
  
  // mapInfo order: left right top bottom
  // puzzle1 size: 9x9
  int puzzle1_mapInfo[81][4]={
     {1,0,1,1},{0,0,1,1},{0,0,1,0},{0,1,1,0},{1,0,1,0},{0,1,1,0},{1,0,1,0},{0,0,1,1},{0,1,1,0},
     {1,0,1,0},{0,1,1,0},{1,1,0,1},{1,1,0,0},{1,1,0,0},{1,1,0,0},{1,0,0,0},{0,1,1,1},{1,1,0,0},
     {1,1,0,0},{1,0,0,1},{0,1,1,0},{1,0,0,0},{0,1,0,1},{1,0,0,1},{0,1,0,1},{1,0,1,0},{0,1,0,0},
     {},{},{},{},{},{},{},{},{},
     {},{},{},{},{},{},{},{},{},
     {},{},{},{},{},{},{},{},{},
     {},{},{},{},{},{},{},{},{},
     {},{},{},{},{},{},{},{},{},
     {},{},{},{},{},{},{},{},{},
  };

  int puzzle2_mapInfo[][4]={
     {},{},{},{},{},{},{},{},{},
     {},{},{},{},{},{},{},{},{},
     {},{},{},{},{},{},{},{},{},
     {},{},{},{},{},{},{},{},{},
     {},{},{},{},{},{},{},{},{},
     {},{},{},{},{},{},{},{},{},
     {},{},{},{},{},{},{},{},{},
     {},{},{},{},{},{},{},{},{},
     {},{},{},{},{},{},{},{},{},
  };

  int puzzle3_mapInfo[][4]={




  };


  int puzzle4_mapInfo[][4]={




  };

  int puzzle5_mapInfo[][4]={




  };




 return 0;
}

