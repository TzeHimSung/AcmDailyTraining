#include<bits/stdc++.h>
using namespace std;
int a[100005];
int vis[100005];
struct node
{
    int a, b;
} c[100005];
int cmp(node x, node y)
{
    return x.b < y.b;
}
int main()
{
    int n, k, cnt;
    long long ans;
    scanf("%d%d", &n, &k);
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &c[i].a);
        vis[c[i].a]++;
    }
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &c[i].b);
    }
    sort(c + 1, c + n + 1, cmp);
    cnt = 0, ans = 0;
    for(int i = 1; i <= k; i++)
    {
        if(vis[i] == 0)
            cnt++;
    }
    for(int i = 1; i <= n; i++)
    {
        if(vis[c[i].a] == 1)
            continue;
        if(cnt == 0)
            break;
        vis[c[i].a]--;
        cnt--;
        ans += c[i].b;
    }
    printf("%lld\n", ans);
}
