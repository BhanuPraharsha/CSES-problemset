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

    int n; cin>>n;
    vector<vector<int>> a;
    for(int j=0;j<n;j++)
    {
        int u,v; cin>>u>>v;
        a.push_back({u, 1, j});
        a.push_back({v, 2, j});
    }

    sort(a.begin(), a.end());
    vector<int> choices(n, 0), freeRooms;
    int countTillNow=0;
    for(int j=0;j<a.size();j++)
    {
        if(a[j][1]==1)
        {
            if(freeRooms.empty())
            {
                countTillNow++;
                freeRooms.push_back(countTillNow);
            }

            choices[a[j][2]]=freeRooms.back();
            freeRooms.pop_back();
        }
        else{
            freeRooms.push_back(choices[a[j][2]]);
        }
    }
    cout<<countTillNow<<endl;
    for(int j=0;j<n;j++)
    {
        cout<<choices[j]<<" ";
    }
    cout<<endl;

    return 0;
}