#include <bits/stdc++.h>
using namespace std;
// main code

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
     vector<vector<pair<long long, long long>>> adj(n + 1);
     vector<long long> dist(n+1, LLONG_MAX);
    // vector<int> vstd(n+1, 0);
    // vector<int> par(n+1, -1);
    for (int j = 0; j < m; j++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b, c});
    }

    priority_queue<pair<long long,long long>, vector<pair<long long ,long long>>, greater<>> pq;
    dist[1] = 0;
    pq.push({0, 1});

    while(!pq.empty())
    {
        int d=pq.top().first, u=pq.top().second;
        pq.pop();
        if (d > dist[u]) continue; 
        for(int j=0;j<adj[u].size();j++)
        {
            if(dist[adj[u][j].first]>dist[u]+adj[u][j].second)
            {
                dist[adj[u][j].first]=dist[u]+adj[u][j].second;
                pq.push({dist[adj[u][j].first], adj[u][j].first});
            }
        }
    }


    for (int i = 1; i <= n; i++) {
        if (dist[i] == LLONG_MAX) cout << "INF ";
        else cout << dist[i] << " ";
    }
    cout << '\n';
    return 0;
}