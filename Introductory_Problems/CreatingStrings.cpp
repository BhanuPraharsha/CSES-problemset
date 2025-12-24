#include<bits/stdc++.h>
using namespace std;
 
void permutate(string &s, set<string> &ss, int start, int end)
{
	if(start==end)
	{
		ss.insert(s);
	}
	else{
		for(int j=start;j<=end;j++)
		{
			swap(s[start], s[j]);
			permutate(s, ss, start+1, end);
			swap(s[start], s[j]);
		}
	}
}
 
 
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
//	cin>>t;
 
	for(int i=0;i<1;i++)
	{
		string s;
		cin>>s;
		set<string> ss;
		permutate(s, ss, 0, s.size()-1);
		
		cout<<ss.size()<<endl;
		
		for(auto it=ss.begin(); it!=ss.end();it++)
		{
			cout<<*it<<endl;
		}
		
	}
				
	return 0;
}

