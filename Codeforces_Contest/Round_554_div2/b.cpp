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

vector<int>ans;
int n, op = 0;

inline int lowbit(int x)
{
    return x & -x;
}

int get(int x)
{
    int ret = 1;
    while (ret <= x) ret <<= 1;
    return ret - 1;
}

int calc(int x)
{
    int ret = 0, tmp = 1;
    while (tmp <= x) ret++, tmp <<= 1;
    return ret;
}

int check(int x)
{
    x++;
    if (x - lowbit(x)) return true; else return false;
}

int main()
{
    scanf("%d", &n);
    while (check(n))
    {
        op++;
        if (op & 1)
        {
            ans.pb(calc(n));
            n ^= get(n);
        }
        else n++;
    }
    printf("%d\n", op);
    for (auto i : ans) printf("%d ", i);
    puts("");
    return 0;
}
