#include <iostream>
#include <algorithm>

#define MAXNUM	1001

struct Point{
  int row;
  int column;

};
typedef struct Point Point;

struct MaxRectangle{

  Point top_left;

  Point bottom_right;

  double maxsum;
};
typedef struct MaxRectangle MaxRectangle;

using namespace std;

double target_rectangle[MAXNUM][MAXNUM]; // input rectangle
double cumulative_sum[MAXNUM][MAXNUM]; // cumulative sum of column

MaxRectangle maxRectangle; // store max value rectangle position
MaxRectangle temMaxRectangle; // store temp max value rectangle position in maxsubarr func

void initialize(int n){

 // assign values in cumulative sum of column
 for(int i=1;i<=n;i++){
   if(i==1){
      for(int j=1;j<=n;j++)
	 cumulative_sum[i][j] = target_rectangle[i][j];
   }
   else{
      for(int j=1;j<=n;j++)
	 cumulative_sum[i][j] = cumulative_sum[i-1][j] + target_rectangle[i][j];
   }
 }

}

// get maxsubarr (r1 <= r2)
double maxsubarr(int r1,int r2,int n){
 
 double arr[MAXNUM]; // assign cumulative_sum values to arr
 double maxS[MAXNUM];
 double maxsum[MAXNUM];

 MaxRectangle maxSRectangle[MAXNUM];
 MaxRectangle maxSumRectangle;
 
 maxSRectangle[1] = {r1,1,r2,1,0};
 for(int i=1;i<=n;i++){
    arr[i] = (r1==r2 ? target_rectangle[r1][i] : cumulative_sum[r2][i]-cumulative_sum[r1-1][i]);
   
    if(i==1){
      maxS[i] = arr[i];
      maxSRectangle[i].maxsum = arr[i];
    }
    else{
      maxS[i] = max(maxS[i-1]+arr[i],arr[i]);
      // if maxS[i-1]+arr[i] is larger
      if(maxS[i-1]+arr[i] >= arr[i]){
	maxSRectangle[i] = {r1,maxSRectangle[i-1].top_left.column,r2,i,maxS[i-1]+arr[i]};
      }else{
	maxSRectangle[i] = {r1,i,r2,i,arr[i]};
      } 
    }
 }

 maxSumRectangle = {r1,1,r2,1,arr[1]};
 maxsum[1] = arr[1];
 for(int i=2;i<=n;i++){
    maxsum[i] = max(maxS[i],maxsum[i-1]);
    if(maxS[i]>=maxsum[i-1]){
	maxSumRectangle = maxSRectangle[i];	
    }
 }

 temMaxRectangle = maxSumRectangle;
 return maxsum[n];
}

int main(){
 
 int n;
 scanf("%d",&n);

 for(int i=1;i<=n;i++)
   for(int j=1;j<=n;j++)
       scanf("%lf",&target_rectangle[i][j]);

 initialize(n);

 // ******************************* MINIMUM PART *********************************
 for(int i=1;i<n;i++)
   for(int j=1;j<=n;j++){
      target_rectangle[i][j] *= -1;  
      cumulative_sum[i][j] *= -1;
   }

  maxRectangle.maxsum =-99999999; // stores max summation value
 // get MaxRectangle[r][c] in O(n3)
 for(int i=1;i<=n;i++)
   for(int j=i;j<=n;j++){
      temMaxRectangle.maxsum = maxsubarr(i,j,n);
      if(maxRectangle.maxsum < temMaxRectangle.maxsum){
	// need to set maxRectangle position 
	// assign temMaxRectangle position to maxRectangle position
        maxRectangle = temMaxRectangle;
      }
   }
 
 printf("result: %.1lf\n",-maxRectangle.maxsum);
 printf("max value pos: (%d,%d)(%d,%d)\n",maxRectangle.top_left.row,maxRectangle.top_left.column
		        ,maxRectangle.bottom_right.row,maxRectangle.bottom_right.column);

 // ******************************** MAXIMUM PART ************************************

 for(int i=1;i<n;i++)
   for(int j=1;j<=n;j++){
      target_rectangle[i][j] *= -1;  
      cumulative_sum[i][j] *= -1;
   }

 maxRectangle.maxsum =-99999999; // stores max summation value
 // get MaxRectangle[r][c] in O(n3)
 for(int i=1;i<=n;i++)
   for(int j=i;j<=n;j++){
      temMaxRectangle.maxsum = maxsubarr(i,j,n);
      if(maxRectangle.maxsum < temMaxRectangle.maxsum){
	// need to set maxRectangle position 
	// assign temMaxRectangle position to maxRectangle position
        maxRectangle = temMaxRectangle;
      }
   }
 
 printf("result: %.1lf\n",maxRectangle.maxsum);
 printf("max value pos: (%d,%d)(%d,%d)\n",maxRectangle.top_left.row,maxRectangle.top_left.column
		        ,maxRectangle.bottom_right.row,maxRectangle.bottom_right.column);

 return 0;
}
