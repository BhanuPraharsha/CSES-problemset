#include<bits/stdc++.h>
using namespace std;
 
 
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
	for(int i=0;i<1;i++)
	{
		int n,x;
		cin>>n>>x;
		
		vector<int> a(n), p(n+1, 0);
		
		
		
		for(int j=0;j<n;j++)
		{
			cin>>a[j];
			if(j!=0)
			{
				p[j-1]=p[j]+a[j-1];
			}
		}
		
		p[n]=p[n-1] + a[n-1];
		
		int start=0;
		int end=0;
		int sum=a[0];
		
		int ans=0;
		
		while(start<n && end<n )
		{
			if(sum<x)
			{
				end++;				
				sum+=a[end];
			}
			else if(sum>x)
			{
				sum-=a[start];
//				if(start!=end)
//				{
//					start++;
//				}
				start++;
			}
			else{
				
//				cout<<"ans incremetning, indices: "<<start<<", "<<end<<endl;
				ans++;
				end++;
				sum+=a[end];
			}
		}
		
		cout<<ans<<endl;	
	}	
	return 0;
}

