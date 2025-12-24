#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    // int t;
    // cin>>t;
 
    for(int i=0;i<1;i++)
    {
    	int n;
    	cin>>n;
    	
    	vector<int> a(n);
    	long long int minn=LLONG_MAX;
    	for(int j=0;j<n;j++) 
		{
			cin>>a[j];
		}
	
    	
    	vector<long long int> psum(n+1, 0);
    	for(int j=1;j<=n;j++)
    	{
    		psum[j]=psum[j-1]+a[j-1];
		}
		
		vector<long long int> minfst(n+1);
		long long int maxx=LLONG_MIN;
		minn=LLONG_MAX;
		
		for(int j=0;j<=n;j++)
		{
			minn=min(minn, psum[j]);
			minfst[j]=minn;
		}
		
		maxx=LLONG_MIN;
		
		
		
		for(int j=1;j<=n;j++)
		{
			maxx=max(psum[j]-minfst[j-1], maxx);
		}
    	
    	
    	cout<<maxx<<endl;
    	
        
    }
                
    return 0;
}
 

