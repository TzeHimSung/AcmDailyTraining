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

int a[15], mon[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int maxn = 1e5 + 10;
string s[maxn];

int check(int x) {
    int year = 0, month = a[s[x][5] - 'A'] * 10 + a[s[x][6] - 'A'], day = a[s[x][8] - 'A'] * 10 + a[s[x][9] - 'A'];
    for (int i = 0; i < 4; i++)
        year = year * 10 + a[s[x][i] - 'A'];
    if (year % 4 == 0 && year % 100 || year % 400 == 0) mon[2] = 29;
    else mon[2] = 28;
    if (year < 1600 || year > 9999 || month < 1 || month > 12 || day < 1 || day > mon[month])
        return 0;
    if (month <= 2) month += 12, year--;
    int ans = (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400 + 1) % 7;
    if (ans == 5) return true;
    else return false;
}

int main() {
    int t; scanf("%d", &t);
    for (int caseNum = 1; caseNum <= t; caseNum++) {
        printf("Case #%d: ", caseNum);
        for (int i = 0; i < 10; i++) a[i] = i;
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++) cin >> s[i];
        sot(s, n);
        n = unique(s + 1, s + 1 + n) - s - 1;
        int tmp = min(n, 20), flag = 1;
        do {
            int haveSolution = 1;
            for (int i = 1; haveSolution && i <= tmp; i++)
                if (!check(i)) haveSolution = 0;
            if (haveSolution)
                for (int i = tmp + 1; haveSolution && i <= n; i++)
                    if (!check(i)) haveSolution = 0;
            if (haveSolution) {
                for (int i = 0; i < 10; i++) printf("%d", a[i]);
                puts("");
                flag = 0;
                break;
            }
        } while (next_permutation(a, a + 10));
        if (flag) puts("Impossible");
    }
    return 0;
}