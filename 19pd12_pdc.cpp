#include<bits/stdc++.h>
#include<omp.h>
using namespace std;
int lcs( string X,string Y, int m, int n )
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m-1] == Y[n-1])
        return 1 + lcs(X, Y, m-1, n-1);
    else
        return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}
int main()
{
	freopen ("Test_Cases_1.txt", "r", stdin); 
	string str1,str2;
	getline(cin, str1);
	getline(cin, str2);
	//cout<<str1<<endl;
	//cout<<str2;
	int m = str1.length();
    	int n = str2.length();
    	cout<<m<<n;
    	//double start_time = omp_get_wtime();
	cout<<"Length of LCS is "<< lcs( str1, str2, m, n ) ;
	//double end_time = omp_get_wtime();
	//cout<<"The time taken by lcs with omp is "<<end_time-start_time;
	return 0;
     	
	/*for(i=1;i<n;i++)
	{
		for(j=1;j<n;j++)
		{
			if(S[i] == T[j]) 
				c[i,j] = c[i-1,j-1]+1;
			else 
				c[i,j] = max(c[i,j-1],c[i-1,j]);
		}
	}
	for(int k=2;k<=10000;k++)
	{
		#pragma omp parallel for
		for(int i=1;i<k;i++)
		{
			if(S[i] == T[(k-i)])
				c[w(i,k-i)] = c[w(i-1,(k-i)-1)]+1;
			else
				c[w(i,(k-i))] = max(c[w(i,(k-i)-1)], c[w(i-1,(k-i))]);
		}
	}
	for(int k=10000+1;k<=2*(10000-1);k++)
	{
		#pragma omp parallel for
		for(i=(k-10000)+1;i<10000;i++)
		{
			if(S[i] == T[k-i])
				c[i,k-i] = c[i-1,(k-i)-1]+1;
			else
				c[i,(k-i)] = max(c[i,(k-i)-1], c[i-1,(k-i)]);
		}
	}*/
}



