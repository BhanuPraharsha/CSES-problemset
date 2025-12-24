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

    int n,m, sx,sy,ex,ey;
    string ans="";
    cin>>n>>m;
    vector<vector<char>> grid(n, vector<char>(m, '!'));
    vector<vector<char>> trk(n, vector<char>(m, 'O'));
    vector<vector<int>> dist(n, vector<int>(m, 0));
    vector<vector<bool>> vstd(n, vector<bool>(m, false));
    for(int j=0;j<n;j++)
    {
        for(int k=0;k<m;k++)
        {
            cin>>grid[j][k];
            if(grid[j][k]=='A')
            {
                sx=j, sy=k;
            }
            if(grid[j][k]=='B')
            {
                ex=j, ey=k;
            }
        }
    }


    queue<pair<int, int>> q;
    q.push({sx,sy});
    vstd[sx][sy]=true;
    dist[sx][sy]=0;

    while(!q.empty())
    {
        int u=q.front().first, v=q.front().second;
        q.pop();
        if(u==ex && v==ey) break;


        if(u+1<n && grid[u+1][v]!='#' && !vstd[u+1][v]) q.push({u+1, v}), vstd[u+1][v]=true, dist[u+1][v]=dist[u][v]+1, trk[u+1][v]='D';
        if(u-1>=0 && grid[u-1][v]!='#' && !vstd[u-1][v]) q.push({u-1, v}), vstd[u-1][v]=true, dist[u-1][v]=dist[u][v]+1, trk[u-1][v]='U';
        if(v+1<m && grid[u][v+1]!='#' && !vstd[u][v+1]) q.push({u, v+1}), vstd[u][v+1]=true, dist[u][v+1]=dist[u][v]+1, trk[u][v+1]='R';
        if(v-1>=0 && grid[u][v-1]!='#' && !vstd[u][v-1]) q.push({u, v-1}), vstd[u][v-1]=true, dist[u][v-1]=dist[u][v]+1, trk[u][v-1]='L';
    }

    if(!vstd[ex][ey]) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        cout<<dist[ex][ey]<<endl;
        int cx=ex, cy=ey;
        while(cx!=sx || cy!=sy)
        {
            char dir=trk[cx][cy];
            ans+=dir;
            if(trk[cx][cy]=='R') cy--;
            else if(trk[cx][cy]=='L') cy++;
            else if(trk[cx][cy]=='U') cx++;
            else if(trk[cx][cy]=='D') cx--;
        }
    }

    reverse(ans.begin(), ans.end());    
    cout<<ans<<endl;

    return 0;
}