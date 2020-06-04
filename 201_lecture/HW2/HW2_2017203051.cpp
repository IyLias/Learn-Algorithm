#include <iostream>
#include <algorithm>

#define MAXNUM	1001
#define TRUE	1
#define FALSE	0

struct Point{
  int row;
  int column;

};
typedef struct Point Point;

struct Rectangle{

  Point top_left;

  Point bottom_right;

  double sum;
};
typedef struct Rectangle Rectangle;

using namespace std;

double target_rectangle[MAXNUM][MAXNUM]; // input rectangle
double cumulative_sum[MAXNUM][MAXNUM]; // cumulative sum of column

Rectangle maxRectangle; // store max value rectangle position
Rectangle temMaxRectangle; // store temp max value rectangle position in maxsubarr func

Rectangle minRectangle; // store min value rectangle position
Rectangle temMinRectangle; // store temp min value rectangle position in maxsubarr func

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
double maxsubarr(int r1,int r2,int n,int minus_flag){
 
 double arr[MAXNUM]; // assign cumulative_sum values to arr
 double maxS[MAXNUM];
 double maxsum[MAXNUM];

 Rectangle maxSRectangle[MAXNUM];
 Rectangle maxSumRectangle;
 
 maxSRectangle[1] = {r1,1,r2,1,0}; 
 for(int i=1;i<=n;i++){
    // initialize arr array
  if(r1==r2){
    arr[i] = (minus_flag == TRUE ? -target_rectangle[r1][i] : target_rectangle[r1][i]);
  }else{
    arr[i] = (minus_flag == TRUE ? -(cumulative_sum[r2][i]-cumulative_sum[r1-1][i]): cumulative_sum[r2][i]-cumulative_sum[r1-1][i]);
  }

  // assign values in maxS array
  if(i==1){
    maxS[i] = arr[i];
    maxSRectangle[i].sum = arr[i];
  }
  else{
    maxS[i] = max(maxS[i-1]+arr[i],arr[i]);
    // if maxS[i-1]+arr[i] is larger
    if(maxS[i-1]+arr[i] > arr[i]){
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
    if(maxS[i]>maxsum[i-1]){
	maxSumRectangle = maxSRectangle[i];	
    }
 }

 if(minus_flag == TRUE)
    temMinRectangle = maxSumRectangle;
 else
    temMaxRectangle = maxSumRectangle;
 return maxsum[n];
}



int main(){
 
 int n;
 scanf("%d",&n);

 for(int i=1;i<=n;i++)
   for(int j=1;j<=n;j++)
       scanf("%lf",&target_rectangle[i][j]);

 initialize(n); // initialize cumulative_sum array

 maxRectangle.sum = -999999999; // stores max summation value
 minRectangle.sum = -999999999;
 for(int i=1;i<=n;i++)
   for(int j=i;j<=n;j++){
  // *********************************** MINIMUM PART *************************************
      temMinRectangle.sum = maxsubarr(i,j,n,TRUE);
      if(minRectangle.sum < temMinRectangle.sum){
        minRectangle = temMinRectangle;
      }

 // *********************************** MAXIMUM PART ************************************
      temMaxRectangle.sum = maxsubarr(i,j,n,FALSE);
      if(maxRectangle.sum < temMaxRectangle.sum){
        maxRectangle = temMaxRectangle;
      }
   }
 
 printf("%lf\n",-minRectangle.sum);
 printf("(%d,%d)(%d,%d)\n",minRectangle.top_left.row,minRectangle.top_left.column
		        ,minRectangle.bottom_right.row,minRectangle.bottom_right.column);

 printf("%lf\n",maxRectangle.sum);
 printf("(%d,%d)(%d,%d)\n",maxRectangle.top_left.row,maxRectangle.top_left.column
		        ,maxRectangle.bottom_right.row,maxRectangle.bottom_right.column);

 return 0;
}

