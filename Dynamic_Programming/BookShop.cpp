#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
//	int t;
//	cin>>t;
 
	for(int i=0;i<1;i++)
	{
		int n,x;
		cin>>n>>x;
		
		vector<int> p(n), c(n);
		
		for(int j=0;j<n;j++)
		{
			cin>>p[j];
		}
		
		for(int j=0;j<n;j++)
		{
			cin>>c[j];
		}
		
		vector<vector<int> > dp(n+1 ,vector<int> (x+1, 0));
		
		for(int k=1; k<=n;k++)
		{
			for(int l=1;l<=x;l++)
			{
				if(p[k-1]<=l)
				{
					dp[k][l]=max(dp[k-1][l], c[k-1] + dp[k-1][l-p[k-1]]);
				}
				else{
					dp[k][l]=dp[k-1][l];
				}
			}
		}
		
		cout<<dp[n][x]<<endl;
	}
	return 0;
}

