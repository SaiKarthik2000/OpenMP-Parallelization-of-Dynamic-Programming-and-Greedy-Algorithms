#include<bits/stdc++.h>
#include<omp.h>
using namespace std;

int LCS(string text1, string text2,int m,int n) 
{
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(text1[i-1]==text2[j-1])
            {
                dp[i][j] = 1+ dp[i-1][j-1];
            }
            else 
            	dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}
int LCSOMP(string text1, string text2,int m,int n) 
{
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i=1;i<=m;i++)
    {
    	#pragma omp parallel for
        for(int j=1;j<=n;j++)
        {
            if(text1[i-1]==text2[j-1])
            {
                dp[i][j] = 1+ dp[i-1][j-1];
            }
            else 
            	dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}
int main()
{
	int len1=4;
	freopen ("Test_Cases_1.txt", "r", stdin); 
	string str1,str2;
	getline(cin, str1);
	getline(cin, str2);
	//cout<<str1<<endl;
	//cout<<str2;
	int m = str1.length();
    int n = str2.length();
    double start_time =  omp_get_wtime();
	int len=LCS(str1,str2,m,n);
	cout<<"The length of longest common subsequence is "<<len<<endl;
	double end_time = omp_get_wtime();
	cout<<"The time taken by LCS without omp is "<<end_time-start_time<<endl;
	start_time = omp_get_wtime();
	len1+=LCSOMP(str1,str2,m,n);
	cout<<"The length of longest common subsequence is "<<len1<<endl;
	end_time = omp_get_wtime();
	cout<<"The time taken by LCS with omp is "<<end_time-start_time<<endl;
    return 0;
}
