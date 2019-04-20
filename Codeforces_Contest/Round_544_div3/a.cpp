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

int h1, h2, m1, m2, delta;
string s1, s2;

int main()
{
    cin >> s1 >> s2;
    h1 = (s1[0] - '0') * 10 + s1[1] - '0';
    m1 = (s1[3] - '0') * 10 + s1[4] - '0';
    h2 = (s2[0] - '0') * 10 + s2[1] - '0';
    m2 = (s2[3] - '0') * 10 + s2[4] - '0';

    delta = 60 * h2 + m2 - 60 * h1 - m1;
    m1 += delta / 2;
    h1 += m1 / 60, m1 %= 60;

    if (h1 < 10) cout << 0;
    cout << h1 << ":";
    if (m1 < 10) cout << 0;
    cout << m1 << endl;
    return 0;
}