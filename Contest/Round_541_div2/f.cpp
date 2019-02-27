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

const int maxn = 1e5 + 5e4 + 10;
int fa[maxn], n;
vector<int>cld[maxn];

int getfa(int x)
{
    int re = x;
    while (fa[x] != x) x = fa[x];
    while (fa[re] != x)
    {
        int tmp = fa[re];
        fa[re] = x;
        re = tmp;
    }
    return x;
}

void solve(int a, int b)
{
    int faa = getfa(a), fab = getfa(b);
    if (faa > fab) swap(faa, fab);
    //renew info
    cld[faa].insert(cld[faa].end(), cld[fab].begin(), cld[fab].end());
    fa[fab] = faa;
}

int main()
{
    cin >> n;
    rep1(i, 1, n) //init
    {
        fa[i] = i;
        cld[i].clear();
        cld[i].pb(i);
    }
    rep1(i, 1, n - 1)
    {
        int x, y; cin >> x >> y;
        solve(x, y);
    }
    //print
    for (auto i : cld[1]) cout << i << " ";
    puts("");
    return 0;
}