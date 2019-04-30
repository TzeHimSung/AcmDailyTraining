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

const int maxn = 2e5 + 10;
int c1 = 0, c2 = 0, n, prime[maxn], p = 1, tot;
vector<int>ans;

//O(n)质数筛
//生成2~n的质数存在ans数组里，tot是质数个数，数组下标从1开始
bool valid[maxn];
void getPrime(int n, int &tot, int ans[maxn])
{
    tot = 0;
    memset(valid, 1, sizeof(valid));
    for (int i = 2; i <= n; i++)
    {
        if (valid[i]) ans[++tot] = i;
        for (int j = 1; (j <= tot) && (i * ans[j] <= n); j++)
        {
            valid[i * ans[j]] = false;
            if (i % ans[j] == 0) break;
        }
    }
}

int main()
{
    getPrime(2e5, tot, prime);
    ans.clear();
    scanf("%d", &n);
    rep1(i, 1, n)
    {
        int x; scanf("%d", &x);
        if (x & 1) c1++; else c2++;
    }
    int curr = 0;
    while (c1 || c2)
    {
        if (prime[p] - curr > 2 && c2)
        {
            ans.pb(2); c2--; curr += 2;
        }
        else if (prime[p] - curr == 2 && c2)
        {
            ans.pb(2); c2--; p++; curr += 2;
        }
        else if (prime[p] - curr == 1 && c1)
        {
            ans.pb(1); c1--; p++; curr += 1;
        }
        else
        {
            if (c2)
            {
                ans.pb(2); c2--; curr += 2;
            }
            else if (c1)
            {
                ans.pb(1); c1--; curr += 1;
            }
        }
    }
    for (auto i : ans) printf("%d ", i);
    return 0;
}