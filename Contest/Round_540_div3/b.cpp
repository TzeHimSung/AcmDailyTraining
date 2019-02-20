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
int n, odd[maxn], even[maxn], x, ans = 0;

int main()
{
    cin >> n;
    rep1(i, 1, n)
    {
        cin >> x;
        odd[i] = odd[i - 1];
        even[i] = even[i - 1];
        if (i & 1)
            even[i] += x;
        else
            odd[i] += x;
    }
    rep1(i, 1, n)
    if (odd[i - 1] + even[n] - even[i] == even[i - 1] + odd[n] - odd[i])
        ans++;
    cout << ans << endl;
    return 0;
}