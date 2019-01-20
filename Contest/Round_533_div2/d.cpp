/* basic header */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <climits>
#include <cmath>
#include <cstdint>
/* STL */
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <array>
#include <iterator>
using namespace std;

inline int read()
{
    int x = 0, ch = getchar(); bool fg = 1;
    while(ch < '0' || ch > '9')
    {
        if(ch == '-') fg = 0;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return fg ? x : -x;
}

const int maxn = 1e3 + 10;
int s[23];
char mp[maxn][maxn];
typedef pair<int, int> P;
vector<P> g[25][2];
int cnt[25];
int per[25];
bool de[25];
int n, m, p;
queue<pair<P, int> > q;
int xt[] = {0, 0, -1, 1};
int yt[] = {1, -1, 0, 0};

void solve(int pt)
{
    if(g[pt][per[pt]].size() == 0) return;
    g[pt][per[pt] ^ 1].clear();
    for(auto x : g[pt][per[pt]]) q.push(make_pair(x, s[pt]) );
    while(!q.empty())
    {
        int x = q.front().first.first, y = q.front().first.second;
        int d = q.front().second;
        q.pop();
        if(d == 0) continue;
        for(int k = 0; k < 4; k++)
        {
            int xx = x + xt[k];
            int yy = y + yt[k];
            if(xx < 1 || xx > n || yy < 1 || y > m) continue;
            if(mp[xx][yy] != '.') continue;
            mp[xx][yy] = '#';
            g[pt][per[pt] ^ 1].push_back(P(xx, yy));
            q.push(make_pair(P(xx, yy), d - 1) );
        }
    }
    cnt[pt] += g[pt][per[pt] ^ 1].size();
    per[pt] ^= 1;
}

int main()
{
    n = read(), m = read(), p = read();
    for(int i = 1; i <= p; i++) s[i] = read();
    for(int i = 1; i <= n; i++)
    {
        scanf("%s", mp[i] + 1);
        for(int j = 1; j <= m; j++)
        {
            if(mp[i][j] != '.' && mp[i][j] != '#')
            {
                g[mp[i][j] - '0'][0].push_back(P(i, j));
                cnt[mp[i][j] - '0']++;
            }
        }
    }
    int re = p, pt = 1;
    while(re)
    {
        solve(pt);
        if(g[pt][per[pt]].size() == 0 && !de[pt])
        {
            de[pt] = 1; re--;
        }
        pt = pt % p + 1;
    }
    for(int i = 1; i <= p; i++) printf("%d ", cnt[i]);
    return 0;
}
