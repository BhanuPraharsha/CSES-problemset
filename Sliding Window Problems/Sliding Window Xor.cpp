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
		long long int n, k;
		cin>>n>>k;
		
		long long int x, a,b,c;
		cin>>x>>a>>b>>c;
		
		
		vector<long long int> arr(n);	
		arr[0]=x;
 
		for(int j=1;j<n;j++)
		{
			arr[j]=(a*arr[j-1] + b)%c;
		}
		
//		for(int j=0;j<n;j++)
//		{
//			cout<<arr[j]<<" ";
//		}
//		
//		cout<<endl;
//		
		
		
		long long int ans=0;
		long long int prev;
		
		for(int j=0;j<k;j++)
		{
			ans^=arr[j];
		}
		prev=ans;
		
//		cout<<"first xor: "<<ans<<endl;
		
		
		
		for(int j=0;j<n-k;j++)
		{
//			cout<<"removing element: "<<arr[j]<<" adding elelement: "<<arr[j+k]<<endl;
			long long int curr=prev^arr[j]^arr[j+k];
			prev=curr;
			ans^=curr;
			
			
//			cout<<"current xor :"<<curr<<endl;	
//			cout<<"xor of xors till now: "<<ans<<endl;
			
//			cout<<"new ans: "<<ans<<endl;
			
		}
		
		cout<<ans<<endl;
	}
	
		
	return 0;
}
 

