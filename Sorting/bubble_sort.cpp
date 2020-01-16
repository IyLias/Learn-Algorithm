#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#define MAXNUM	10

using namespace std;

void swap(int *a,int *b){

 *a ^= *b;
 *b ^= *a;
 *a ^= *b;
}

void bubble_sort(int * ptr,int n){

 if(n<=1)
   return;

 for(int i=0;i<n-1;i++)
   if(ptr[i] > ptr[i+1])
	swap(&ptr[i],&ptr[i+1]); 

 bubble_sort(ptr,n-1);
}

void print_arr(int * arr,int n){

 for(int i=0;i<n;i++)
   cout << arr[i] << " ";
 cout << endl;
}

int main(){

 srand((int)time(NULL));

 int * arr = new int[MAXNUM];
 for(int i=0;i<MAXNUM;i++)
    arr[i] = rand() % 100;

 print_arr(arr,MAXNUM);
 bubble_sort(arr,MAXNUM);
 print_arr(arr,MAXNUM);

 return 0;
}
