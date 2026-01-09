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
            int n,x; cin>>n>>x;
            vector<int> w(n);
            for(int j=0;j<n;j++)
            {
                cin>>w[j];
            }
            int ub=1<<n;

            vector<pair<int, int>> dp(ub, {100, 0});
            //dp[X].first represents the minimum number of lift cycles for transporting the subset X
            // and the second value represents the minimum amount of people leftover in the last lift
    
            //transition:
            //for calculation of dp[x], this state must be arrived after the final guy in X gets on the lift,
            // iterate over the potential final guys(set-bits in the mask) and get the best answer from the previous state(dp[mask^lastPerson])
            // keep track of the minimum lift cycles and then give priority to the case when minimum people are in the last lift(when cycles count matches)
            
            dp[0]={1, 0};

            for(int mask=0;mask<ub;mask++)
            {
                for(int j=0;j<n;j++)
                {
                    if(mask&(1<<j))
                    {
                        pair<int, int> prevbest=dp[mask^(1<<j)];
                        if(prevbest.second + w[j]<=x)
                        {
                            prevbest.second+=w[j];
                        }
                        else{
                            prevbest.first++;
                            prevbest.second=w[j];
                        }

                        dp[mask]=min(dp[mask], prevbest);
                    }
                }
            }

            cout<<dp[ub-1].first<<endl;
            // dbg(dp);
            
        }
        return 0;
    }