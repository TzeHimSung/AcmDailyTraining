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

set<int>s;
int n, x;

int main()
{
    s.clear();
    cin >> n;
    rep1(i, 1, n)
    {
        cin >> x;
        s.insert(x);
    }
    if (s.size() == 1) puts("0");
    else if (s.size() == 2)
    {
        int b[2], p = 0;
        for (auto i : s) b[p++] = i;
        sort(b, b + 2);
        if ((b[1] - b[0]) % 2 == 0)
            cout << (b[1] - b[0]) / 2 << endl;
        else
            cout << b[1] - b[0] << endl;
    }
    else if (s.size() >= 4) puts("-1");
    else
    {
        int b[3], p = 0;
        for (auto i : s) b[p++] = i;
        sort(b, b + 3);
        if (b[2] - b[1] == b[1] - b[0]) cout << b[1] - b[0] << endl;
        else puts("-1");
    }
    return 0;
}