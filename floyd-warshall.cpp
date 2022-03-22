#include<bits/stdc++.h>
using namespace std;
#define n 100
void floyd_warshall(int mat[n][n], int M[][n])
{
	int i, j, k;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			M[i][j] = mat[i][j];
	for(k = 0; k < n; k++) 
	#pragma omp parallel for private(j) 
		for(i = 0; i < n; i++) 
			for(j = 0; j < n; j++) 
				M[i][j] = min(M[i][j],M[i][k]+M[k][j]);
}
int main()
{
	
	int mat[n][n], M[n][n];
	floyd_warshall(mat, M);
	return 0;
}