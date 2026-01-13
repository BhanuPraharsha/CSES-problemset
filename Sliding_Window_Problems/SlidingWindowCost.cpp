#include <bits/stdc++.h>
using namespace std;

#define LOCAL // comment out

#ifdef LOCAL
#define dbg(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 0
#endif

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

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

// main code

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k; cin>>n>>k;
    vector<int> a(n);
    for(int j=0;j<n;j++) cin>>a[j];
    long long int lsum=0LL, rsum=0LL, lc=0LL, rc=0LL;
    multiset<int> l, r;
    vector<int> temp(k);
    for(int j=0;j<k;j++) temp[j]=a[j];
    sort(temp.begin(), temp.end());
    int med=temp[(k-1)/2];

    for(int j=0;j<k;j++)
    {
        if(a[j]<med)
        {
            l.insert(a[j]);
            lsum+=a[j];
            lc++;
        }
        else{
            r.insert(a[j]);
            rsum+=a[j];
            rc++;
        }
    }

    cout<<(med*lc - lsum) + (rsum-med*rc)<<" ";

    for(int j=0;j<n-k;j++)
    {
        int curr=a[j];
        if(l.find(curr)!=l.end())
        {
            lsum-=curr;
            lc--;
            auto it=l.find(curr);
            l.erase(it);
        }
        else{
            rsum-=curr;
            rc--;
            auto it=r.find(curr);
            r.erase(it);
        }

        curr=a[j+k];
        if(curr<=med)
        {
            lsum+=curr;
            lc++;
            l.insert(curr);
        }
        else{
            rsum+=curr;
            rc++;
            r.insert(curr);
        }


        while(!(lc==rc) && !(lc==rc+1))
        {
            if(lc>rc+1)
            {
                int tt=*l.rbegin();
                auto it=l.find(tt);
                l.erase(it);
                r.insert(tt);
                lc--, rc++;
                lsum-=tt, rsum+=tt;
            }
            else{
                int tt=*r.begin();
                auto it=r.find(tt);
                r.erase(it);
                l.insert(tt);
                lc++, rc--;
                lsum+=tt, rsum-=tt;
            }
        }

        med=*l.rbegin();
        cout<<(med*lc - lsum) + (rsum-med*rc)<<" ";
    }

    return 0;
}