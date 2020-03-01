#include <iostream>

#define INF	123456789
#define MAXNUM	100
#define UNDEFINED	-1

using namespace std;

int graph[MAXNUM+1][MAXNUM+1];
int min_cost[MAXNUM+1][MAXNUM+1];
bool visited[MAXNUM+1];

bool is_all_visited(int n){

   for(int i=1;i<=n;i++)
       if(visited[i] == false)
	   return false;

   return true;
}

void dijkstra(int start,int n){

 for(int i=1;i<=n;i++)
   for(int j=1;j<=n;j++)
	 if(i!=j)
	    min_cost[i][j] = INF;


 for(int j=1;j<=n;j++)
    visited[j] = false;

 int next_node=start;
 while(is_all_visited(n) == false){
   	
    int distance = INF;
    for(int j=1;j<=n;j++)
	 if(visited[j] == false)
	     if(distance >= min_cost[start][j]){
		 distance = min_cost[start][j];
 		 next_node = j;
	     }
	
     visited[next_node] = true;
	for(int j=1;j<=n;j++){
	   if(graph[next_node][j] > 0)
		if(min_cost[start][j] > distance + graph[next_node][j])
		    min_cost[start][j] = distance + graph[next_node][j];
	}

    }

}

int main(){

 int n,m,start;
 scanf("%d %d %d",&n,&m,&start);

 for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
	if(i != j)
	  graph[i][j] = UNDEFINED;

 int s,e,c;
 for(int i=0;i<m;i++){
    scanf("%d %d %d",&s,&e,&c);
    if(graph[s][e] == UNDEFINED)
	  graph[s][e] = c;
    else
	  if(graph[s][e] > c)
	     graph[s][e] = c;
 }

 dijkstra(start,n);

 for(int j=1;j<=n;j++)
    if(min_cost[start][j] != INF)
       printf("%d\n",min_cost[start][j]);
    else
       printf("INF\n");
 
 return 0;
}

