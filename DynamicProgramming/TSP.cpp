#include <iostream>
#include <algorithm>

using namespace std;

#define MAXNUM	16
#define INF	987654321

int n;
int w[MAXNUM][MAXNUM];
int dp[MAXNUM][1<<MAXNUM];

int find(int cur,int visited){
 
  if(visited == ((1<<n)-1)){
     if(w[cur][0] == 0)
       return INF;
     else
       return w[cur][0];
  }

  int& ret = dp[cur][visited];
  if(ret != 0) 
    return ret;

  ret = INF;
  for(int i=1;i<n;i++){
     if((visited & (1<<i)) == 0 && w[cur][i] != 0)
	ret = min(ret,w[cur][i]+find(i,visited|(1<<i)));
  }

  return ret;
}


int main(void){

  scanf("%d",&n);

  for(int i=0;i<n;i++)
     for(int j=0;j<n;j++)
	 scanf("%d",&w[i][j]);

  printf("%d\n",find(0,1));
   
  return 0;
}
