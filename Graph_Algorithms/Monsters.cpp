#include <bits/stdc++.h>
using namespace std;
// main code
vector<string> grid;
vector<vector<int>> mdist;
vector<vector<int>> adist;
vector<vector<char>> par;
vector<vector<pair<int,int>>> parPos;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char dirs[4] = {'D', 'U', 'R', 'L'};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n,m,sx,sy;
    string ans="";
    cin>>n>>m;
    mdist.assign(n, vector<int> (m, INT_MAX));
    adist.assign(n, vector<int> (m, INT_MAX));
    grid.resize(n);
    par.resize(n, vector<char>(m, 'O'));
    parPos.resize(n, vector<pair<int, int>> (m));
    queue<pair<int, int>> q;
    for(int j=0;j<n;j++)
    {
        cin>>grid[j];
        for(int k=0;k<m;k++)
        {
            if(grid[j][k]=='A')
            {
                sx=j, sy=k;
            }
            else if(grid[j][k]=='M')
            {
                q.push({j,k});
                mdist[j][k]=0;
            }
        }
    }

    while(!q.empty())
    {
        int cx=q.front().first, cy=q.front().second;
        q.pop();
        for(int j=0;j<4;j++)
        {
            int nx=cx+dx[j], ny=cy+dy[j];
            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]!='#' && mdist[nx][ny]==INT_MAX)
            {
                mdist[nx][ny]=mdist[cx][cy]+1;
                q.push({nx, ny});
            }
        }
    }
    //
    q.push({sx,sy});
    parPos[sx][sy]={-1,-1};
    adist[sx][sy]=0;

    while(!q.empty())
    {
        int u=q.front().first, v=q.front().second;
        q.pop();
        if(u==n-1 || v==m-1 || u==0 || v==0)
        {
            cout<<"YES"<<endl;
            int ex=u, ey=v;
            while(ex!=sx || ey!=sy)
            {
                ans+=par[ex][ey];
                int temp=ex;
                ex=parPos[ex][ey].first, ey=parPos[temp][ey].second;
            }
            reverse(ans.begin(), ans.end());
            cout<<ans.length()<<endl;
            cout<<ans<<endl;
            return 0;
        }
        for(int j=0;j<4;j++)
        {
            int nx=u+dx[j], ny=v+dy[j];
            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]!='#' && adist[nx][ny]==INT_MAX)
            {
                if(adist[u][v]+1<mdist[nx][ny])
                {
                    adist[nx][ny]=adist[u][v]+1;
                    par[nx][ny]=dirs[j];
                    parPos[nx][ny]={u,v};
                    q.push({nx, ny});
                }
            }
        }
    }

    cout<<"NO"<<endl;
    return 0;
}