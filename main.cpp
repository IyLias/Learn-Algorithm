#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXNUM	100001

#define MAX(X,Y)	((X) > (Y) ? (X) : (Y))

int arr[MAXNUM];

void swap(int * ptr1, int * ptr2) {
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

void bubble_sort(int comp,int len) {

	int temp;

	for(int i=0;i<len-1;i++)
		for (int j = 0; j < len-i-1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}

		}

}

void selection_sort(int len) {

	for (int i = 0; i < len - 1; i++) {

		int min_idx = i;
		for (int j = i + 1; j < len; j++) {
			if (arr[min_idx] > arr[j])
				min_idx = j;
		}

		swap(&arr[min_idx], &arr[i]);
	}

}

void insertion_sort(int len) {

	int i, j;

	for ( i = 1; i < len; i++) {
		int key = arr[i];
		for ( j = i-1; j >= 0 && key < arr[j]; j--) {
				arr[j + 1] = arr[j];
		}

		if (j != i - 1)
			arr[j+1] = key;
	}

}

void print_arr(int len) {

	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main(void)
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	//bubble_sort(1,N);
	//selection_sort(N);
	insertion_sort(N);

	print_arr(N);

	return 0;
}