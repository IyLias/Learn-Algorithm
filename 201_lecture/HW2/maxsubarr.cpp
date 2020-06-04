#include <iostream>
#include <algorithm>

using namespace std;

#define MAXNUM	100000

int arr[MAXNUM];
int maxsum[MAXNUM];
int maxS[MAXNUM];

int main(){

 int n;
 scanf("%d",&n);

 for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
    
    if(i==0)
      maxS[i] = maxS[i];
    else
      maxS[i] = max(maxS[i-1]+arr[i],arr[i]);
 }

 maxsum[0]=arr[0]; //initialize
 for(int i=1;i<n;i++){
    maxsum[i] = max(maxS[i],maxsum[i-1]);
 }

 printf("max cont subarr sum: %d\n",maxsum[n-1]);

 return 0;
}
