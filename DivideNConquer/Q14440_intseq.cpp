#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> matrix;

matrix matrix_multiplication(matrix& A,matrix& B){

   int size = A.size();
   matrix result(size,vector<int>(size,0));

   for(int i=0;i<size;i++)
      for(int j=0;j<size;j++){
	   for(int p=0;p<size;p++)
		result[i][j] += A[i][p]*B[p][j];
	   result[i][j] %= 100;
      }

   return result;
}

matrix matrix_power(matrix& A,int pow){

   matrix result;

   if(pow == 1)
      return A;

   matrix half = matrix_power(A,pow&1 ? (pow-1)/2 : pow/2);
   result = matrix_multiplication(half,half);
   
   if(pow & 1)
     result = matrix_multiplication(result,A);
  
   return result;
}


void print_matrix(const matrix& A,int r,int c){

 for(int i=0;i<r;i++){
    for(int j=0;j<c;j++)
	cout << A[i][j] << " ";
    cout << endl;
 }

}

int main(){

 int x,y,a0,a1,n;
 scanf("%d %d %d %d %d",&x,&y,&a0,&a1,&n);

 matrix seq_matrix(2,vector<int>(2,0));

 seq_matrix[0][0] = x; seq_matrix[0][1] = y; seq_matrix[1][0] = 1;

 if(n<2){
    int result = (n==0?a0:a1);
    if(result < 10)
	printf("0");
    printf("%d\n",result);
 }else{
    matrix result_matrix = matrix_power(seq_matrix,n);
    int result = (result_matrix[1][0]*a1+result_matrix[1][1]*a0)%100;
    if(result < 10)
	printf("0");
    printf("%d\n",result);
 }

 return 0;
}
