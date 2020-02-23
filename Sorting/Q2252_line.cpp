#include <iostream>
#include <vector>
#include <queue>

#define MAXNUM	32000

using namespace std;

vector<int> graph[MAXNUM+1];


// Baekjoon Q2252 using topological sort

void topological_sort(int n,int inDegree[]){

  queue<int> qqueue;
  for(int i=1;i<=n;i++)
     if(inDegree[i] == 0)
	 qqueue.push(i);

  while(!qqueue.empty()){
     int num = qqueue.front();
     qqueue.pop();

     printf("%d ",num);
     for(int i=0;i<graph[num].size();i++){
	inDegree[graph[num][i]]--;
	if(inDegree[graph[num][i]] == 0)
	   qqueue.push(graph[num][i]);
     }
  }

  printf("\n");
}

int main(){

 int N,M;
 scanf("%d %d",&N,&M);

 int inDegree[MAXNUM+1];
 int p1,p2;
 for(int i=0;i<M;i++){
    scanf("%d %d",&p1,&p2);
    graph[p1].push_back(p2);
    inDegree[p2]++;
 }

 topological_sort(N,inDegree);

 return 0;
}
