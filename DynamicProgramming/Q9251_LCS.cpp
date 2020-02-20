#include <iostream>
#include <cstdlib>
#include <utility>
#include <cstring>

#define MAXLEN	1000

using namespace std;

int max_len[MAXLEN+1][MAXLEN+1]; 
char lcs_str[MAXLEN+1];

int search_lcs_recursive(const char* str1,int idx1,const char* str2,int idx2){

 if(idx1 < 0 || idx2 < 0)
    return 0;

 if(str1[idx1] == str2[idx2])
    return (1 + search_lcs_recursive(str1,idx1-1,str2,idx2-1));
 else
    return max(search_lcs_recursive(str1,idx1-1,str2,idx2),search_lcs_recursive(str1,idx1,str2,idx2-1));

}

int search_lcs(const char* str1,int len1,const char* str2,int len2){

 for(int i=1;i<=len1;i++)
    for(int j=1;j<=len2;j++)
	 if(str1[i-1] == str2[j-1])
	    max_len[i][j] = 1 + max_len[i-1][j-1];
 	 else
	    max_len[i][j] = max(max_len[i-1][j],max_len[i][j-1]);
 
 int lcs_length = max_len[len1][len2];
 int i=len1,j=len2;

 while(i>=0 && j>=0){

    if(str1[i-1] == str2[j-1]){
	i--; j--;
	lcs_str[--lcs_length] = str1[i];
    }
    else if(max_len[i-1][j] > max_len[i][j-1])
	i--;
    else
	j--;

 }
 
 return max_len[len1][len2];
}

int main(){

 char str1[MAXLEN+1],str2[MAXLEN+1];
 scanf("%s %s",str1,str2); 
 
 printf("%d\n",search_lcs(str1,strlen(str1),str2,strlen(str2)));
 printf("%s\n",lcs_str);

 return 0;
}
