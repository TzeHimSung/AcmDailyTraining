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

const int maxn = 1e5 + 10;
ll a[maxn];

void init()
{
    rep0(i, 1, 1e5)
    a[i] = (ll)i * (ll)(i - 1) / 2;
}

int main()
{
    init();
    int t; cin >> t;
    while (t--)
    {
        ll n; cin >> n;
        int flag = 0;
        rep0(i, 2, 100000)
        {
            if (a[i] < n && (n - a[i]) % (ll)i == 0)
            {
                cout << n << " = ";
                int pos = (n - a[i]) / (ll)i;
                rep0(j, 0, i)
                {
                    if (j) cout << " + ";
                    cout << pos + (ll)j;
                }
                flag = 1;
                break;
            }
        }
        if (!flag) cout << "IMPOSSIBLE" << endl;
        else cout << endl;
    }
    return 0;
}