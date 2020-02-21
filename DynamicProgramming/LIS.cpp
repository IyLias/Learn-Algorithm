#include <iostream>
#include <cstring>
#include <cstdlib>

#define MAXNUM	1000

using namespace std;

int main(){

 int N;
 scanf("%d",&N);

 int arr[MAXNUM],max_list[MAXNUM];
 memset(arr,0x00,sizeof(int)*MAXNUM);
 for(int i=0;i<MAXNUM;i++)
    max_list[i] = 0;

 for(int i=0;i<N;i++)
    scanf("%d",arr+i);

 for(int i=0;i<N;i++){
    int tem = max_list[i];
    for(int j=0;j<i;j++){
	if(arr[i] > arr[j]){
	   tem = (tem < max_list[j] ? max_list[j] : tem);
	}
    }

    max_list[i] = tem + 1;
 }

 cout << max_list[N-1] << endl;

 for(int i=0;i<N;i++)
    cout << max_list[i] << " ";
 cout << endl;

 return 0;
}
