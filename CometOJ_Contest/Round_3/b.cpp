/* basic header */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdint>
#include <climits>
#include <float.h>
/* STL */
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <array>
#include <iterator>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define fir first
#define sec second
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;++i)
#define rep0(i,a,b) for(int i=a;i<b;++i)
#define repa(i,a) for(auto &i:a)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e5 + 10;
const int px[] = {0, -1, 0, 1, 0};
const int py[] = {0, 0, -1, 0, 1};
int a[2][maxn], n, vis[2][maxn];
int cnt = 0;
pair<int, int>lm, rm;
struct Block
{
    pair<int, int>lm, rm;
    Block() {}
    Block(pair<int, int>a, pair<int, int>b): lm(a), rm(b) {}
};
vector<Block>v;

int check(int x, int y)
{
    if (x >= 0 && x <= 1 && y >= 1 && y <= n && !vis[x][y]) return 1;
    return 0;
}

void dfs(int x, int y)
{
    vis[x][y] = 1;
    if (y < lm.second) lm = {x, y};
    if (y > rm.second) rm = {x, y};
    for (int i = 1; i <= 4; i++)
    {
        int nx = x + px[i], ny = y + py[i];
        if (check(nx, ny)) dfs(nx, ny);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i <= 1; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]), vis[i][j] = (a[i][j]) ? 0 : 1;
    for (int j = 1; j <= n; j++)
    {
        for (int i = 0; i <= 1; i++)
            if (!vis[i][j])
            {
                cnt++; lm = {i, j}; rm = {i, j};
                dfs(i, j);
                v.push_back(Block(lm, rm));
            }
    }
    if (cnt == 1) return puts("0"), 0;
    ll ans = 0;
    for (int i = 0; i < cnt - 1; i++)
    {
        ans += abs(v[i + 1].lm.first - v[i].rm.first) + abs(v[i + 1].lm.second - v[i].rm.second) - 1;
        if (i + 2 < cnt)
        {
            if (v[i + 2].lm.second - v[i].rm.second == 2) ans--;
        }
    }
    printf("%lld\n", ans);
    return 0;
}