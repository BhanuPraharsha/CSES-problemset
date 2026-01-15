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
long long int dfs(int curr, int parent, vector<vector<int>> &adjlst, vector<long long int> &subtreeCount)
{
    long long int distSum=0;
    subtreeCount[curr]=1;
    for(int j=0;j<adjlst[curr].size();j++)
    {
        if(adjlst[curr][j]==parent) continue;
        distSum+=dfs(adjlst[curr][j], curr, adjlst, subtreeCount);
        subtreeCount[curr]+=subtreeCount[adjlst[curr][j]];
    }

    distSum+=subtreeCount[curr]-1;
    return distSum;
}

void getans(vector<long long int> &ans, vector<vector<int>> &adjlst, int curr, int parent, vector<long long int> &subtreeCount)
{
    long long int n=adjlst.size()-1;
    for(int j=0;j<adjlst[curr].size();j++)
    {
        if(adjlst[curr][j]==parent) continue;
        ans[adjlst[curr][j]]=ans[curr]-subtreeCount[adjlst[curr][j]]+(n-subtreeCount[adjlst[curr][j]]);
        getans(ans, adjlst, adjlst[curr][j], curr, subtreeCount);
    }

    return;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<vector<int>> adjlst(n+1);
    for(int j=0;j<n-1;j++)
    {
        int a,b; cin>>a>>b;
        adjlst[a].push_back(b), adjlst[b].push_back(a);
    }
    vector<long long int> ans(n+1, 0), subtreeCount(n+1, 0);
    ans[1]=dfs(1, 0, adjlst, subtreeCount);
    getans(ans, adjlst, 1, 0, subtreeCount);

    for(int j=1;j<=n;j++) cout<<ans[j]<<" ";
    cout<<endl;
    return 0;
}