#include<bits/stdc++.h>
using namespace std;
 
// Common Operations
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.rbegin(), v.rend())
#define mxe(v) *max_element(v.begin(), v.end())
#define mne(v) *min_element(v.begin(), v.end())
 
//sieve progrom to precompute primes
const int MAX = 1e6 + 1;
bitset<MAX> is_prime;
vector<int> primes;
 
void sieve() {
   is_prime.set();
    is_prime[0] = is_prime[1] = 0;
 
    for (long long i = 2; i * i <= MAX; ++i) {
        if (is_prime[i]) {
            for (long long j = i * i; j < MAX; j += i)
                is_prime[j] = 0;
        }
    }
}
 
 
 
//main code
 
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    
   	for(int j=2;j<MAX;j++)
		{
			if(is_prime[j])
			{
				primes.push_back(j);
			}
		}
		
//		for(int j=0;j<primes.size();j++)
//		{
//			cout<<primes[j]<<" ";
//		}
//		
//		cout<<endl<<endl;
//		
//		cout<<"done with primes "<<endl;
 
	int t;
	cin>>t;
	
 
 
 
	for(int i=0;i<t;i++)
	{
		
//		cout<<"testcase: "<<i<<endl;
		
		
		int x;
		cin>>x;
		long long int ans=1;
		
		if(x==1)
		{
			ans=1;
			cout<<1<<endl;
			continue;
		}
		
		
		for(int j=0;primes[j]*primes[j]<=x;j++)
		{
			int temp=0;
//			cout<<"checking primefactor as "<<primes[j]<<endl;
			while(x%primes[j]==0)
			{
				temp++;
				x/=primes[j];
//				cout<<"primefactorfound: "<<primes[j]<<" modified x: "<<x<<endl;				
			}
			
			
			ans*=(long long int)(temp+1);
//			cout<<"modified ans: "<<ans<<endl;
			
		}
		
		if(ans==1 || x!=1)
		{
			ans*=2;
		}
		
		
		cout<<ans<<endl;
	}
	return 0;
}

