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



    int mex(const vector<int>& a) {
    unordered_set<int> s(a.begin(), a.end());
    int m = 0;
    while (s.count(m)) {
        m++;
    }
    return m;
}



    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int t=1;
        // cin>>t;
        while(t--)
        {
            int n,m; cin>>n>>m;
            vector<vector<pair<int, int>>> adj(2*n + 1);
            for(int j=0;j<m;j++)
            {
                int u,v,c;
                cin>>u>>v>>c;
                adj[u].push_back({v, c}), adj[u+n].push_back({v+n, c}), adj[u].push_back({v+n, c/2});
            }

            int src=1;
            vector<long long int> dist(2*n + 1, LLONG_MAX);
            dist[src]=0LL;
            priority_queue<pair<long long int,int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> pq;
            pq.push({0, src});
            while(!pq.empty())
            {
                int curr=pq.top().second;
                int cost=pq.top().first;
                pq.pop();
                if(cost>dist[curr]) continue;

                for(int j=0;j<adj[curr].size();j++)
                {
                    if(dist[adj[curr][j].first]> dist[curr]+adj[curr][j].second)
                    {
                        dist[adj[curr][j].first]=dist[curr]+adj[curr][j].second;
                        pq.push({dist[adj[curr][j].first], adj[curr][j].first});
                    }
                }
            }

            // dbg(dist);
            cout<<min(dist[n], dist[2*n])<<endl;
        }
        return 0;
    }