
#include <bits/stdc++.h>
#include<omp.h>
#include<fstream>
using namespace std;

// Number of vertices in the graph
#define V 1000

int minKey(int key[], bool mstSet[])
{
	int min = INT_MAX, index;
    #pragma omp parallel 
    {
    	int index_local = index;
    	int min_local = min;
    	#pragma omp for nowait
        	for (int i = 0; i < V; i++)
        	{
            	if (mstSet[i] == 0 && key[i] < min_local)
            	{
                	min_local = key[i];
                	index_local = i;
            	}
        	}
    	#pragma omp critical
    	{
        	if (min_local < min) {
            	min = min_local;
            	index = index_local;
        	}
    	}
    }
        
    /*
        for (int v = 0; v < V; v++)
   	        if (mstSet[v] == false && key[v] < min)
            {
   		        min = key[v], 
                index = v;
            }
    */
	return index;
}



void primMST(int graph[V][V])
{
    int parent[V];
    
    int key[V];
    bool mstSet[V];

    //#pragma omp parallel for shared(key,mstSet)
    for (int i = 0; i < V; i++)
   	    key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1; 

    for (int count = 0; count < V - 1; count++)
    {
   	    int u = minKey(key, mstSet);

   	    mstSet[u] = true;
   	    #pragma omp parallel for 
   		for (int v = 0; v < V; v++)
    
   			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
   				parent[v] = u, key[v] = graph[u][v];
    }
}

// Driver code
int main()
{ 
    fstream fin;
    fin.open ("testcase.txt", ios::in);
    int a, i = 0, j = 0;
    int graph[V][V];
    while(fin)
    {
        fin>>graph[i][j];
        if(j == V - 1)
        {
            i++;
            j=0;
        }
        else
            j++;
    }
    fin.close();

    double start = omp_get_wtime();
    primMST(graph);

    double end = omp_get_wtime();
    cout<<"Time taken:"<<end-start;

    return 0;
}
