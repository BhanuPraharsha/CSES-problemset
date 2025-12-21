#include<bits/stdc++.h>
using namespace std;
long long int MOD =1000000007;
 
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, x;
    cin>>n>>x;
    vector<int> a(n);
	vector<int> dp(x+1, 0);\
	dp[0]=1;
	
    for(int j=0;j<n;j++)
    {
    	cin>>a[j];
	}
	
	sort(a.begin(), a.end());
	
	
	for(int j=1;j<=x;j++)
	{
		for(int k=0;k<n;k++)
		{
			if(j>=a[k])
			{
				dp[j]+=(dp[j-a[k]]);
				if (dp[j] >= MOD) dp[j] -= MOD;			}
			else{
				break;
			}
			
		}
		
	}
	
	cout<<dp[x]<<endl;
	
	
//	for(int j=0;j<=x;j++)
//	{
//		cout<<dp[j]<<" ";
//	}
//	cout<<endl;
	return 0;
}
 

