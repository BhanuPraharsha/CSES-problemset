#include<bits/stdc++.h>
using namespace std;
 
 
bool helper(vector<int> &a, long long int mid, int k)
{
	int ans=1;
	long long int sum=0;
	for(int j=0;j<a.size();j++)
	{
		if(sum+(long long int)a[j] <= mid)
		{
			sum+=(long long int)a[j];
		}
		else{
			ans++;
			sum=(long long int)a[j];
		}
	}
	
	return (ans<=k)? true: false;
}
 
 
 
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
 
	for(int i=0;i<1;i++)
	{
		int n,k;
		cin>>n>>k;
		
		vector<int> a(n);
		long long int maxx=LLONG_MIN;
		long long int sum=0;
		for(int j=0;j<n;j++)
		{
			cin>>a[j];
			maxx=max(maxx, (long long int)a[j]);
			sum+=a[j];
		}
		
		
		
		long long int low=maxx, high=sum;
		long long int ans=high;
		
		while(low<=high)
		{
			long long int mid=low + (high-low)/2LL;
			
			if(helper(a, mid, k))
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

