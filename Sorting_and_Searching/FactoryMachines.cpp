#include<bits/stdc++.h>
using namespace std;
 
 
long long int helper(vector<long long int> &a, long long int mid)
{
	long long int ans=0;
	for(int j=0;j<a.size();j++)
	{
		ans+=mid/a[j];
	}
	
	return ans;
}
 
 
 
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
 
	for(int i=0;i<1;i++)
	{
		int n,t;
		cin>>n>>t;
		
		vector<long long int> a(n);
		long long int minn=LLONG_MAX;
		for(int j=0;j<n;j++)
		{
			cin>>a[j];
			minn=min(minn, a[j]);
		}
		
		
		long long int low=0LL, high=minn*t;
		long long int ans=high;
		
		while(low<=high)
		{
			long long int mid=low + (high-low)/2LL;
			
			if(helper(a, mid) >=t)
			{
				ans=mid;
				high=mid-1;
			}
			else{
				low=mid+1;
			}
		}
		
		cout<<ans<<endl;
	}
				
	return 0;
}

