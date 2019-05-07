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

const int maxn = 1e6;
int a[maxn * 4 + 10], com[maxn * 2 + 10];
int n;

int main()
{
    init(com, 0);
    cin >> n;
    rep1(i, 1, 2 * n) cin >> a[i];
    rep1(i, 1, 2 * n)
    com[a[i]] = 1;
    int ans = 0;
    rep1(i, 1, n)
    rep1(j, 1, n)
    {
        int t = a[i] ^ a[n + j];
        if (t <= 2 * maxn)
            ans += com[t];
    }
    if (ans & 1) puts("Koyomi");
    else puts("Karen");
    return 0;
}