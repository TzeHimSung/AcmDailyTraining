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

string s;
int n, cnt[30];
map<int, ll>m;

int main()
{
    m.clear();
    cin >> n;
    while (n--)
    {
        cin >> s; int len = s.size();
        init(cnt, 0);
        rep0(i, 0, len) cnt[s[i] - 'a']++;
        int curr = 0;
        rep0(i, 0, 26)
        if (cnt[i] & 1)
            curr |= (1 << i);
        m[curr]++;
    }
    ll ans = 0;
    repa(i, m)
    {
        int curr = i.first, cnt2 = 0;
        ans += m[curr] * (m[curr] - 1) / 2;
        rep0(i, 0, 26)
        if ((curr >> i) & 1)
        {
            cnt2++;
            int newOne = curr ^ (1 << i);
            ans += m[curr] * m[newOne];
        }
    }
    cout << ans << endl;
    return 0;
}