#include<bits/stdc++.h>
using namespace std;
 
#define LOCAL // comment out to disable debugging
 
#ifdef LOCAL
#define dbg(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 0
#endif
 
// Base template to prlong long intany type
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
//const long long intMAX = 1e9 + 1;
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
//long long intgcd(long long inta, long long intb) { return b ? gcd(b, a % b) : a; }
 
 
template<typename T>
struct SegTree {
    long long int n; vector<T> t; T ID;                  
    function<T(T,T)> F;                        
 
    SegTree(long long int n, T ID, function<T(T,T)> F)
        : n(n), ID(ID), F(F), t(4*n,ID) {}     
 
    // Build from array a[]
    void build(const vector<T> &a, long long int v, long long int l, long long int r){
        if(l==r){ t[v]=a[l]; return; }         
        long long int m=(l+r)/2;
        build(a,v*2,l,m);                      
        build(a,v*2+1,m+1,r);                  
        t[v]=F(t[v*2],t[v*2+1]);               
    }
    void build(const vector<T> &a){ build(a,1,0,n-1); }
 
    // Polong long intupdate: a[i] = val
    void upd(long long int v,long long int l,long long int r,long long int i,T val){
        if(l==r){ t[v]=val; return; }          
        long long int m=(l+r)/2;
        (i<=m ? upd(v*2,l,m,i,val)             
               : upd(v*2+1,m+1,r,i,val));
        t[v]=F(t[v*2],t[v*2+1]);               
    }
    void update(long long int i, T val){ upd(1,0,n-1,i,val); }
 
    // Range query: [L, R]
    T qry(long long int v,long long int l,long long int r,long long int L,long long int R) const {
        if(R<l || r<L) return ID;              
        if(L<=l && r<=R) return t[v];          
        long long int m=(l+r)/2;                         
        return F(qry(v*2,l,m,L,R),
                 qry(v*2+1,m+1,r,L,R));
    }
    T query(long long int L,long long int R) const { return qry(1,0,n-1,L,R); }
};
 
//usage 
 
 
//
//SegTree<int> st_min(
//    n,
//    INT_MAX,        //0 for sum  , INT_MIN for max  // identity for min
//    [](long long inta, long long intb){ return min(a,b); }
//);
//st_min.build(arr);
//cout << st_min.query(l, r) << "\n";
//st_min.update(idx, newValue);
 
 
//main code
 
int main()
{
	//Timer t; // optional, for timing execution t.print();
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
	long long int t;
//	cin>>t;
 
	for(long long int i=0;i<1;i++)
	{
		long long int n,q;
		cin>>n>>q;
		vector<long long int> a(n);
		for(long long int j=0;j<n;j++) cin>>a[j];
		
		SegTree<long long int> st(n, 0, [](long long int a, long long int b){ return a^b; });
		st.build(a);
		
		
		
		for(long long int j=0;j<q;j++)
		{
			long long int tt,a,b;
//			cin>>tt>>a>>b;
			cin>>a>>b;
			cout<<st.query(--a, --b)<<endl;
//			if(tt==1)
//			{
//				st.update(a-1, b);
//			}
//			else{
//				cout<<st.query(--a, --b)<<endl;
//			}
		}
				
	}
 
	return 0;
}

