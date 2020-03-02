#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <utility>

#define INF	123456789
#define MAXNUM	20000
#define UNDEFINED	-1

using namespace std;


vector<pair<int,int>> adj[MAXNUM+1];

// get minimum distance from start node
vector<int> dijkstra(int start,int n){

 vector<int> dist(n+1,INF);
 dist[start] = 0; 

 priority_queue<pair<int,int>> pq;
 pq.push(make_pair(0,start));

 while(!pq.empty()){

   int cost = -pq.top().first;
   int here = pq.top().second;

   pq.pop();

   if(dist[here] < cost)
	continue;

   for(int i=0;i<adj[here].size();i++){
    
      int there = adj[here][i].first;
      int nextDist = cost + adj[here][i].second;

      if(dist[there] > nextDist){
	dist[there] = nextDist;
	pq.push(make_pair(-nextDist,there));
      }

   }

 }

 return dist;
}

int main(){

 int n,m,start;
 scanf("%d %d %d",&n,&m,&start);

 int s,e,c;
 for(int i=0;i<m;i++){
    scanf("%d %d %d",&s,&e,&c);
    adj[s].push_back(make_pair(e,c));
 }

 vector<int> distance = dijkstra(start,n);
 for(int i=1;i<distance.size();i++)
    if(distance[i] != INF)
	printf("%d\n",distance[i]);
    else
	printf("INF\n");

 return 0;
}


