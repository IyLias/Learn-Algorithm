#include <iostream>

#define INF	123456789
#define MAXNUM	100
#define UNDEFINED	-1

using namespace std;

int graph[MAXNUM+1][MAXNUM+1];
int min_cost[MAXNUM+1][MAXNUM+1];

bool visited[MAXNUM+1];

int main(){

 int n,m;
 scanf("%d %d",&n,&m);

 for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
	if(i != j)
	   graph[i][j] = INF;

 int s,e,c;
 for(int i=0;i<m;i++){
    scanf("%d %d %d",&s,&e,&c);
    if(graph[s][e] == UNDEFINED)
	  graph[s][e] = c;
    else
	  if(graph[s][e] > c)
	     graph[s][e] = c;
 }

 for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	   if(graph[i][j] > graph[i][k]+graph[k][j])
		 graph[i][j] = graph[i][k] + graph[k][j];

 for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++)
	 cout << graph[i][j] << " ";
    cout << endl;  
 }

 return 0;
}
