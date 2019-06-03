#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <math.h>

#define MAXNUM	1001

using namespace std;

int arr[MAXNUM][MAXNUM];

int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

int main() {

	int N,r=0,c=-1,cnt=1,dir_cnt=0,wall=0;
	scanf("%d", &N);

	while (1) {

		while (1) {

			r = r + dir[(dir_cnt % 4)][0], c = c + dir[(dir_cnt % 4)][1];

			if (dir_cnt % 2 == 1) {
				if (!(r >= wall && r < N - wall)) {
					r = r - dir[(dir_cnt % 4)][0], c = c - dir[(dir_cnt % 4)][1];
					break;
				}
			}else {

				if (!(c >= wall && c < N - wall)) {
					r = r - dir[(dir_cnt % 4)][0], c = c - dir[(dir_cnt % 4)][1];
					break;
				}

			}

			arr[r][c] = cnt++;
		
		}

		dir_cnt++;
		if (dir_cnt % 4 == 3)
			wall++;

		if (cnt > N*N)
			break;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%d ", arr[i][j]);

		printf("\n");
	}

	return 0;
}