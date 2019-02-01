/* basic header */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
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

const int maxn = 5e2 + 10;
const int px[] = {0, -1, -1, +1, +1};
const int py[] = {0, -1, +1, -1, +1};
char s[maxn][maxn];
int n, ans = 0;

int isX(int x, int y)
{
    if (s[x][y] == 'X') return 1; else return 0;
}

int isLeagl(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > n) return 0; else return 1;
}

int main()
{
    cin >> n;
    rep1(i, 1, n)
    scanf("%s", s[i] + 1);
    rep1(i, 1, n)
    rep1(j, 1, n)
    {
        int isCross = 1;
        rep1(k, 0, 4)
        {
            int nx = i + px[k], ny = j + py[k];
            if (!isLeagl(nx, ny) || !isX(nx, ny))
            {
                isCross = 0;
                break;
            }
        }
        if (isCross) ans++;
    }
    printf("%d\n", ans);
    return 0;
}