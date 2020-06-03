#include <iostream>
#include <utility>
#include <vector>

#define MAXNUM	15

using namespace std;

int n,result;
vector<pair<int,int>> queen_pos;

bool promising(int k,int col){

 bool flag =true;
 for(int i=0;i<k-1;i++)
    if(queen_pos[i].second == col || (abs(queen_pos[i].first-k) == abs(queen_pos[i].second-col))){
	flag = false;
	break;
    }

 return flag;
}

void print_queenPos(){

 printf("\n\n possible situation \n\n");

 for(int i=0;i<queen_pos.size();i++)
    printf("%dth queen pos: (%d,%d)\n",i+1,queen_pos[i].first,queen_pos[i].second);
}

void find(int curnum){

 for(int i=1;i<=n;i++){
   if(promising(curnum,i)){
     queen_pos.push_back(make_pair(curnum,i));

     if(curnum == n){
       result++;
       print_queenPos();
       queen_pos.pop_back();
       return;
     }else{
       find(curnum+1);
     }
  
    queen_pos.pop_back(); 
   }
 }

}

int main(){

 scanf("%d",&n);

 find(1);

 printf("total cases: %d\n",result);

 return 0;
}
