#include <iostream>
using namespace std;
#include <limits.h>
#include <omp.h>
#include<fstream>

#define V 1000


int minDistance(int dist[], bool sptSet[])
{

	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}


void printSolution(int dist[])
{
	cout <<"Vertex \t Distance from Source" << endl;
	for (int i = 0; i < V; i++)
		cout << i << " \t\t"<<dist[i]<< endl;
}

double dijkstra(int graph[V][V], int src)
{
	int dist[V]; 

	bool sptSet[V]; 
	for (int i = 0; i < V; i++){
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}

	dist[src] = 0;
	double st = omp_get_wtime();
	for (int count = 0; count < V - 1; count++) {
		int u = minDistance(dist, sptSet), v;
		sptSet[u] = true;
		for (v = 0; v < V; v++){

			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
		}
	}
	double en = omp_get_wtime();

	return (en - st);
}

int main()
{

	fstream fin;
	fin.open ("testcase.txt", ios::in);
	int a, i = 0, j = 0;
	int mat[V][V];
	while(fin)
	{
		fin>>mat[i][j];
		if(j == V - 1)
		{
			i++;
			j=0;
		}
		else
			j++;
	}
	fin.close();
	double tot_time = dijkstra(mat, 0);
	cout<<"Total Time for a Vertex: "<<tot_time<<endl;
	return 0;
}
