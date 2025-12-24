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
		int n;
		cin>>n;
		
		vector<int> a(n, INT_MIN);
		
		if(n==1)
		{
			cout<<1;
			return 0;
		}
		else if(n<4)
		{
			cout<<"NO SOLUTION";
			return 0;
		}
		else if(n==4)
		{
			cout<<"2 4 1 3";
			return 0;
		}
		
		if(n%2!=0)
		{
			for(int j=0;j<=(n/2);j++)
		{
			a[j]=(2*j) +1;
		}
		
		for(int j=n-1;j>n/2;j--)
		{
			a[j]=2*(n-j);
		}
		
					swap(a[(n/2)+1], a[n-1]);			
 
		}
		
		else{
			for(int j=0;j<(n/2);j++)
		{
			a[j]=(2*j) +1;
		}
		
		for(int j=n-1;j>=n/2;j--)
		{
			a[j]=2*(n-j);
		}
		
		
					swap(a[(n/2)], a[n-1]);			
 
		
		}
		
		
		
		
		
		
		
		for(int j=0;j<n;j++)
		{
			cout<<a[j]<<" ";
		}
		
	}
	return 0;
}
