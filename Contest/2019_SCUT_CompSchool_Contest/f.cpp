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

const int maxn = 5e3 + 10, maxm = 1e5 + 20;
int T, n = 5000;
double A, B, f[maxn][maxn], C[maxm];

int main()
{
    rep0(i, 1, maxm) C[i] = 1.0 * i * (i - 1) / 2;
    rep1(i, 0, n) rep1(j, 0, n)
    {
        if (!i && !j) continue;
        double t = 0, d = C[2 * i + j];
        if (i) t += i * (f[i - 1][j] + 1);
        if (i > 1) t += C[i] * 4 * (f[i - 2][j + 2] + 1);
        if (i && j) t += 2 * i * j * (f[i - 1][j] + 2);
        if (j >= 2) t += C[j] * (f[i][j - 2] + 3);
        A = t / d;
        if (j)
        {
            B = 0;
            if (i) B += 2 * i * (f[i - 1][j + 1] + 1);
            B += f[i][j - 1] + 1;
            B += (j - 1) * (f[i][j - 1] + 2);
            B /= 2 * i + j;
        }
        else B = 1e100;
        f[i][j] = A < B ? A : B;
    }
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        printf("%.2f\n", f[n][0]);
    }
    return 0;
}