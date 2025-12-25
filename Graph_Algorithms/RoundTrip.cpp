#include <bits/stdc++.h>
using namespace std;

// main code

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> vstd(n+1, 0);
    vector<int> par(n+1, -1);
    for (int j = 0; j < m; j++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int j=1;j<=n;j++)
    {
        
        if(vstd[j]==0)
        {
            queue<int> q;
            q.push(j);
            vstd[j]=1;
            while(!q.empty())
            {
                int curr=q.front();
                q.pop();
                for(int k=0;k<adj[curr].size();k++)
                {
                    if(!vstd[adj[curr][k]])
                    {
                        vstd[adj[curr][k]]=1;
                        par[adj[curr][k]]=curr;
                        q.push(adj[curr][k]);
                        continue;
                    }
                    if(vstd[adj[curr][k]] && par[curr] != adj[curr][k])
                    {
                        vector<int> p1, p2;
                        for (int v = curr; v != -1; v = par[v]) p1.push_back(v);
                        for (int v = adj[curr][k]; v != -1; v = par[v]) p2.push_back(v);
                        int u=p1.size()-1, v=p2.size()-1;
                        while(u>=0 && v>=0 && p1[u]==p2[v]) u--, v--;
                        u++, v++;
                        cout<<u+2+v<<endl;
                        for(int l=0;l<=u;l++) cout<<p1[l]<<" ";
                        for(int l=v-1;l>=0;l--) cout<<p2[l]<<" ";
                        cout<<p1[0]<<endl;
                        return 0;
                    }
                }
            }
        }
    }


    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}