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
#define lson curpos<<1
#define rson curpos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 510, px[4] = {1, -1, 0, 0}, py[4] = {0, 0, 1, -1};
int h, w, cnt = 0, n = 0, m = 0, flag = 1, cnt2 = 0;
char s[maxn][maxn];

void dfs(int x, int y, int i) {
    if (s[x][y] == '*' && x >= 1 && x <= h && y >= 1 && y <= w) {
        x += px[i]; y += py[i]; cnt2++; dfs(x, y, i);
    }
}

int main() {
    scanf("%d%d", &h, &w);
    rep1(i, 1, h) scanf("%s", s[i] + 1);
    rep1(i, 1, h) {
        rep1(j, 1, w)
        if (s[i][j] == '*') cnt++;
    }
    if (h < 3 || w < 3) return puts("NO"), 0;
    rep1(i, 2, h - 1) {
        rep1(j, 2, w - 1) {
            if (s[i][j] == '*' && s[i - 1][j] == '*' && s[i][j - 1] == '*' && s[i + 1][j] == '*' && s[i][j + 1] == '*')
                if (!n) n = i, m = j;
                else flag = 0;
        }
    }
    if (!flag || n == 0) return puts("NO"), 0;
    rep0(i, 0, 4) dfs(n + px[i], m + py[i], i);
    cnt2++;
    if (cnt2 == cnt) puts("YES"); else puts("NO");
    return 0;
}