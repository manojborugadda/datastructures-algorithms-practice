#include <bits/stdc++.h>
using namespace std;

#define N 4

// Converts A[][] to its transpose
void transpose(int A[][N])
{
	for (int i = 0; i < N; i++)
		for (int j = i+1; j < N; j++)
			swap(A[i][j], A[j][i]);
}

int main()
{
	int A[N][N] = { {1, 1, 1, 1},
					{2, 2, 2, 2},
					{3, 3, 3, 3},
					{4, 4, 4, 4}};

	transpose(A);

	printf("Modified matrix is \n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		printf("%d ", A[i][j]);
		printf("\n");
	}

	return 0;
}
