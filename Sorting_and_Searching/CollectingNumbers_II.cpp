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
		int n,m;
		cin>>n>>m;
		vector<int> a(n);
		unordered_map<int, int> hmap;
		for(int j=0;j<n;j++)
		{
			cin>>a[j];
			hmap[a[j]]=j;
		}
		
		int baseans=1;
		int curridx=hmap[1];
		
		for(int j=2;j<=n;j++)
		{
			if(hmap[j]>curridx)
			{
				curridx=hmap[j];
			}
			else{
				baseans++;
				curridx=hmap[j];
			}
		}
		
//		cout<<"base ans: "<<baseans<<endl;
		
		
		for(int j=0;j<m;j++)
		{
			int p1,p2;
			cin>>p1>>p2;
			p1--;
			p2--;
			
			int tosub=0;
			int toadd=0;
			
			int v1=a[p1];
			int v2=a[p2];
			
			set<int> aff;
			if(v1>1)
			{
				aff.insert(v1-1);
			}
			aff.insert(v1);
			if(v2>1)
			{
				aff.insert(v2-1);
			}
			aff.insert(v2);
			
			for(int v : aff)
			{
				if(v<n && hmap[v+1]<hmap[v])
				{
					tosub++;
				}
			}
 
 
							
				
			
//			cout<<"tosub: "<<tosub<<endl;
			
			hmap[a[p1]]=p2;
			hmap[a[p2]]=p1;
			swap(a[p1], a[p2]);
			
			for(int v : aff)
			{
				if(v<n && hmap[v+1]<hmap[v])
				{
					toadd++;
				}
			}
			
			
//			cout<<"toadd: "<<toadd<<endl;
//			
			
			cout<<baseans+toadd-tosub<<endl;
			baseans+=toadd-tosub;
//			cout<<"updated base ans: "<<baseans<<endl;
		}
	}	return 0;
}

