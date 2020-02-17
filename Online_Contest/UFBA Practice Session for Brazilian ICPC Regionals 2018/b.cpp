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

const int maxn = 2e3 + 10;
char a[maxn], b[maxn];
int len1, len2, ans = 0;

int main() {
    scanf("%s%s", a, b);
    len1 = strlen(a), len2 = strlen(b);
    set<char>zero, one;
    zero.clear(), one.clear();
    for (int i = 0; i <= len1 - len2; i++) {
        zero.clear(), one.clear();
        for (int j = 0; j < len2; j++)
            if (b[j] == '1') one.insert(a[i + j]);
            else zero.insert(a[i + j]);
        if ((int)zero.size() > 1 || (int)one.size() > 1) {
            zero.clear(), one.clear();
            for (int j = 0; j < len2; j++)
                if (b[j] == '1') one.insert(a[len2 + i - 1 - j]);
                else zero.insert(a[len2 + i - 1 - j]);
            if ((int)zero.size() > 1 || (int)one.size() > 1) continue;
            else ans++;
        } else {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}