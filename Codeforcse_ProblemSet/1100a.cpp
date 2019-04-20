/* basic header */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
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
#define inf 0x3f3f3f3f
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e2 + 10;
int a[maxn], n, k, numOfInfo = 0, numOfNet = 0, ans = 0;

int main()
{
    cin >> n >> k;
    rep1(i, 1, n)
    {
        cin >> a[i];
        if (a[i] > 0) numOfInfo++; else numOfNet++;
    }
    rep1(i, 1, k)
    {
        int p = numOfInfo, q = numOfNet;
        for (int j = i; j <= n; j += k)
                if (a[j] == 1) p--; else q--;
        ans = max(ans, abs(p - q));
    }
    cout << ans << endl;
    return 0;
}