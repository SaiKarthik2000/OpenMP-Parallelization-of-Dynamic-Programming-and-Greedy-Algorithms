#include<bits/stdc++.h>
using namespace std;

 
// Define the range of the test data generated
#define MAX 1000 

int main()
{
    freopen ("Test_Cases.txt", "w", stdout);
    srand(time(NULL));
    int row = 10000;
    int col = 2;
    int wei = 50000;
    printf("%d %d %d\n", row,col,wei);
    for (int j=1; j<=row; j++)
    {
        for (int k=1; k<=col; k++)
            printf("%d ", rand() % MAX);
        printf("\n");
    }
    printf("\n");
    fclose(stdout);
    return(0);
}
