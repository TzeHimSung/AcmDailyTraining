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

// const int maxn = 2e5 + 10;
const int maxn = 10;
int t, n, len, sh[maxn], lo[maxn];
char s[maxn];

void solveShort() {
    set<int>vis;
    for (int i = 1; i <= n; i++) sh[i] = 0;
    int cnt = n, i = n, len = n - 1;
    for (; i >= 1;) {
        i--;
        if (s[i] == '>' && !vis.count(i)) {
            int pos = i;
            while (pos - 1 >= 1 && s[pos - 1] == '>') pos--;
            for (int j = pos; j <= i; j++) {
                sh[j] = cnt--; vis.insert(j);
            }
        }
    }
    i = 0;
    for (; i <= n;) {
        i++;
        if (s[i] == '<' && !vis.count(i)) {
            int pos = i;
            while (pos + 1 <= n && s[pos + 1] == '<') pos++;
            if (pos == n - 1 && s[pos] == '<') pos++;
            for (int j = pos; j >= i; j--) {
                sh[j] = cnt--; vis.insert(j);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (sh[i]) printf("%d ", sh[i]); else printf("1 ");
    }
    puts("");
}

void solveLong() {
    set<int>vis; vis.clear();
    for (int i = 0; i <= n; i++) lo[i] = 0;
    int cnt = n, i = n, len = n - 1;
    for (; i >= 1;) {
        i--;
        if (s[i] == '<' && !vis.count(i)) {
            int pos = i;
            while (pos - 1 >= 1 && s[pos - 1] == '<') pos--;
            for (int j = pos; j <= i; j++) {
                lo[j] = cnt--; vis.insert(j);
            }
        }
    }
    i = n;
    for (; i >= 1;) {
        i--;
        if (s[i] == '>' && !vis.count(i)) {
            int pos = i;
            while (pos - 1 >= 1 && s[pos - 1] == '>') pos--;
            if (pos == 1 && s[pos] == '>') pos--;
            for (int j = pos; j <= i; j++) {
                lo[j] = cnt--; vis.insert(j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (lo[i]) printf("%d ", lo[i]); else printf("1 ");
    }
    puts("");
}

int main() {
    scanf("%d", &t);
    while (t--) {
        int same = 1;
        scanf("%d%s", &n, s + 1); len = n - 1;
        for (int i = 1; i < len; i++)
            if (s[i] != s[i + 1]) {
                same = 0; break;
            }
        if (same) {
            if (s[1] == '<') {
                for (int i = 1; i <= n; i++) printf("%d ", i);
                puts("");
                for (int i = 1; i <= n; i++) printf("%d ", i);
                puts("");
            } else {
                for (int i = n; i >= 1; i--) printf("%d ", i);
                puts("");
                for (int i = n; i >= 1; i--) printf("%d ", i);
                puts("");
            }
            continue;
        }
        solveShort();
        solveLong();
    }
    return 0;
}
/*
123456
>><>><
5>4>3<7>6>1<2
3>2>1<6>4>5<7
>>><
5>4>3>1<2
4>3>2>1<5
 */