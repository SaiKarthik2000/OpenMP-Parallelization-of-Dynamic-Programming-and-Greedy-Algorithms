// A C++ Program to generate matrix filled with random numbers
#include<bits/stdc++.h>
using namespace std;

// Define the number of runs for the test data
// generated
#define RUN 1

// Define the range of the test data generated
#define MAX 50

// Define the maximum rows in matrix
#define MAXROW 1000

// Define the maximum columns in matrix
#define MAXCOL 1000

int main()
{
	// Uncomment the below line to store
	// the test data in a file
	freopen ("testcase.txt", "w", stdout);

	// For random values every time
	srand(time(NULL));

	for (int i=1; i<=RUN; i++)
	{
		// Number of rows and columns
		int row = MAXROW;
		int col = MAXCOL;

		// Then print the matrix
		for (int j=1; j<=row; j++)
		{
			for (int k=1; k<=col; k++)
				printf("%d ", rand() % MAX);
			printf("\n");
		}
		printf("\n");
	}

	// Uncomment the below line to store
	// the test data in a file
	fclose(stdout);
	return(0);
}
