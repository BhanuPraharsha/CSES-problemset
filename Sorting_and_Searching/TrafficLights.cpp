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
            int x,n,temp; cin>>x>>n;
            set<int> s;
            set<pair<int, int>> highest;
            s.insert(0), s.insert(x);
            highest.insert({x, 0});


            for(int j=0;j<n;j++)
            {
                cin>>temp;
                auto it =s.upper_bound(temp);
                int ul=*it;
                it=s.lower_bound(temp);
                it--;
                int ll=*it;

                s.insert(temp);
                highest.erase({ul-ll, ll});
                highest.insert({temp-ll, ll});
                highest.insert({ul-temp, temp});
                cout<<(highest.rbegin())->first<<" ";
            }

        }
        return 0;
    }