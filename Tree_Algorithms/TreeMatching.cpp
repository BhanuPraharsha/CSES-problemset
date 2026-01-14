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


void dfs(int u, int parent, vector<vector<int>> &adjlst, vector<bool> &vstd, int &ans)
{
    for(int j=0;j<adjlst[u].size();j++)
    {
        if(adjlst[u][j]==parent) continue;
        dfs(adjlst[u][j], u, adjlst, vstd, ans);
        if(!vstd[u] && !vstd[adjlst[u][j]])
        {
            vstd[u]=true;
            vstd[adjlst[u][j]]=true;
            ans++;
        }
    }

}

// main code

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, ans=0; cin>>n;
    vector<vector<int>> adjlst(n+1);
    vector<bool> vstd(n+1, false);
    for(int j=2;j<=n;j++)
    {
        int u,v;
        cin>>u>>v;
        adjlst[u].push_back(v);
        adjlst[v].push_back(u);
    }

    dfs(1, 0, adjlst, vstd, ans);
    cout<<ans<<endl;


    return 0;
}