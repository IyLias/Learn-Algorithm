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
 
 for(int i=1;i<=n;i++){
    arr[i] = (r1==r2 ? target_rectangle[r1][i] : cumulative_sum[r2][i]-cumulative_sum[r1-1][i]);
   
    if(i==1)
      maxS[i] = arr[i];
    else
      maxS[i] = max(maxS[i-1]+arr[i],arr[i]);
 }

 maxsum[1] = arr[1];
 for(int i=2;i<=n;i++)
    maxsum[i] = max(maxS[i],maxsum[i-1]);

 return maxsum[n];
}

int main(){
 
 int n;
 scanf("%d",&n);

 for(int i=1;i<=n;i++)
   for(int j=1;j<=n;j++)
       scanf("%lf",&target_rectangle[i][j]);

 initialize(n);

 double result=-99999999; // stores max summation value
 // get MaxRectangle[r][c] in O(n3)
 for(int i=1;i<=n;i++)
   for(int j=i;j<=n;j++){
      double temsum = maxsubarr(i,j,n);
      if(result < temsum)
	result = temsum;
   }
 
 printf("result: %.1lf\n",result);

 return 0;
}
