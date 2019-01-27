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
#define int_inf 0p3f3f3f3f
#define ll_int 0p7f7f7f7f7f7f7f7f
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 2e5 + 10;
int a[maxn], _size[maxn], n, k;
ll ans = 0;
char s[maxn];

int main()
{
    cin >> n >> k;
    rep0(i, 0, n) cin >> a[i];
    char lastChar = ' ';
    int cnt = 0, pos = 0;
    rep0(i, 0, n)
    {
        cin >> s[i];
        if (s[i] == lastChar)
        {
            if (!cnt) pos = i - 1;
            cnt++;
        }
        else if (cnt)
        {
            _size[pos] = cnt + 1;
            cnt = 0;
        }
        if (i == n - 1 && cnt)
            _size[pos] = cnt + 1;
        lastChar = s[i];
    }
    rep0(i, 0, n)
    {
        if (_size[i] <= k) ans += a[i];
        else
        {
            vector<int>tmp;
            for (int j = i; j < _size[i] + i; j++) tmp.pb(a[j]);
            sort(tmp.begin(), tmp.end());
            int cnt = 0;
            for (int p = _size[i] - 1; p >= 0; p--)
            {
                if (cnt != k)
                {
                    ans += tmp[p];
                    cnt++;
                }
                else break;
            }
            i += _size[i] - 1;
        }
    }
    cout << ans << endl;
    return 0;
}