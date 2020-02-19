#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define MAXLEN	15
#define LEAST_VOWEL	1
#define LEAST_CONSONANT	2

using namespace std;

void get_crypto(char* collection,vector<char>& crypto,int cur_len,int cur_idx,int max_len,int C,int num_v,int num_c){
 
   if(cur_len < max_len){
      
      if(cur_idx >= C)
	return;

      crypto.push_back(collection[cur_idx]);
      
      int tem_num_v=num_v,tem_num_c=num_c;
      if(collection[cur_idx]=='a' || collection[cur_idx]=='e' || collection[cur_idx]=='i' || collection[cur_idx]=='o' || collection[cur_idx]=='u') 
	 tem_num_v++;
      else
         tem_num_c++;

      get_crypto(collection,crypto,cur_len+1,cur_idx+1,max_len,C,tem_num_v,tem_num_c);

      crypto.pop_back();

      get_crypto(collection,crypto,cur_len,cur_idx+1,max_len,C,num_v,num_c);

   }else{

      if(num_v >= LEAST_VOWEL && num_c >= LEAST_CONSONANT){
          for(int i=0;i<cur_len;i++)
	     printf("%c",crypto[i]);
	  printf("\n");
	  return;
      }
   }

}


int main(){

 int L,C;
 scanf("%d %d",&L,&C);

 char collection[MAXLEN];
 for(int i=0;i<C;i++)
    scanf(" %c",&collection[i]);

 sort(collection,collection+C);

 int num_vowel=0,num_conso=0; 
 vector<char> crypto; // stores crypto
 
 get_crypto(collection,crypto,0,0,L,C,num_vowel,num_conso);

 return 0;
}
