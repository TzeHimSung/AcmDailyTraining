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

const int maxn = 2e6 + 10;
char s[maxn], t[maxn], tmp[maxn << 1];
int pos, Len[maxn << 1], l, r;
ll ans;

int init(char *st) //hash
{
    int len = strlen(st);
    tmp[0] = '$'; //
    for (int i = 1; i <= 2 * len; i += 2)
    {
        tmp[i] = '#';
        tmp[i + 1] = st[i / 2];
    }
    tmp[2 * len + 1] = '#';
    tmp[2 * len + 2] = '^';
    tmp[2 * len + 3] = 0;
    return 2 * len + 1;
}

void manacher(char *st, int len)
{
    int maxx = 0, posi = 0;
    rep1(i, 1, len)
    {
        if (maxx > i)
            Len[i] = min(maxx - i, Len[2 * posi - i]);
        else
            Len[i] = 1;
        while (st[i - Len[i]] == st[i + Len[i]])
            Len[i]++;
        if (Len[i] + i > maxx)
        {
            maxx = Len[i] + i;
            posi = i;
        }
        l = (i - 1) / 2 - (Len[i] - 1) / 2; r = (i - 1) / 2 + (Len[i] - 1) / 2;
        if (Len[i] & 1) r--;
        ans += (r - l + 2) >> 1;
    }
    printf("%lld\n", ans);
    return;
}

int main()
{
    int Case; scanf("%d", &Case);
    while (Case--)
    {
        ans = 0;
        scanf("%s%s", s, t);
        int n = strlen(s); l = -1;
        rep0(i, 0, n)
        if (s[i] != t[i]) //找不同区间的最左端
        {
            l = i;
            break;
        }
        if (l != -1) //说明有不同区间
        {
            r = -1;
            for (int i = n - 1; i >= 0; i--) //找不同区间的最右端
                if (s[i] != t[i])
                {
                    r = i;
                    break;
                }
            int j = r, flag = 0;
            for (int i = l; i <= r; i++, j--) //判断不同区间翻转是否相等，若不相等答案必为0
                if (s[i] != t[j])
                {
                    flag = 1; break;
                }
            if (flag)
                puts("0");
            else //往左右两边扩展
            {
                ans = 1;
                for (int i = 1; i <= l && r + i < n; i++)
                    if (s[l - i] == s[r + i]) ans++;
                    else break;
                printf("%lld\n", ans);
            }
        }
        else
        {
            int len = init(s);
            printf("%s", tmp);
            // manacher(tmp, len);
        }
    }
    return 0;
}