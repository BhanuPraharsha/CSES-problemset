#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
 
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
//	int t;
//	cin>>t;
 
	for(int i=0;i<1;i++)
	{
		int n;
		cin>>n;
		
		
		vector<vector<char> > a(n, vector<char> (n, 0));
		vector<vector<int> > dp(n, vector<int> (n, 0));
 
		
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				cin>>a[j][k];
			}
		}
		
		if(a[0][0] == '*' || a[n-1][n-1]=='*')
		{
			cout<<0<<endl;
			continue;
		}
		
		dp[0][0]=1;
		
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				if(a[j][k]=='*')
				{
					continue;
				}
				
				if(j>0)
				{
					dp[j][k]=(dp[j][k]+dp[j-1][k])%MOD;
				}
				
				if(k>0)
				{
					dp[j][k]=(dp[j][k]+dp[j][k-1])%MOD;
				}
				
				
			}
		}
		cout<<dp[n-1][n-1]<<endl;
	}
	
		
	return 0;
}

