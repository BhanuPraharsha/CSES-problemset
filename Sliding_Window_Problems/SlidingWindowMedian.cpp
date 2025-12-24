#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int,int>, null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
ordered_multiset omset;
int uid = 0;

void insert(int x) {
    omset.insert({x, uid++});
}

void erase(int x) {
    auto it = omset.lower_bound({x, -1});
    if (it != omset.end() && it->first == x)
        omset.erase(it);
}

int kth(int k) {              
    return omset.find_by_order(k)->first;
}

int main()
{
	//Timer t; // optional, for timing execution t.print();
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(int j=0;j<n;j++) cin>>a[j];
	
	int tar=(k%2)?(k/2):((k/2)-1);
	for(int j=0;j<k;j++)
	{
		insert(a[j]);
	}
	
	cout<<kth(tar)<<" ";
	for(int j=k;j<n;j++)
	{
		insert(a[j]);
		erase(a[j-k]);
		cout<<kth(tar)<<" ";
	}
	
	return 0;
}


