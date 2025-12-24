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
 
//	int t;
//	cin>>t;
 
	for(int i=0;i<1;i++)
	{
		int n,m, k;
		cin>>n>>m>>k;
		vector<int> b(m), a(n);
		
		
		for(int j=0;j<n;j++)
		{
			cin>>a[j];
		}
		
		for(int j=0;j<m;j++)
		{
			cin>>b[j];
		}
		
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		
		
		int currper=0;
		int currhouse=0;
		int count=0;
		
		while(currper<n && currhouse<m )
		{
			if((b[currhouse]<= a[currper] + k)&& (b[currhouse]>= a[currper] - k))
			{
				count++;
				currhouse++;
				currper++;
			}
			else if(b[currhouse] > a[currper] + k)
			{
				currper++;
			}
			else if(b[currhouse]< a[currper] - k)
			{
				currhouse++;
			}
		}
		
		
		cout<<count<<endl;
		
 
		
 
	}
	return 0;
}
 

