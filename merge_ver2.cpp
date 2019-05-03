#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <time.h>

#define MAXNUM	100001

using namespace std;


void swap(int * ptr1, int * ptr2) {
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

void print_arr(int * arr, int len) {

	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void merge(int * arr, int start, int mid, int end) {

	int * left = new int[mid - start + 1];
	int * right = new int[end - mid ];

	int left_idx = 0,right_idx=0,arr_idx=start;
	
	for (int i = start; i <= mid; i++)
		left[left_idx++] = arr[i];
	for (int i = mid+1; i <= end; i++)
		right[right_idx++] = arr[i];

	left_idx = right_idx = 0;

	while (left_idx < mid - start + 1 && right_idx < end - mid) {

		if (left[left_idx] > right[right_idx]) {
			arr[arr_idx] = right[right_idx];
			right_idx++;
		}
		else {
			arr[arr_idx] = left[left_idx];
			left_idx++;
		}

		arr_idx++;
	}

	if (left_idx < mid - start + 1)
		for (int i = left_idx; i < mid - start + 1; i++) {
			arr[arr_idx] = left[i];
			arr_idx++;
		}

	if (right_idx < end - mid )
		for (int i = right_idx; i < end - mid; i++) {
			arr[arr_idx] = right[i];
			arr_idx++;
		}

	free(left);
	free(right);
}

void merge_sort(int * arr, int start,int end) {

	if (start < end) {
		int mid = (start + end) / 2;
	
		merge_sort(arr,start, mid);
		merge_sort(arr, mid + 1, end);
		
		merge(arr,start,mid,end );
	}

}

int main(void) {

	int N,arr[MAXNUM];
	
	int time = clock();
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	merge_sort(arr, 0, N-1);

	print_arr(arr, N);

	time = clock() - time;

	printf("%d sec\n", time / CLOCKS_PER_SEC);

	return 0;
}