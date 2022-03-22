#include<bits/stdc++.h>
#include<string>
#include <fstream>
#define row 1000
#define col 1000

using namespace std;
int main()
{
	fstream fin;
	fin.open ("testcase.txt", ios::in);
	int a,i=0,j=0;
	int adj_mat[row][col];
	while(fin)
	{
		fin>>adj_mat[i][j];
		if(j == col-1)
		{
			i++;
			j=0;
		}
		else
			j++;
	}
	fin.close();
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
			cout<<adj_mat[i][j];
		cout<<endl;
	}
}