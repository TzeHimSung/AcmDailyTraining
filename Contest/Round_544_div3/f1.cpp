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
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 2e5 + 10;
vector<int>g[maxn];
queue<int>q;
int n, m, deg[maxn], vis[maxn];

int main()
{
    cin >> n >> m;
    rep1(i, 1, m)
    {
        int x, y; cin >> x >> y;
        deg[x]++, deg[y]++;
        g[x].pb(y); g[y].pb(x);
    }
    int pos = 1;
    rep1(i, 2, n) if (deg[i] > deg[pos]) pos = i;
    while (!q.empty()) q.pop();
    q.push(pos), vis[pos] = 1;
    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        rep0(k, 0, deg[i])
        {
            int j = g[i][k];
            if (!vis[j])
            {
                vis[j] = 1;
                q.push(j);
                cout << i << " " << j << endl;
            }
        }
    }
    return 0;
}