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

string s;
int n, k, len, ans = 0;

int main()
{
    cin >> n >> k >> s;
    //for alphabet
    rep1(i, 0, 25)
    {
        char c = 'a' + i;
        int cnt = 0, _size = 0;
        //for string
        rep0(j, 0, n)
        {
            if (s[j] == c)
            {
                _size++;
                if (_size == k)
                {
                    cnt++;
                    _size = 0;
                }
            }
            else _size = 0;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}