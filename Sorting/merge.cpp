#include <iostream>

#define MAXNUM	100001

using namespace std;

void merge(int * arr, int start, int mid, int end) {

	int * temp_arr = new int[end+1];
	int j;

	for (int i = start; i <= mid; i++)
		temp_arr[i] = arr[i];

	for (int i = mid + 1; i <= end; i++) {
		int key = arr[i];
		for (j = i - 1; j >= start; j--)
			if (key < temp_arr[j])
				temp_arr[j + 1] = temp_arr[j];
			else
				break;
		temp_arr[j+1] = key;
	}

	for (int i = start; i <= end; i++)
		arr[i] = temp_arr[i];

	free(temp_arr);
}

void merge_sort(int * arr, int start, int end) {

	if (end > start) {

		int mid = (start + end) / 2;

		merge_sort(arr, start, mid);
		merge_sort(arr, mid + 1, end);

		merge(arr, start, mid, end);
	}


}

void print_arr(int * arr,int len) {

	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(void) {

	int N,arr[MAXNUM];
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	merge_sort(arr, 0, N-1);

	print_arr(arr,N);

	return 0;
}