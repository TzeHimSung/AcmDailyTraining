/*

sucks code

*/

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
#define dou double
#define pb emplace_back
#define mp make_pair
#define fir first
#define sec second
#define init(a,b) fill(begin(a),end(a),b)
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

struct Node
{
    int wh, num;
    Node() {}

    bool operator<(const Node &rhs) const
    {
        return num < rhs.num;
    }
};

const int maxn = 1e3 + 10;
int n, m, a[maxn][maxn], hh[maxn][maxn], ll[maxn][maxn];
int mh[maxn], ml[maxn];
vector<Node>h[maxn], l[maxn];

int main()
{
    cin >> n >> m;
    rep1(i, 1, n)
    rep1(j, 1, m)
    cin >> a[i][j];
    rep1(i, 1, n)
    {
        Node tmp;
        rep1(j, 1, m)
        {
            tmp.num = a[i][j];
            tmp.wh = j;
            h[i].pb(tmp);
        }
        sort(h[i].begin(), h[i].end());
        int how = 0;
        rep0(j, 0, m)
        {
            if (j)
            {
                if (h[i][j - 1].num == h[i][j].num) how++;
            }
            hh[i][h[i][j].wh] = j + 1 - how;
        }
        mh[i] = m - how;
    }
    rep1(j, 1, m)
    {
        Node tmp;
        rep1(i, 1, n)
        {
            tmp.num = a[i][j];
            tmp.wh = i;
            l[j].pb(tmp);
        }
        sort(l[j].begin(), l[j].end());
        int how = 0;
        rep0(i, 0, n)
        {
            if (i)
                if (l[j][i - 1].num == l[j][i].num) how++;
            ll[l[j][i].wh][j] = i + 1 - how;
        }
        ml[j] = n - how;
    }
    rep1(i, 1, n)
    {
        rep1(j, 1, m)
        {
            int cha;
            if (hh[i][j] == ll[i][j])
            {
                int cha1;
                cha1 = mh[i] - hh[i][j];
                cha = ml[j] - ll[i][j];
                printf("%d ", max(max(hh[i][j] + cha, mh[i]), max(ll[i][j] + cha1, ml[j])));
            }
            else if (hh[i][j] > ll[i][j])
            {
                cha = ml[j] - ll[i][j];
                printf("%d ", max(hh[i][j] + cha, mh[i]));
            }
            else if (hh[i][j] < ll[i][j])
            {
                cha = mh[i] - hh[i][j];
                printf("%d ", max(ll[i][j] + cha, ml[j]));
            }
        }
        puts("");
    }
    return 0;
}