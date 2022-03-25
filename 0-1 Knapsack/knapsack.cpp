#include<bits/stdc++.h>
#include<omp.h>
#include<fstream>
using namespace std;

int Knapsack(int val[],int wt[],long int N,long int W)
{
	int *K = (int*) malloc((W+1)*sizeof(int));
	int *Kp = (int*) malloc((W+1)*sizeof(int));
	long int i, w;

	for (i = 0; i <= N; i++)
	{
		for (w = 0; w <= W; w++)
		{
			if (i==0 || w==0)
				K[w] = 0;
			else if (wt[i-1] <= w)
				K[w] = max(val[i-1] + Kp[w-wt[i-1]], Kp[w]);
			else
				K[w] = Kp[w];
		}
		int *tmp = Kp;
		Kp = K;
		K = tmp;
	}

	int result = K[W];

	free(K);
	free(Kp);

	return result;
}
int Knapsackomp(int val[],int wt[],long int N,long int W)
{
	int *K = (int*) malloc((W+1)*sizeof(int));
	int *Kp = (int*) malloc((W+1)*sizeof(int));
	long int i, w;

	for (i = 0; i <= N; i++)
	{
		#pragma omp parallel for
		for (w = 0; w <= W; w++)
		{
			if (i==0 || w==0)
				K[w] = 0;
			else if (wt[i-1] <= w)
				K[w] = max(val[i-1] + Kp[w-wt[i-1]], Kp[w]);
			else
				K[w] = Kp[w];
		}
		int *tmp = Kp;
		Kp = K;
		K = tmp;
	}

	int result = K[W];

	free(K);
	free(Kp);

	return result;
}

int main()
{
	fstream fin;
	fin.open ("Test_Cases.txt", ios::in);
	int i=0,r,c,wei;
	fin>>r;
	fin>>c;
	fin>>wei;
	int v[r],w[r];
	while(fin)
	{
		fin>>w[i];
		fin>>v[i];
		i++;
	}
	fin.close();
	// for(int i=0;i<r;i++)
	// {
	// 	cout<<w[i]<<" "<<v[i];
	// 	cout<<endl;
	// }
	
	double start_time = omp_get_wtime();
	long int max=Knapsack(v,w,r,wei);
	cout<<"The maximum value that can be collected in knapsack is "<<max<<endl;
	double end_time = omp_get_wtime();
	cout<<"The time taken by knapsack without omp is "<<end_time-start_time<<endl;
	start_time = omp_get_wtime();
	max=Knapsackomp(v,w,r,wei);
	end_time = omp_get_wtime();
	cout<<"The maximum value that can be collected in knapsack is "<<max<<endl;
	cout<<"The time taken by knapsack with omp is "<<end_time-start_time<<endl;
	return 0;
}
