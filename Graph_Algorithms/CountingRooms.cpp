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
 
    // int t;
    // cin >> t;
 
    int n,m,ans=0;
    cin>>n>>m;
    vector<vector<char>> grid(n, vector<char>(m, '!'));
    vector<vector<bool>> vstd(n, vector<bool>(m, false));
    for(int j=0;j<n;j++)
    {
        for(int k=0;k<m;k++) cin>>grid[j][k];
    }
 
    for(int j=0;j<n;j++)
    {
        for(int k=0;k<m;k++)
        {
            if(!vstd[j][k] && grid[j][k]=='.')
            {
                // dbg(j,k);
                queue<pair<int, int>> q;
                q.push({j,k});
                ans++;
                vstd[j][k]=true;
 
                while(!q.empty())
                {
                    int u=q.front().first, v=q.front().second;
                    q.pop();
                    vstd[u][v]=true;
                    if(u+1<n && grid[u+1][v]=='.' && !vstd[u+1][v]) q.push({u+1, v}), vstd[u+1][v]=true;
                    if(u-1>=0 && grid[u-1][v]=='.' && !vstd[u-1][v]) q.push({u-1, v}), vstd[u-1][v]=true;
                    if(v+1<m && grid[u][v+1]=='.' && !vstd[u][v+1]) q.push({u, v+1}), vstd[u][v+1]=true;
                    if(v-1>=0 && grid[u][v-1]=='.' && !vstd[u][v-1]) q.push({u, v-1}), vstd[u][v-1]=true;
                }
            }
        }
    }
 
    cout<<ans<<endl;
 
    return 0;
}