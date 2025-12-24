#include <bits/stdc++.h>
using namespace std;
 
int main() {
	
	
	int n, x;
	cin>>n>>x;
	vector<pair<int,int>> a(n);
	
	for(int j=0;j<n;j++)
	{
		cin>>a[j].first;
		a[j].second=j+1;
	}	
	
	sort(a.begin(), a.end());
	
		
	bool check=false;
	int l,r;
	int count=0;
	
	for(int j=0;j<n-1;j++)
	{
		l=j+1;
		r=n;
		
		auto it=lower_bound(a.begin()+l, a.begin() +r, x-a[j].first, [](const pair<int, int> &p, int value){
			return p.first<value;
			
		});
		
		if(it!=a.begin()+r  &&  it->first == x-a[j].first)
		{
			cout<<a[j].second<<" "<<(it->second)<<endl;
			check=true;
			break;
		}
		
	}
	
	if(!check)
	{
		cout<<"IMPOSSIBLE\n";
	}
	
    return 0;
}

