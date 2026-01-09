#include <bits/stdc++.h>
using namespace std;
// main code

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<long long>> dist(n, vector<long long int> (n, LLONG_MAX));
    for(int j=0;j<n;j++) dist[j][j]=0;
    for (int j = 0; j < m; j++)
    {
        long long int a,b,c;
        cin>>a>>b>>c;
        a--, b--;
        dist[a][b]=min(dist[a][b], c);
        dist[b][a]=min(dist[b][a], c);
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (dist[i][k] == LLONG_MAX) continue;
            for (int j = 0; j < n; j++) {
                if (dist[k][j] == LLONG_MAX) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }



    for (int i = 1; i <= q; i++) {
        int a,b;
        cin>>a>>b;
        a--, b--;
        cout<<((dist[a][b]==LLONG_MAX)?-1:dist[a][b])<<endl;
    }
    return 0;
}