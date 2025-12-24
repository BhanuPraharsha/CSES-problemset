#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
 
	for(int i=0;i<1;i++)
	{
		int n,k;
		cin>>n>>k;
		
		vector<pair<int, int>> a(n);
		
		for(int j=0;j<n;j++)
		{
			int x,y;
			cin>>x>>y;
			a[j].first=x;
			a[j].second=y;
		}
		
		sort(a.begin(), a.end(), [](const pair<int, int>& x, const pair<int, int> &y){
		if(x.second==y.second) return x.first < y.first;
		return x.second < y.second;
		});
		
		
		int ans=0;
		multiset<int> etimes;
		
		for(int j=0;j<k;j++)
		{
			etimes.insert(0);
		}
		
		for(int j=0;j<n;j++)
		{
			auto it=etimes.upper_bound(a[j].first);
			
			if(it!=etimes.begin())
			{
				it--;
				
				etimes.erase(it);
				etimes.insert(a[j].second);
				ans++;
			}	
		}
		
		cout<<ans<<endl;	
	}
	return 0;
}
