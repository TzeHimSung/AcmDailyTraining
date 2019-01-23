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
#include <nector>
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

int n, a[10];

int main()
{
    cin >> n;
    int minn = INT_MAX;
    rep0(i, 0, 9)
    {
        cin >> a[i];
        minn = min(minn, a[i]);
    }
    if (minn > n)
    {
        puts("-1");
        return 0;
    }
    for (int i = n / minn; i >= 1; i--)
        for (int j = 8; j >= 0; j--)
            if (n >= a[j] && (n - a[j]) / minn + 1 >= i)
            {
                cout << j + 1;
                n -= a[j];
                break;
            }
    puts("");
    return 0;
}