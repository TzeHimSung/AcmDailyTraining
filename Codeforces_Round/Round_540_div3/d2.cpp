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

const int maxn = 2e5 + 10;
int a[maxn], n, m, ans = -1;

int check(int x)
{
    int sub = 0, num = 0, sum = 0;
    rep0(i, 0, n)
    {
        num++;
        sum += max(0, a[i] - sub);
        if (sum >= m)
            return 1;
        if (num == x)
        {
            num = 0;
            sub++;
        }
    }
    return 0;
}

int main()
{
    cin >> n >> m;
    rep0(i, 0, n) cin >> a[i];
    sort(a, a + n, greater<int>());
    int l = 1, r = n;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}