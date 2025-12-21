#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
 
 
int getmaxdig(int n)
{
	int temp=INT_MIN;
	
	while(n>0)
	{
		int last=n%10;
		temp=max(temp, last);
		n/=10;
	}
	
	return temp;
	
}
 
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
		
		
		vector<long int> dp(n+1, 0);
		
		for(int j=1;j<10;j++)
		{
			dp[j]=1;
		}
		
//		vector<int> a(n);
//		for(int j=0;j<n;j++)
//		{
//			cin>>a[j];
//		}
		
		for(int j=10;j<=n;j++)
		{
			int maxdig=getmaxdig(j);
//			cout<<"got max digit for j: "<<j<<" , "<<maxdig<<endl;
			dp[j]=1+dp[j-maxdig];
		}
		
		
		
//		for(int j=0;j<=n;j++)
//		{
//			cout<<dp[j]<<" ";
//		}
		
//		cout<<endl;
		
		cout<<dp[n]<<endl;
	}
	
		
	return 0;
}

