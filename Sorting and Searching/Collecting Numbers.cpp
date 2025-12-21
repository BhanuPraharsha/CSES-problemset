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
		int n;
		cin>>n;
		vector<int> a(n);
		unordered_map<int, int> hmap;
		for(int j=0;j<n;j++)
		{
			cin>>a[j];
			hmap[a[j]]=j;
		}
		
		int ans=1;
		int curridx=hmap[1];
		
		for(int j=2;j<=n;j++)
		{
			if(hmap[j]>curridx)
			{
				curridx=hmap[j];
			}
			else{
				ans++;
				curridx=hmap[j];
			}
		}
		
		cout<<ans<<endl;
	}	return 0;
}
 

