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
/* define */
#define int int32_t
#define ll int64_t
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
#define inf 0x3f3f3f3f
#define lson curr<<1
#define rson curr<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e3 + 10;
int speed[23];
char _mp[maxn][maxn];
vector<pair<int, int>>g[25][2];
int own[25], lastPos[25], dead[25], n, m, p;
int px[] = {0, 0, -1, 1}, py[] = {1, -1, 0, 0};
queue<pair<pair<int, int>, int> >q;

void solve(int point)
{
    if (g[point][lastPos[point]].size() == 0) return;
    g[point][lastPos[point] ^ 1].clear();
    for (auto x : g[point][lastPos[point]])
        q.push(mp(x, speed[point]));
    while (!q.empty())
    {
        int curx = q.front().first.first, cury = q.front().first.second;
        int curSpeed = q.front().second;
        q.pop();
        if (!curSpeed) continue;
        rep0(k, 0, 4)
        {
            int nx = curx + px[k], ny = cury + py[k];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (_mp[nx][ny] != '.') continue;
            _mp[nx][ny] = '#';
            g[point][lastPos[point] ^ 1].pb(mp(nx, ny));
            q.push(mp(mp(nx, ny), curSpeed - 1));
        }
    }
    own[point] += g[point][lastPos[point] ^ 1].size();
    lastPos[point] ^= 1;
}

int main()
{
    scanf("%d%d%d", &n, &m, &p);
    rep1(i, 1, p) cin >> speed[i];
    //init graph
    rep1(i, 1, n)
    {
        scanf("%s", _mp[i] + 1);
        rep1(j, 1, m)
        //if find born point
        if (_mp[i][j] != '.' && _mp[i][j] != '#')
        {
            g[_mp[i][j] - '0'][0].pb(mp(i, j)); //g[player_num][0] saves the born point
            own[_mp[i][j] - '0']++;
        }
    }
    int remain = p, point = 1;
    while (remain)
    {
        solve(point);
        if (g[point][lastPos[point]].size() == 0 && !dead[point])
            dead[point] = 1, remain--;
        point = point % p + 1;
    }
    rep1(i, 1, p) printf("%d ", own[i]);
    return 0;
}