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
#define init(a,b) fill(begin(a),end(a),b)
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;i++)
#define rep0(i,a,b) for(int i=a;i<b;i++)
#define repa(i,a) for(auto &i:a)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_int 0x7f7f7f7f7f7f7f7f
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 60;
const int px[] = {0, -1, 0, 1, 0};
const int py[] = {0, 0, 1, 0, -1};
int r1, c1, r2, c2, m[maxn][maxn], vis[maxn][maxn], n, ans = INT_MAX;

int check(int x, int y)
{
    if (!x || !y || x > n || y > n || vis[x][y] || m[x][y] == 1) return 0;
    return 1;
}

void dfs(int x, int y, int t)
{
    if (x == r2 && y == c2 && t == -1)
    {
        puts("0");
        exit(0);
    }
    vis[x][y] = 1; m[x][y] = t;
    rep1(i, 1, 4)
    {
        int nx = x + px[i], ny = y + py[i];
        if (check(nx, ny))
            dfs(nx, ny, t);
    }
}

int main()
{
    cin >> n >> r1 >> c1 >> r2 >> c2;
    rep1(i, 1, n)
    {
        string s; cin >> s;
        rep0(j, 0, n) m[i][j + 1] = s[j] - '0';
    }
    dfs(r1, c1, -1);
    dfs(r2, c2, 2);
    rep1(i, 1, n)
    rep1(j, 1, n)
    {
        if (m[i][j] != -1) continue;
        rep1(p, 1, n)
        rep1(q, 1, n)
        {
            if (m[p][q] != 2) continue;
            ans = min(ans, (p - i) * (p - i) + (q - j) * (q - j));
        }
    }
    cout << ans << endl;
    return 0;
}