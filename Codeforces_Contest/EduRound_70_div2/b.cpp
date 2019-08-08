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

const int maxn = 2e6 + 10;
char s[maxn];
int len, ans[10][10];

int solve(int x, int y) {
    int ret = 0, cnt = 0, lastBit = 0;
    for (int i = 2; i <= len; i++) {
        int currBit = s[i] - '0';
        if ((currBit % 5) && ((!x && !y) || (x == 5 && y == 5) || (!x && y == 5) || (x == 5 && !y)))
            return -1;
        int t1 = 0, t2 = 0;
        while (currBit < lastBit) currBit += 10;
        while (x && (lastBit + x * t1) % 10 != currBit % 10) t1++;
        while (y && (lastBit + y * t2) % 10 != currBit % 10) t2++;
        int k = 10000;
        if (x) k = min(k, t1);
        if (y) k = min(k, t2);
        ret += k == 10000 ? 0 : k - 1;
        lastBit = s[i] - '0';
    }
    return ret;
}

int main() {
    scanf("%s", s + 1); len = strlen(s + 1);
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) ans[i][j] = -1;
    for (int i = 0; i < 10; i++)
        for (int j = i; j < 10; j++)
            ans[j][i] = ans[i][j] = solve(i, j);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) printf("%d ", ans[i][j]);
        puts("");
    }
    return 0;
}