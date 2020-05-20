#include <iostream>
#include <algorithm>
#include <vector>

#define MAXNUM	10000

using namespace std;

int getParent(int parent[],int x){

  if(parent[x] == x) return x;
  return parent[x] = getParent(parent,parent[x]);
}

void unionParent(int parent[],int v1,int v2){
 
 v1 = getParent(parent,v1);
 v2 = getParent(parent,v2);

 if(v1 < v2)
    parent[v2]=v1;
 else
    parent[v1]=v2;
}

bool findParent(int parent[],int v1,int v2){

  v1 = getParent(parent,v1);
  v2 = getParent(parent,v2);

  if(v1==v2)
     return true;
  else
     return false;
}


class Edge{

 public:

 int vertex[2];
 int distance;

 Edge(int a,int b,int dis){
    vertex[0]=a;
    vertex[1]=b;
    distance = dis;
 }

 bool operator<(Edge& edge){
    return this->distance < edge.distance;
 } 

};

int main(){

 int V,E;
 scanf("%d %d",&V,&E);

 int v1,v2,dis;
 vector<Edge> graph;
 for(int i=0;i<E;i++){
    scanf("%d %d %d",&v1,&v2,&dis);
    graph.push_back(Edge(v1,v2,dis));
 }

 sort(graph.begin(),graph.end());

 int connect[MAXNUM];
 for(int i=0;i<V;i++)
    connect[i] = i;

 int sum=0;
 for(int i=0;i<graph.size();i++){

    if(!findParent(connect,graph[i].vertex[0]-1,graph[i].vertex[1]-1)){
	sum += graph[i].distance;
	unionParent(connect,graph[i].vertex[0]-1,graph[i].vertex[1]-1);
    }
 }

 printf("%d\n",sum);

 return 0;
}
