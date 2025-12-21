#include<bits/stdc++.h>
using namespace std;
 
# define MOD 1000000007
//main code
 
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin>>n>>x;
    vector<int> c(n);
    for(int j=0;j<n;j++)
    {
    	cin>>c[j];
	}
	
	sort(c.begin(), c.end());
	
	vector<int> dp(x+1, 1e9);
	dp[0]=0;
	
	for(int j=1;j<=x;j++)
	{
		for(int k=0;(j-c[k]>=0) && (k<n);k++)
		{
		dp[j]=min(dp[j], dp[j-c[k]] + 1);
		}
	}
	
	if(dp[x]<=x){
		cout<<dp[x]<<endl;
	}
	else{
		cout<<-1<<endl;
	}
    
    
    
	return 0;
}
 
 
