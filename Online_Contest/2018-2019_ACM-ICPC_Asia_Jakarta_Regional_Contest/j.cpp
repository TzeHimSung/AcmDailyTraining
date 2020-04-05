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

const int MAXN = 5e6 + 10, MAXM = 20;
struct Node {
    char s[MAXM];
    int id;
    bool operator<(const Node &rhs)const {
        int t = strcmp(s, rhs.s);
        return t ? t<0: id>rhs.id;
    }
} a[MAXN];
int n, aTop = 0, sum[MAXM];
char s[MAXM], t[MAXM];

int main() {

    function<void(int, int, int)> dfs = [&](int step, int length, int id) {
        if (!s[step]) {
            if (length) {
                copy(t, t + length, a[aTop].s);
                a[aTop++].id = id;
            }
            return;
        }
        dfs(step + 1, length, id);
        t[length] = s[step];
        dfs(step + 1, length + 1, id);
    };

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        dfs(0, 0, i);
    }
    for (int i = 1; i <= n; i++) sum[i] = INT_MIN;
    sort(a, a + aTop);
    for (int i = 0; i < aTop; i++) {
        sum[a[i].id] = max(sum[a[i].id], (int)strlen(a[i].s) + sum[a[i].id - 1]);
    }
    printf("%d\n", max(sum[n], -1));
    return 0;
}