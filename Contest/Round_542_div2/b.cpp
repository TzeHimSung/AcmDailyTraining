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

struct Node
{
    int x, pos;

    Node() {}
    Node(int a, int b)
    {
        x = a, pos = b;
    }

    bool operator<(const Node &rhs)const
    {
        if (x != rhs.x) return x < rhs.x;
        else return pos < rhs.pos;
    }
};
const int maxn = 2e5 + 10;
Node a[maxn];
int n, last1 = 1, last2 = 1;
ll ans = 0;

int main()
{
    cin >> n;
    rep1(i, 1, 2 * n)
    {
        int x; cin >> x;
        a[i].x = x, a[i].pos = i;
    }
    sot(a, 2 * n);
    for (int i = 1; i <= 2 * n; i += 2)
    {
        ans += min(abs(a[i].pos - last1) + abs(a[i + 1].pos - last2), abs(a[i].pos - last2) + abs(a[i + 1].pos - last1));
        last1 = a[i].pos, last2 = a[i + 1].pos;
    }
    cout << ans << endl;
    return 0;
}