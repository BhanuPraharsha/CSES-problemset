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
		int n, x;
		cin>>n>>x;
		
		
		vector<long int> dp(x+1, 0);
		dp[0]=1;
		
		vector<int> a(n);
		for(int j=0;j<n;j++)
		{
			cin>>a[j];
		}
		
		for(int j=0;j<n;j++)
		{
			for(int k=a[j];k<=x;k++)
			{
				dp[k]= (dp[k] + dp[k-a[j]])%MOD;
			}
		}
		
		cout<<dp[x]<<endl;
	}
	
		
	return 0;
}
 
 
