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

int n, anscnt = INT_MAX;
string tmp = "BGR", s, ans;

int main()
{
    cin >> n >> s;
    do
    {
        int cnt = 0;
        rep0(i, 0, n)
        if (s[i] != tmp[i % 3]) cnt++;
        if (cnt < anscnt)
        {
            ans = "", anscnt = cnt;
            rep0(i, 0, n) ans.push_back(tmp[i % 3]);
        }
    }
    while (next_permutation(tmp.begin(), tmp.end()));
    cout << anscnt << endl << ans << endl;
    return 0;
}