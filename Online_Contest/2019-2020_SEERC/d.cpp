/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define pb emplace_back
#define mp make_pair
#define eps 1e-8
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e6 + 10;
char s[maxn];
int n, cnt[26], over = -1, kinds = 0;

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1) / 2;
    for (int i = 1; i <= 2 * n; i++) {
        if (!cnt[s[i] - 'a']) kinds++;
        cnt[s[i] - 'a']++;
        if (cnt[s[i] - 'a'] > n) over = s[i] - 'a';
    }

    if (over == -1) {
        puts("YES");
        for (int i = 0; i < 26; i++) {
            while (cnt[i]--) printf("%c", char(i + 'a'));
        }
        return 0;
    }

    if (cnt[over] >= 2 * n - 1) return puts("NO"), 0;
    if (cnt[over] >= 2 * n - 2 && kinds == 2) return puts("NO"), 0;
    puts("YES");
    for (int i = 1; i <= n; i++) printf("%c", over + 'a'), cnt[over]--;
    for (int i = 0, j = 0; i < 26, j < kinds / 2; i++) {
        if (i != over && cnt[i]) {
            j++;
            cnt[i]--;
            printf("%c", i + 'a');
        }
    }
    while (cnt[over]--) printf("%c", over + 'a');
    for (int i = 0; i < 26; i++) {
        if (i != over) {
            while (cnt[i]--) printf("%c", i + 'a');
        }
    }
    puts("");
    return 0;
}