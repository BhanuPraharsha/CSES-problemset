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
		int n;
		cin>>n;
		vector<int> a(n);
		
		for(int j=0;j<n;j++)
		{
			cin>>a[j];
		}
		
		sort(a.begin(), a.end());
		
		int mid=((n%2)==0)?(n-2)/2 : n/2;
		
		
		long long int ans=0,temp=0;
		
		for(int j=0;j<n;j++)
		{
			ans+=(long long int)abs(a[j]-a[mid]);
		}
		
		if((n%2)==0)
		{
			for(int j=0;j<n;j++)
		{
			temp+=(long long int)abs(a[j]-a[mid+1]);
		}
				ans=min(ans, temp);
 
		
		}
		
		
		
		
		
		cout<<ans<<endl;
	}
 
	return 0;
}
 

