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

const int maxn = 5e3 + 10;
vector<int>a[maxn]; //info of sugar
int n, m;

int solve(int p, int q)
{
    if (p == q) return 0;
    else if (q > p) return q - p;
    else return n - p + q;
}

int main()
{
    cin >> n >> m;
    rep1(i, 1, m)
    {
        int x, y; cin >> x >> y;
        a[x].pb(y);
    }
    rep1(i, 1, n)
    {
        int ans = 0;
        rep1(j, 1, n)
        {
            int tmp = -1;
            rep0(k, 0, (int)a[j].size())
            {
                if (tmp == -1)
                    tmp = solve(i, j) + ((int)a[j].size() - 1) * n + solve(j, a[j][k]);
                else
                    tmp = min(tmp, solve(i, j) + ((int)a[j].size() - 1) * n + solve(j, a[j][k]));
            }
            ans = max(ans, tmp);
        }
        cout << ans << " ";
    }
    return 0;
}