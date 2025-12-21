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
 
	int t;
	cin>>t;
 
	for(int i=0;i<t;i++)
	{
		long int a, b;
		cin>>a>>b;
		if(a==0 && b==0)
		{
			cout<<"YES"<<endl;
			continue;
		}
		else if(a==0 || b==0)
		{
			cout<<"NO"<<endl;
			continue;
		}
		
		if((2*a -b)%3==0 && (2*b-a)%3==0)
		{
			if((2*a-b)/3 >=0 && (2*b-a)/3 >=0)
			{
				cout<<"YES"<<endl;
				continue;
			}
			else{
				cout<<"NO"<<endl;
				continue;
			}
			
		}
		else{
			cout<<"NO"<<endl;
		}
	}
 
	return 0;
}

