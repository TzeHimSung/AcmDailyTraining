#include<bits/stdc++.h>
using namespace std;
const int maxn = 2000000;
int pa[maxn];

int find(int x)
{
    if (pa[x] == x) return x;
    else return pa[x] = find(pa[x]);
}
priority_queue<int, vector<int>, greater<int> > Q;
vector<int> G[maxn];
int vis[maxn], visit[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            pa[i] = i;
            vis[i] = 0;
            visit[i] = 0;
            G[i].clear();
        }
        for (int i = 1; i <= m; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            if (a > b) swap(a, b);
            G[a].push_back(b);
            G[b].push_back(a);
            int x = find(a);
            int y = find(b);
            pa[y] = x;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (find(i) == i) ans ++;
        }
        printf("%d\n", ans);
        while (!Q.empty()) Q.pop();
        for (int i = 1; i <= n; i++)
        {
            if (vis[pa[i]] == 0)
            {
                Q.push(i);
                vis[pa[i]] = 1;
                visit[i] = 1;
            }
        }
        int flag = 0;
        while (!Q.empty())
        {
            int x = Q.top();
            Q.pop();
            if (flag == 0)
            {
                printf("%d", x);
                flag = 1;
            }
            else printf(" %d", x);
            for (int i = 0; i < G[x].size(); i++)
            {
                if (!visit[G[x][i]])
                {
                    visit[G[x][i]] = 1;
                    Q.push(G[x][i]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}