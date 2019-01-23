#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <string>
#include <map>
using namespace std;
const int maxn = 500 + 10;
int vis[maxn][maxn][2];
int is[maxn][maxn];
int has[maxn][maxn];
map<string, int>mapa;
int id = 1;
int  add(string a)
{
    if(mapa.count(a)) return mapa[a];
    mapa[a] = id++;
    //  cout<<mapa[a]<<endl;
}
void bfs(int st)
{
    vis[st][st][0] = 1;
    queue< pair<int, int> >q;
    q.push({st, 0});
    while(!q.empty())
    {
        pair<int, int> tmp;
        tmp = q.front();
        //  cout<<tmp.first<<" "<<tmp.second<<endl;
        q.pop();
        for(int i = 1; i < id; i++)
        {
            if(is[tmp.first][i] && !vis[st][i][tmp.second])
            {
                vis[st][i][tmp.second] = 1;
                q.push({i, tmp.second});
            }
            if(has[tmp.first][i] && !vis[st][i][1])
            {
                vis[st][i][1] = 1;
                q.push({i, 1});
            }
        }
    }
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    memset(vis, 0, sizeof vis);
    memset(is, 0, sizeof is);
    memset(has, 0, sizeof has);
    for(int i = 0; i < n; i++)
    {
        string a, b, c;
        cin >> a >> b >> c;
        add(a), add(c);
        // cout<<b[0]<<endl;
        if(b[0] == 'i')
        {
            is[add(a)][add(c)] = 1;
            // vis[mapa[a]][mapa[c]][0] = 1;
        }
        else
        {
            // cout<<"ok"<<endl;
            has[add(a)][add(c)] = 1;
            //  vis[mapa[a]][mapa[c]][1] = 1;
        }
    }
    for(int i = 1; i < id; i++) bfs(i);
    for(int i = 1; i <= m; i++)
    {
        string a, b, c;
        cin >> a >> b >> c;
        //   cout<<b[0]<<endl;
        add(a), add(c);
        printf("Query %d: ", i);
        if(b[0] == 'i')
        {
            if(vis[add(a)][add(c)][0])
                puts("true");
            else
                puts("false");
        }
        else
        {
            if(vis[add(a)][add(c)][1])
                puts("true");
            else
                puts("false");
        }
    }
}