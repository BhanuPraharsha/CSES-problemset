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
		int n, k;
		cin>>n>>k;
		
		int x, a,b,c;
		cin>>x>>a>>b>>c;
		
		
		vector<long long int> arr(n);	
		arr[0]=x;
 
		for(int j=1;j<n;j++)
		{
			arr[j]=(a*arr[j-1] + b)%c;
		}
		
		
		deque <int> dq;
		
		long long int ans=0;
		
		for(int j=0;j<n;j++)
		{
		
				while(!dq.empty() && dq.front() <= j-k)
				{
					dq.pop_front();
				}
				while(!dq.empty() && arr[dq.back()] > arr[j])
				{
					dq.pop_back();
				}
				
				dq.push_back(j);
				
				if(j>=k-1)
				{
					ans^=arr[dq.front()];
				}
			
			
		}
		
		cout<<ans<<endl;
		
		
		
		
 
	}
	
		
	return 0;
}

