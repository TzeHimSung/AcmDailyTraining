/*************************************************************************
*File Name: c.cpp
*Author: JHSeng
*zxc98567@163.com
*Created Time: Sun 11 Aug 2019 12:39:55 AM CST
 ************************************************************************/
/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;++i)
#define rep0(i,a,b) for(int i=a;i<b;++i)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, k; scanf("%d%d", &n, &k);
        if ((ll)n * (n + 1) / 2 % k || (n == k && n != 1)) {
            puts("no");
            continue;
        }
        puts("yes");
        int x = k, y = n / k, mp[x + 5][y + 5];
        if (y & 1) {
            for (int i = 1; i <= x; i++) mp[i][1] = i;
            mp[k / 2 + 1][2] = 2 * k;
            for (int i = k / 2 + 2; i <= x; i++) mp[i][2] = i - k / 2 - 1 + k;
            for (int i = 1; i <= k / 2; i++) mp[i][2] = k + k / 2 + i;
            for (int i = 1; i <= x; i++) mp[i][3] = 4 * k + k / 2 + 2 - mp[i][1] - mp[i][2];
            int nx = 1, ny = 4;
            for (int i = 3 * k + 1; i <= n; i++) {
                mp[nx][ny] = i;
                if (!(ny % 2)) {
                    if (nx == x) ny++;
                    else nx++;
                } else {
                    if (nx == 1) ny++;
                    else nx--;
                }
            }
        } else {
            int nx = 1, ny = 1;
            for (int i = 1; i <= n; i++) {
                mp[nx][ny] = i;
                if (ny % 2 == 1) {
                    if (nx == x) ny++;
                    else nx++;
                } else {
                    if (nx == 1) ny++;
                    else nx--;
                }
            }
        }
        for (int i = 1; i <= x; i++)
            for (int j = 1; j <= y; j++)
                printf("%d%c", mp[i][j], j == y ? '\n' : ' ');
    }
    return 0;
}

