#include<bits/stdc++.h>
using namespace std;
 
 
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
		
		long long int x, a,b, c;
		cin>>x>>a>>b>>c;
		vector<long long int> arr(n);
		long long int sum=0;
		long long int cxor;
		
		arr[0]=x;
 
		
		for(int j=1;j<n;j++)
		{
			arr[j]=(a*arr[j-1] +b)%c;
		}
		
		for(int j=0;j<k;j++)
		{
			sum+=arr[j];
		}
		
		cxor=sum;
		
		
		for(int j=1;j+k<n+1;j++)
		{
			sum+=arr[j+k-1];
			sum-=arr[j-1];
			
			cxor^=sum;
		}
		
		cout<<cxor<<endl;
			}
	return 0;
}
 
 
