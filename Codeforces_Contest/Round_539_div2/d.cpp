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
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

string s;
int len;

int check(string ss)
{
    int sign = 1;
    rep0(i, 0, len)
    if (ss[i] != ss[len - i - 1]) sign = 0;
    return (ss != s) && sign;
}

int main()
{
    cin >> s;
    len = s.size();
    int sign = 0;
    rep0(i, 1, len)
    {
        if (len & 1 && i == len / 2) continue;
        if (s[i] != s[0]) sign = 1;
    }
    if (!sign)
        return cout << "Impossible", 0;
    rep0(i, 1, len)
    {
        string s1 = s.substr(0, i), s2 = s.substr(i, len);
        s2 += s1;
        if (check(s2)) sign = 0;
    }
    if (!sign) puts("1"); else puts("2");
    return 0;
}