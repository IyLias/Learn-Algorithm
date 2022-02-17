#include <stdio.h>
#include <vector>
#include <algorithm>

#define INF 1123456789

using namespace std;

int main(){

  int N,num;
  scanf("%d",&N);
	        
  vector<int> arr;
  for(int i=0;i<N;i++){
     scanf("%d",&num);
     arr.push_back(num);
  }

  int max_length=0;  
  vector<int> max_arr(N+1,INF);
  max_arr[0] = -INF;
		          
  for(int i=0;i<N;i++){
     int j = upper_bound(max_arr.begin(),max_arr.end(),arr[i])-max_arr.begin();
     if(max_arr[j-1]<arr[i] && max_arr[j]>arr[i])
	max_arr[j] = arr[i];
  }
			    
  for(int i=0;i<N+1;i++)
     if(max_arr[i] < INF)
	max_length = i;
  printf("%d\n",max_length);

  return 0;
}
