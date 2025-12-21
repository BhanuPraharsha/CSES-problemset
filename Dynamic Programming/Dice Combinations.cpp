#include<bits/stdc++.h>
using namespace std;
 
# define MOD 1000000007
//main code
 
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
		int n;
		cin>>n;
		
		vector<int> a(7);
		
		a[1]=1;
		a[2]=2;
		a[3]=4;
		a[4]=8;
		a[5]=16;
		a[6]=32;
		
		a.resize(n+1);
		
		if(n>6)
		{
			for(int j=7;j<=n;j++)
		{
			a[j]=(((a[j-1] + a[j-2])%MOD + (a[j-3] + a[j-4])%MOD)%MOD + (a[j-5] + a[j-6])%MOD)%MOD;
		}
		}
		
		
		cout<<a[n]<<endl;
	return 0;
}
 

