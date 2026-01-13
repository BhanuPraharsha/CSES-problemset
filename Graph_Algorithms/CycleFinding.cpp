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



struct edge{
    int u;
    int v;
    int w;
};


    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int t=1;
        // cin>>t;
        while(t--)
        {
            int n,m; cin>>n>>m;
            vector<edge> e(m);
            vector<long long int> dist(n+1, 0), parent(n+1, -1);


            for(int j=0;j<m;j++)
            {
                int a,b,d;
                cin>>a>>b>>d;
                e[j].u=a, e[j].v=b, e[j].w=d;
            }
            
            int neg=-1;

            for(int j=0;j<n;j++)
            {
                neg=-1;
                for(int k=0;k<m;k++)
                {
                    if(dist[e[k].v]>dist[e[k].u] + e[k].w)
                    {
                        dist[e[k].v]=dist[e[k].u] + e[k].w;
                        parent[e[k].v]=e[k].u;
                        neg=e[k].v;
                    }
                }
            }

            if(neg==-1)
            {
                cout<<"NO"<<endl;
                continue;
            }


            cout<<"YES"<<endl;

            for(int j=0;j<n;j++)
            {
                neg=parent[neg];
            }
            vector<int> ans;
            int curr=neg;
            
            while(true)
            {
                ans.push_back(curr);
                curr=parent[curr];
                if(curr==neg)
                {
                    ans.push_back(neg);
                    break;
                }
            }

            reverse(ans.begin(), ans.end());

            for(int j=0;j<ans.size();j++)
            {
                cout<<ans[j]<<" ";
            }
            cout<<endl;
        }
        return 0;
    }