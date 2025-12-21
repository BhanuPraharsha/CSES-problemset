#include<bits/stdc++.h>
using namespace std;
 
#define LOCAL // comment out to disable debugging
 
#ifdef LOCAL
#define dbg(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 0
#endif
 
// Base template to print any type
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) {
    os << "[";
    for(size_t i = 0; i < v.size(); i++) {
        os << v[i]; if(i != v.size()-1) os << ", ";
    }
    return os << "]";
}
template<typename T> ostream& operator<<(ostream &os, const set<T> &s) {
    os << "{";
    size_t i=0; for(auto &x:s){ os << x; if(i!=s.size()-1) os << ", "; i++; }
    return os << "}";
}
template<typename K, typename V> ostream& operator<<(ostream &os, const map<K,V> &m) {
    os << "{";
    size_t i=0;
    // FIXED: C++11 compatible loop
    for(const auto &pair : m){
        os << "(" << pair.first << ":" << pair.second << ")";
        if(i != m.size()-1) os << ", ";
        i++;
    }
    return os << "}";
}
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A,B> &p) {
    return os << "(" << p.first << "," << p.second << ")";
}
 
// Multi-arg debug
template<typename T>
void debug_out(const char* name, T&& arg) { cerr << name << " = " << arg << "\n"; }
 
template<typename T, typename... Args>
void debug_out(const char* names, T&& arg, Args&&... args) {
    const char* comma = strchr(names, ',');
    cerr.write(names, comma - names) << " = " << arg << " | ";
    debug_out(comma+1, args...);
}
 
 
struct Timer {
    chrono::time_point<chrono::steady_clock> start;
    Timer() { start = chrono::steady_clock::now(); }
    void print() {
        auto end = chrono::steady_clock::now();
        cerr << "[Time elapsed: "
             << chrono::duration_cast<chrono::milliseconds>(end-start).count()
             << " ms]\n";
    }
};
 
 
 
 
 
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
	//Timer t; // optional, for timing execution t.print();
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
	int t;
//	cin>>t;
 
	for(int i=0;i<1;i++)
	{
		int n,q;
		cin>>n>>q;
		vector<int> a(n);
		vector<long long int> ps(n+1, 0);
		for(int j=0;j<n;j++) cin>>a[j];
		for(int j=0;j<n;j++) ps[j+1]=ps[j]+a[j];
		
		
		for(int j=0;j<q;j++)
		{
			int a,b;
			cin>>a>>b;
			
			cout<<ps[b]-ps[a-1]<<endl;
		}
				
	}
 
	return 0;
}

