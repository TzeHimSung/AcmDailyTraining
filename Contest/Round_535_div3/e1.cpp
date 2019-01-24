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

const int maxn = 3e2 + 10;
int n, m, a[maxn], b[maxn], f[maxn], num[maxn], ans[maxn];
pair<int, int>seg[maxn];

int main()
{
    cin >> n >> m;
    rep1(i, 1, n) cin >> a[i];
    rep1(i, 1, m) cin >> seg[i].fir >> seg[i].sec;
    int pos = 1;
    //enum all position
    rep1(i, 1, n)
    {
        memset(f, 0, sizeof(f));
        //enum all segments
        rep1(j, 1, m)
        {
            if (seg[j].fir <= i && i <= seg[j].sec)
            {
                f[seg[j].fir]--;
                f[seg[j].sec + 1]++;
                num[i]++;
            }
        }
        int maxx = INT_MIN, minn = INT_MAX;
        rep1(j, 1, n)
        {
            f[j] += f[j - 1];
            b[j] = f[j] + a[j];
            maxx = max(maxx, b[j]);
            minn = min(minn, b[j]);
        }
        ans[i] = maxx - minn;
        if (ans[i] > ans[pos]) pos = i;
    }
    cout << ans[pos] << endl << num[pos] << endl;
    rep1(i, 1, m)
    if (seg[i].fir <= pos && pos <= seg[i].sec)
        cout << i << " ";
    return 0;
}