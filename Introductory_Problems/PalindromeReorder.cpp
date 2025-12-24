#include<bits/stdc++.h>
using namespace std;
//main code
 
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
//	int t;
//	cin>>t;
 
	for(int i=0;i<1;i++)
	{
		string s;
		cin>>s;
		int n=s.size();
		
		unordered_map<char, int> freqcount;
		
		for(int j=0;j<n;j++)
		{
			freqcount[s[j]]++;
		}
		
		bool possible=true;
		int evenc=0;
		int oddc=0;
		
		for(auto it=freqcount.begin(); it!=freqcount.end(); it++)
		{
			if(((it->second)%2)==0)
			{
				evenc++;
			}
			else{
				oddc++;
			}
		}
		
		if(oddc>1)
		{
			cout<<"NO SOLUTION"<<endl;
		}
		else{
			string res(n, ' ');
			int curr = 0;
 
			for (auto it = freqcount.begin(); it != freqcount.end(); it++) {
    			int j = it->second;
 
    			if (j % 2 == 1) {
        			res[n/2] = it->first;   // middle character
        			j--; // use one occurrence for the middle
   				}
 
    // place j/2 chars on the left
   			fill(res.begin() + curr, res.begin() + curr + j/2, it->first);
 
    // place j/2 chars on the right
    		fill(res.begin() + n - curr - j/2, res.begin() + n - curr, it->first);
 
   			curr += j/2;
			}
			cout << res << "\n";
 
		}
	}
	return 0;
}

