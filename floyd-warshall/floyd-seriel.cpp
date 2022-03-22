#include<bits/stdc++.h>
#include<omp.h>
using namespace std;
#define n 1000
double floyd_warshall(int mat[n][n])
{
	int i, j, k, M[n][n];
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			M[i][j] = mat[i][j];
	double st = omp_get_wtime();
	for(k = 0; k < n; k++)
	{ 
		//#pragma omp parallel for private(j) 
		for(i = 0; i < n; i++) 
			for(j = 0; j < n; j++)
			{
				if(M[i][j] != 0)
					M[i][j] = min(M[i][j],M[i][k]+M[k][j]);
				else
					M[i][j] = M[i][k]+M[k][j];
			}
	}
	double en = omp_get_wtime();
	return (en - st);
}
int main()
{
	fstream fin;
	fin.open("testcase.txt", ios::in);
	int a, i = 0, j = 0;
	int mat[n][n];
	while(fin)
	{
		fin>>mat[i][j];
		if(j == n - 1)
		{
			i++;
			j=0;
		}
		else
			j++;
	}
	fin.close();
	double t = floyd_warshall(mat);
	cout<<"Time Taken = "<<t<<endl;
	return 0;
}