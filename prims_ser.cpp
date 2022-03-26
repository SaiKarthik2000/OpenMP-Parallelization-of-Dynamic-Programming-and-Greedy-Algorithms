#include<fstream>
#include <bits/stdc++.h>
#include<omp.h>
using namespace std;

#define V 1000         // Number of vertices in the graph

int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
   	    if (mstSet[v] == false && key[v] < min)
   		   min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int graph[V][V])
{
    cout<<"Edge \tWeight\n";
    for (int i = 1; i < V; i++)
   	    cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
}

void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++)
       	key[i] = INT_MAX, mstSet[i] = false;           // Initialize all keys as INFINITE
    
    key[0] = 0;
    parent[0] = -1;                                 // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++)
    {
       	 int u = minKey(key, mstSet);                   // Pick the minimum key vertex from the
       	                                                // set of vertices not yet included in MST

       	 mstSet[u] = true;                              // Add the picked vertex to the MST Set
       	 for (int v = 0; v < V; v++)
        {
       		 if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
       			 parent[v] = u, key[v] = graph[u][v];
        }
    }

    //printMST(parent, graph);
}

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