#include<bits/stdc++.h>
using namespace std;
 
//main code
 
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
 
	cin>>t;
 
	for(int i=0;i<t;i++)
	{
		unsigned long long int x, y;
		cin>>y>>x;
		y--;
		x--;
		
		
		if(x>=y)
		{
			if(x%2!=0)
			{
				cout<<(x*x) + y+1<<endl;
			}
			else{
				cout<<(x+1)*(x+1) -y<<endl;
			}			
 
		}
		else{
						if(y%2!=0)
			{
				cout<<(y+1)*(y+1) - x<<endl; 
			}
			else{
				cout<<(y*y) + x+1<<endl;
			}
		}
 
		
	}
	return 0;
}

