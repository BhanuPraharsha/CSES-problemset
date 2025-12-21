#include<bits/stdc++.h>
using namespace std;
 
 
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
	for(int i=0;i<1;i++)
	{
		int n;
		cin>>n;
		
		multiset<int> bst;
		
		
		for(int j=0;j<n;j++)
		{
//			cout<<"initial bst: ";
//			
//			for(auto& num: bst)
//			{
//				cout<< num<<" ";
//			}
//			
//			cout<<endl;
//			
//			
			int temp;
			cin>>temp;
			auto it = bst.upper_bound(temp);
//			cout<<"j, a[j]: "<<j<<", "<<temp<<endl;
			
			if(it!=bst.end())
			{
//				cout<<"found the value to be modified: "<<*it<<endl;
				bst.erase(it);
				bst.insert(temp);
			}
			else{
//				cout<<"forming new tower\n";
				bst.insert(temp);
			}
			
		}
		
		cout<<bst.size()<<endl;
		
	}	
	return 0;
}

