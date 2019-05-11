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

const int maxn = 3e4 + 10;
struct Node
{
    double xjb, h, p, cost;
    Node() {}
    Node(double a, double b, double c)
    {
        cost = a; h = b; p = c; xjb = (b * c) / a;
    }
    bool operator<(const Node &rhs) const
    {
        return xjb > rhs.xjb;
    }
};

vector<Node>item;
int n, c;
double sum1 = 0, sum2 = 0;

int main()
{
    scanf("%d%d", &n, &c);
    rep1(i, 1, n)
    {
        double a, b, c; scanf("%lf%lf%lf", &a, &b, &c);
        item.pb(Node(a, b, c));
    }
    sort(item.begin(), item.end());
    int cnt = -1;
    while (cnt < n)
    {
        cnt++;
        if (c < item[cnt].cost) continue;
        int num = c / item[cnt].cost;
        sum1 += num * item[cnt].h, sum2 += num * item[cnt].p;
        c -= num * item[cnt].cost;
    }
    printf("%f\n", sum1 * sum2);
    return 0;
}