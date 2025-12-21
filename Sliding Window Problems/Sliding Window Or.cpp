#include<bits/stdc++.h>
using namespace std;
 
struct stak{
	long long int val;
	long long int por;
};
 
vector<stak> sinn, sout;
 
long long int sinor()
{
	if(sinn.size())
	{
		return sinn.back().por;
	}
	return 0;
}
 
long long int soutor()
{
	if(sout.size())
	{
		return sout.back().por;
	}
	return 0;
}
 
long long int tor()
{
	return soutor() | sinor();
}
 
 
void add(long long int val)
{
	long long int prevor = sinor();
	sinn.push_back({val, val | prevor});
}
 
void remove()
{
	if(sout.size()==0)
	{
		while(sinn.size()!=0)
		{
			long long int val=sinn.back().val;
			sinn.pop_back();
			
			sout.push_back({val, soutor() | val});	
		}
		
	}
	sout.pop_back();
}
 
 
 
 
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	for(int i=0;i<1;i++)
	{
		int n, k;
		cin>>n>>k;
		
		long long int x, a,b, c;
		cin>>x>>a>>b>>c;
		vector<long long int> arr(n);
		long long int cxor;
		
		arr[0]=x;
 
		
		for(int j=1;j<n;j++)
		{
			arr[j]=(a*arr[j-1] +b)%c;
		}
		
		for(int j=0;j<k;j++)
		{
			add(arr[j])	;
		}
		
		cxor=tor();
		
		for(int j=k;j<n;j++)
		{
			remove();
			add(arr[j]);
			cxor^=tor();
		}
 
		cout<<cxor<<endl;
 
		}
		
			
	return 0;
}

