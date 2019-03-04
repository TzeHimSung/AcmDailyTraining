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

const int maxn = 1e2 + 10;
int n, m, k, a[maxn][2], ans = 0, must[maxn];
map<int, int>highest;

int main()
{
    highest.clear();
    cin >> n >> m >> k;
    rep1(i, 1, n) must[i] = 0;
    rep1(i, 1, n) cin >> a[i][0];
    rep1(i, 1, n)
    {
        cin >> a[i][1];
        if (!highest.count(a[i][1])) highest[a[i][1]] = a[i][0];
        else highest[a[i][1]] = max(highest[a[i][1]], a[i][0]);
    }
    rep1(i, 1, k)
    {
        int x; cin >> x;
        if (highest[a[x][1]] != a[x][0]) ans++;
    }
    cout << ans << endl;
    return 0;
}