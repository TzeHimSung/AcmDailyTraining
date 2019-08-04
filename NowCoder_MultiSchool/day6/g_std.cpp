#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[15], mon[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string s[100005];
bool check(int x) {
    int y = 0, m = a[s[x][5] - 'A'] * 10 + a[s[x][6] - 'A'], d = a[s[x][8] - 'A'] * 10 + a[s[x][9] - 'A'];
    for (int i = 0; i <= 3; i++)y = y * 10 + a[s[x][i] - 'A'];
    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)mon[2] = 29;
    else mon[2] = 28;
    if (y < 1600 || y > 9999 || m < 1 || m > 12 || d < 1 || d > mon[m])return false;
    if (m <= 2) {
        m += 12;
        y--;
    }
    int w = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7;
    if (w == 5)return true;
    return false;
}
int main() {
    int T, n;
    scanf("%d", &T);
    for (int ii = 1; ii <= T; ii++) {
        for (int i = 0; i < 10; i++)a[i] = i;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)cin >> s[i];
        sort(s + 1, s + n + 1);
        n = unique(s + 1, s + n + 1) - s - 1;
        printf("Case #%d: ", ii);
        int tmp = min(n, 20), flag = 1;
        do {
            int f = 1;
            for (int i = 1; f && i <= tmp; i++)
                if (!check(i))f = 0;
            if (f) {
                for (int i = tmp + 1; f && i <= n; i++)
                    if (!check(i))f = 0;
            }
            if (f) {
                for (int i = 0; i < 10; i++)printf("%d", a[i]);
                puts("");
                flag = 0;
                break;
            }
        } while (next_permutation(a, a + 10));
        if (flag)puts("Impossible");
    }
    return 0;
}