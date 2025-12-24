#include<bits/stdc++.h>
using namespace std;
 
 
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	for(int i=0;i<1;i++)
	{
		int n, k;
		cin>>n>>k;
		
		vector<int> arr(n);
		
		unordered_map<int, int> fmap;
		
		set<pair<int,int>> bst; 
		
		for(int j=0;j<n;j++)
		{
			cin>>arr[j];
		}
		
		
		
		
		for(int j=0;j<k;j++)
		{
			if(fmap[arr[j]]>0)
			{
				bst.erase({-fmap[arr[j]], arr[j]});
			}
			fmap[arr[j]]++;
			bst.insert({-fmap[arr[j]], arr[j]});
		}
		cout<<bst.begin()->second<<" ";
		
		
		for(int j=k;j<n;j++)
		{
			bst.erase({-fmap[arr[j-k]], arr[j-k]});
			fmap[arr[j-k]]--;
			if(fmap[arr[j-k]]>0)
			{
				bst.insert({-fmap[arr[j-k]], arr[j-k]});
			}
			
			
			
			if(fmap[arr[j]]>0)
			{
				bst.erase({-fmap[arr[j]], arr[j]});
			}
			fmap[arr[j]]++;
			bst.insert({-fmap[arr[j]], arr[j]});
			
			cout<<bst.begin()->second<<" ";
		}
		
	}
		
			
	return 0;
}
 
