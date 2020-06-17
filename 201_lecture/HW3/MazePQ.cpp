#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <queue>
#include <vector>

#define MAXNUM	20
#define MAX_SOLUTION_LENGTH	500
#define MINOTAUR_MOVE_TIME	2

#define LEFT	0
#define RIGHT 	1
#define TOP	2
#define BOTTOM	3
#define STAY	4

using namespace std;


class Node{

 public:

   int my_row;
   int my_col;

   int minotaur_row;
   int minotaur_col;

   int distance_to_exit;
   int distance_to_minotaur;

   char solution[MAX_SOLUTION_LENGTH];

   Node(int mrow,int mcol,int mino_row,int mino_col,int dE,int dM,char* sol){
	my_row = mrow;
	my_col = mcol;

	minotaur_row = mino_row;
	minotaur_col = mino_col;

	distance_to_exit = dE;
	distance_to_minotaur = dM;

	memset(solution,0,MAX_SOLUTION_LENGTH);
	for(int i=0;sol[i];i++)
	   solution[i] = sol[i];
   }

   void printSolution(){
	printf("\n\nsolution:\n");
	for(int i=0;solution[i];i++){
	   printf("%c",solution[i]);
	   if(i!=0 && i%5 == 0) printf("\n%d:",i/5+1);
	}
	printf("\n");
    }


};


struct cmp{

 bool operator()(Node n1,Node n2){
    return n1.distance_to_exit> n2.distance_to_exit;
 }

};


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
 
    // start position of 2 characters
    int start_minotaur_row;
    int start_minotaur_col;

    int start_my_row;
    int start_my_col;

    // exit position
    int exit_row;
    int exit_col;

    bool gameClearFlag;

    // method

    Puzzle(int r,int c,int my_row,int my_col,int minotaur_row,int minotaur_col,int exit_row,int exit_col,int** mapInfo){
       mapsize_row = r;
       mapsize_col = c;

       this->start_my_row = my_row;
       this->start_my_col = my_col;

       this->start_minotaur_row = minotaur_row;
       this->start_minotaur_col = minotaur_col;

       this->exit_row = exit_row;
       this->exit_col = exit_col;

       gameClearFlag = false;

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

    int distance(int r1,int c1,int r2,int c2){
       return (r1-r2)*(r1-r2) + (c1-c2)*(c1-c2);
    }

    bool isGameOver(int my_row,int my_col,int minotaur_row,int minotaur_col){
       if((my_row==minotaur_row) && (my_col==minotaur_col))
	   return true;
       else 
	   return false;
    }

    bool isGameClear(int my_row,int my_col){
       if((my_row==exit_row) && (my_col == exit_col))
	   return true;
       else
	   return false;
    }

    // move function of Minotaur
    void minotaurMove(int& minotaur_row,int& minotaur_col,const int& my_row,const int& my_col){

       int moveCount=0;
      
       printf("minotaurMove called start pos: (%d %d)\n",minotaur_row,minotaur_col);
 
       for(int y=0;y<MINOTAUR_MOVE_TIME;y++){

         for(int i=0;i<MINOTAUR_MOVE_TIME;i++){
 
          // 1) first check left and right direction
	  for(int j=0;j<2;j++){
	  // left direction => not blocked by wall? and this move get close to me?
	    if(!(1 & (puzzleMap[minotaur_row][minotaur_col] >> (3-j))) && 
         (distance(my_row,my_col,minotaur_row,minotaur_col) > distance(my_row,my_col,minotaur_row+horizon[j][0],minotaur_col+horizon[j][1]))){
	      moveCount++;	
	      minotaur_row += horizon[j][0],minotaur_col += horizon[j][1];
	  
	      if(moveCount == MINOTAUR_MOVE_TIME) break;
	    } 

	  }

	    if(moveCount == MINOTAUR_MOVE_TIME){
	      break;
	    }
         }

          printf("mino pos: ( %d %d)\n",minotaur_row,minotaur_col);
	    if(moveCount == MINOTAUR_MOVE_TIME){
	      return;
	    }


         for(int i=0;i<MINOTAUR_MOVE_TIME;i++){
 
	  // 2) second check top and bottom direction	
	  for(int j=0;j<2;j++){
	     // left direction => not blocked by wall? and this move get close to me?
	     if(!(1 & (puzzleMap[minotaur_row][minotaur_col] >> (1-j))) && 
         (distance(my_row,my_col,minotaur_row,minotaur_col) > distance(my_row,my_col,minotaur_row+vertical[j][0],minotaur_col+vertical[j][1]))){
	       moveCount++;
	       minotaur_row += vertical[j][0],minotaur_col += vertical[j][1];
	     	  
	       if(moveCount == MINOTAUR_MOVE_TIME) break;
	     } 
	     
	     printf("mino pos: (%d %d)\n",minotaur_row,minotaur_col);
	  }

	  if(moveCount == MINOTAUR_MOVE_TIME) break;
        }
	
	 if(moveCount == MINOTAUR_MOVE_TIME) break;
       }

	printf("minotaur pos after move: %d %d\n",minotaur_row,minotaur_col);
    }

    // My move
    void myMove(int& my_row,int& my_col,int direction){

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
       printf("my pos %d %d direction %d\n",my_row,my_col,direction);
    }

    // solve puzzle function
    // print solution of corresponding puzzle map
    void solvePuzzle(int moveTimes,int direction){

     // printf("solve Puzzle call at my pos: (%d,%d) and direction %d\n",my_row,my_col,direction);

      priority_queue<Node,vector<Node>,cmp> nodeQueue;	    
      queue<Node> qqueue;
      vector<Node> visitedNodes;

      int dE = distance(start_my_row,start_my_col,exit_row,exit_col);
      int dM = distance(start_my_row,start_my_col,start_minotaur_row,start_minotaur_col);
      char sol[MAX_SOLUTION_LENGTH];
      memset(sol,0,MAX_SOLUTION_LENGTH);
      Node firstNode(start_my_row,start_my_col,start_minotaur_row,start_minotaur_col,dE,dM,sol);
      nodeQueue.push(firstNode);      
      //qqueue.push(firstNode);

      int num=0;

      while(!nodeQueue.empty()){

	 // extract Node from nodeQueue
	 Node targetNode = nodeQueue.top();
	// Node targetNode = qqueue.front();

         // get datas from Node 
	 int my_row = targetNode.my_row,my_col = targetNode.my_col,minotaur_row = targetNode.minotaur_row,minotaur_col = targetNode.minotaur_col;
	 int last_distance_to_exit = targetNode.distance_to_exit;
	 int last_distance_to_minotaur = targetNode.distance_to_minotaur;

	 printf(">>>current Node: mypos (%d %d) minopos (%d %d) solution: %s\n",my_row,my_col,minotaur_row,minotaur_col,targetNode.solution);
	 nodeQueue.pop();
	 //qqueue.pop();
	 visitedNodes.push_back(targetNode);
	 num++;

	 // check gameClear 
	 if(isGameClear(my_row,my_col) == true){
	    targetNode.printSolution();
	    printf("\n\nTotal search Time: %d\n",num); 
	    break;
	 }

         // for 5 direction {
	 //  direction only not blocked by wall 
	 for(int i=0;i<5;i++){
            
	   if(!(1 & (puzzleMap[my_row][my_col] >> (3-i))) || i==STAY){
	   // myMove() and minotaurMove() function call to change position values
	     int temp_my_row=my_row,temp_my_col=my_col,temp_minotaur_row=minotaur_row,temp_minotaur_col=minotaur_col;
	     myMove(temp_my_row,temp_my_col,i);
	     minotaurMove(temp_minotaur_row,temp_minotaur_col,temp_my_row,temp_my_col);

	   // calculate distance between me and exit
             int dE = distance(temp_my_row,temp_my_col,exit_row,exit_col);
	     int dM = distance(temp_my_row,temp_my_col,temp_minotaur_row,temp_minotaur_col);

	   // if distance is 0(caught by minotaur) then don't insert into queue 
	   // or in STAY, distance is not changed don't insert into queue
	     if(!((dM==0 && dE != 0) || (i==STAY && dM == last_distance_to_minotaur))){
	         bool isVisited=false;
		 for(int k=0;k<visitedNodes.size();k++)
		    if(visitedNodes[k].my_row==temp_my_row&&visitedNodes[k].my_col==temp_my_col&&
			visitedNodes[k].minotaur_row==temp_minotaur_row&&visitedNodes[k].minotaur_col==temp_minotaur_col){
			    isVisited = true;
			    break;
		    }

		 if(isVisited == false){
		   char solution[MAX_SOLUTION_LENGTH];
	           memset(solution,0,MAX_SOLUTION_LENGTH);
 	           memcpy(solution,targetNode.solution,strlen(targetNode.solution));
		   solution[strlen(targetNode.solution)] = dir[i];
	     	   // insert into nodeQueue 
		   printf("insert Node tempmyRowPos (%d %d) tempMinoPos (%d %d) solution: %s\n",temp_my_row,temp_my_col,temp_minotaur_row,temp_minotaur_col,solution);
		   nodeQueue.push(Node(temp_my_row,temp_my_col,temp_minotaur_row,temp_minotaur_col,dE,dM,solution));
		   //qqueue.push(Node(temp_my_row,temp_my_col,temp_minotaur_row,temp_minotaur_col,dE,dM,solution));
	     
		 }
	      }
	   }

	 }

	 if(nodeQueue.empty())
	    printf("*************** qqueue empty!!\n");
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
//  minotaurPuzzle1.printSolution();



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
//  minotaurPuzzle2.solvePuzzle(0,LEFT);
//  minotaurPuzzle2.printSolution();


// ------------------------------------ puzzle 3 --------------------------------------


  // puzzle3 size: 8x8
  int puzzle3_mapData[8][8]={
	6,10,2,2,2,3,2,7,
	8,0,0,0,0,2,4,14,
	8,0,0,0,4,8,0,4,
	8,1,0,4,8,1,0,4,
	8,2,4,8,0,2,0,4,
	13,12,8,0,0,4,9,4,
	11,4,8,4,9,0,2,4,
	11,1,1,1,7,9,1,5
  };

  int** puzzle3_mapInfo = (int**)malloc(8*sizeof(int*));
  for(int i=0;i<8;i++){
     puzzle3_mapInfo[i] = (int*)malloc(8*sizeof(int));
     puzzle3_mapInfo[i] = puzzle3_mapData[i];
  }

  Puzzle minotaurPuzzle3(8,8,2,2,1,1,1,0,puzzle3_mapInfo);

  printf("Puzzle3\n");
  // print solution of puzzle1
  minotaurPuzzle3.solvePuzzle(0,LEFT);
//  minotaurPuzzle3.printSolution();



// ------------------------------------ puzzle 4 --------------------------------------


  // puzzle4 size: 9x14
  int puzzle4_mapData[9][14]={
     11,3,2,2,6,10,3,2,7,11,2,3,3,6,
     14,14,12,13,12,12,11,0,3,3,5,11,3,0,
     8,0,1,2,0,0,3,0,2,2,3,3,2,4,
     12,12,11,4,12,8,2,4,12,9,3,3,4,12,
     12,12,10,4,12,12,12,12,8,3,3,6,12,12,
     12,12,12,8,4,12,8,0,0,3,3,4,12,12,
     12,12,12,12,12,12,12,12,8,3,3,4,12,12,
     12,12,12,12,12,12,12,12,8,3,3,4,12,12,
      9,1,1,1,1,1,1,1,1,3,3,1,1,5	     
  };

  int** puzzle4_mapInfo = (int**)malloc(9*sizeof(int*));
  for(int i=0;i<9;i++){
     puzzle4_mapInfo[i] = (int*)malloc(14*sizeof(int));
     puzzle4_mapInfo[i] = puzzle4_mapData[i];
  }

  Puzzle minotaurPuzzle4(9,14,5,1,5,14,2,15,puzzle4_mapInfo);

  printf("Puzzle4\n");
  // print solution of puzzle1
 // minotaurPuzzle4.solvePuzzle(0,BOTTOM);
  //minotaurPuzzle4.printSolution();




// ------------------------------------ puzzle 5 --------------------------------------


  // puzzle5 size: 9x14
  int puzzle5_mapData[9][14]={
     10,6,10,3,2,3,3,2,2,7,10,3,3,6,
     12,9,1,6,12,10,3,4,8,7,12,14,14,12,
     8,6,10,1,1,0,3,0,1,6,12,8,0,4,
     12,8,0,2,6,12,11,0,6,8,4,12,12,12,
     12,12,12,12,12,8,6,12,12,12,12,8,1,5,
     8,1,1,1,4,12,8,4,12,12,12,12,14,10,
     9,3,2,6,9,1,4,8,1,4,9,0,5,12,
     14,14,12,12,11,3,4,8,2,1,3,1,6,12,
      9,1,1,1,1,1,1,5,9,3,3,3,1,5	     
  };

  int** puzzle5_mapInfo = (int**)malloc(9*sizeof(int*));
  for(int i=0;i<9;i++){
     puzzle5_mapInfo[i] = (int*)malloc(14*sizeof(int));
     puzzle5_mapInfo[i] = puzzle5_mapData[i];
  }

  Puzzle minotaurPuzzle5(9,14,6,13,4,7,6,15,puzzle5_mapInfo);

  printf("Puzzle5\n");
  // print solution of puzzle1
  //minotaurPuzzle5.solvePuzzle(0,BOTTOM);
  //minotaurPuzzle5.printSolution();

 return 0;
}

