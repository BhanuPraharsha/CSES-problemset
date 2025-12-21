#include<bits/stdc++.h>
using namespace std;
 
// Common Operations
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.rbegin(), v.rend())
#define mxe(v) *max_element(v.begin(), v.end())
#define mne(v) *min_element(v.begin(), v.end())
 
//sieve progrom to precompute primes
//const int MAX = 1e9 + 1;
//bitset<MAX> is_prime;
 
//void sieve() {
//   is_prime.set();
//    is_prime[0] = is_prime[1] = 0;
//
//    for (long long i = 2; i * i <= MAX; ++i) {
//        if (is_prime[i]) {
//            for (long long j = i * i; j < MAX; j += i)
//                is_prime[j] = 0;
//        }
 //   }
//}
 
//gcd function
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
 
 
//main code
 
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
//	cin>>t;
 
	for(int i=0;i<1;i++)
	{
		string s;
		cin>>s;
		int n=s.size();
		int maxx=1;
		for(int j=0;j<n;j++)
		{
			
			int temp=1;
			for(int k=j;k<n;k++)
			{
				if(s[k]==s[k+1])
				{
					temp++;
				}
				else{
					temp=k-j+1;
					maxx=max(maxx, temp);
					j=k;
					break;
				}
			}
		}
		
		cout<<maxx;
	}
	return 0;
}

