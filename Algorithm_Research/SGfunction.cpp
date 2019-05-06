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

const int maxn = 1e3 + 10;
const int maxf = 20;

int f[maxf], sg[maxn], s[maxn];

void getSG(int n)
{
    for (int i = 0; i < maxn; i++) sg[i] = 0;
    rep1(i, 1, n)
    {
        for (int j = 0; j < maxn; j++) s[j] = 0;
        for (int j = 0; f[j] <= i && j <= maxf; j++)
            s[sg[i - f[j]]] = 1;
        for (int j = 0;; j++) if (!s[j])
            {
                sg[i] = j;
                break;
            }
    }
}

int main()
{
    int n, m, k; f[0] = f[1] = 1;
    rep1(i, 2, 16) f[i] = f[i - 1] + f[i - 2];
    getSG(1000);
    while (scanf("%d%d%d", &m, &n, &k), n || m || k)
    {
        if (sg[n]^sg[m]^sg[k]) puts("Fibo");
        else puts("Nacci");
    }
    return 0;
}