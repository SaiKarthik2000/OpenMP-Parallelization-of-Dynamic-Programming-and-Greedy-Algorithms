#include<bits/stdc++.h>
using namespace std;

int Knapsackomp(v, w, n, W)
{
	for(i = 1;i ≤ n; j++)
	{
		#pragma omp parallel for
		for(j = 1; j ≤ W; j++)
		{
			if(w[i]≤ j)
				V [i%2, j]= max{ V [(i−1)%2, j],v[i]+V [i− 1, j − w[i]] };
			else
				V [%2i, j]=V [(i − 1)%2, j];
		}
	}
	return V [n, W];
}

int Knapsack(v, w, n, W)
{
	for(i = 1;i ≤ n; j++)
	{
		for(j = 1; j ≤ W; j++)
		{
			if(w[i]≤ j)
				V [i, j]= max{ V [i − 1, j],v[i]+V [i − 1, j − w[i]] };
			else
				V [i, j]=V [i − 1, j];
		}
	}
	return V [n, W];
}
int main()
{

	double start_time = omp_get_wtime();
	long int max=Knapsack(v,w,n,W)
	double end_time = omp_get_wtime();
	cout<<"The time taken by knapsack without omp is "<<end_time-start_time;
	double start_time = omp_get_wtime();
	
	double end_time = omp_get_wtime();
	cout<<"The time taken by knapsack with omp is "<<end_time-start_time;
	
}
