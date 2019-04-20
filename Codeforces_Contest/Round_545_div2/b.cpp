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

int n, cnt, t0, t1, t2;

int main()
{
    cin >> n;
    cnt = t0 = t1 = t2 = 0;
    vector<char>c(n), a(n);
    vector<int>s(n);
    rep0(i, 0, n) cin >> c[i];
    rep0(i, 0, n)
    {
        cin >> a[i];
        s[i] = a[i] - '0' + c[i] - '0';
        if (!s[i]) t0++;
        else if (s[i] == 1) t1++;
        else if (s[i] == 2) t2++;
        if (a[i] == '1') cnt++;
    }
    int k = n / 2, ans0, ans1, ans2, sign = 0;
    rep1(i, 0, k)
    {
        rep1(j, 0, k - i)
        {
            int x0 = min(t0, i), x1 = min(t1, j), x2 = k - x0 - x1;
            if (x2 <= t2 && x1 * 1 + x2 * 2 == cnt)
            {
                sign = 1;
                ans0 = x0, ans1 = x1, ans2 = x2;
                break;
            }
        }
        if (sign) break;
    }
    if (!sign)
    {
        puts("-1");
        return 0;
    }

    rep0(i, 0, n)
    {
        if (!ans0) break;
        if (!s[i])
        {
            cout << i + 1 << " ";
            ans0--;
        }
    }
    rep0(i, 0, n)
    {
        if (!ans1) break;
        if (s[i] == 1)
        {
            cout << i + 1 << " ";
            ans1--;
        }
    }
    rep0(i, 0, n)
    {
        if (!ans2) break;
        if (s[i] == 2)
        {
            cout << i + 1 << " ";
            ans2--;
        }
    }
    puts("");
    return 0;
}