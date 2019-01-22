#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 2e5 + 10;
int to[maxn], nxt[maxn], fa[maxn], vis[maxn], dis[maxn];
int n, m, u, v, bg, ed, tot = 1, cnt = 1, flag = 0;
queue<int> q;
void add(int u, int v)
{
    to[tot] = v;
    nxt[tot] = fa[u];
    fa[u] = tot++;
}
void bfs(int s, int e)
{
    vis[s] = cnt++;
    vis[e] = cnt++;
    q.push(s); q.push(e);
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int i = fa[now]; i; i = nxt[i])
        {
            if(!vis[to[i]])
            {
                vis[to[i]] = cnt++;
                q.push(to[i]);
            }
        }
    }
}
void print()
{
    printf("%d", vis[1]);
    for(int i = 2; i <= n; i++) printf(" %d", vis[i]);
    puts("");
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        add(u, v); add(v, u);
        dis[u]++; dis[v]++;
    }
    for(int i = 1; i <= n; i++)
    {
        if(dis[i] < n - 1)
        {
            flag = 1;
            bg = i;
            vis[bg] = 1;
            for(int j = fa[i]; j; j = nxt[j])
                vis[to[j]] = 1;
            for(int j = 1 ; j <= n; j++)
                if(!vis[j])
                {
                    ed = j; break;
                }
            break;
        }
    }
    if(!flag)
    {
        puts("NO");
        return 0;
    }
    memset(vis, 0, sizeof vis);
    bfs(bg, ed);
    for(int i = 1; i <= n; i++)
        if(!vis[i])
        {
            vis[i] = cnt++;
            q.push(i);
            while(!q.empty())
            {
                int now = q.front();
                q.pop();
                for(int i = fa[now]; i; i = nxt[i])
                {
                    if(!vis[to[i]])
                    {
                        vis[to[i]] = cnt++;
                        q.push(to[i]);
                    }
                }
            }
        }
    puts("YES");
    print();
    vis[ed] = 1;
    print();
}