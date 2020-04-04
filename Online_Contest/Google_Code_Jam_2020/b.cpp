#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = 110;

int main() {
    int T; scanf("%d", &T);
    for (int __case = 1; __case <= T; __case++) {
        printf("Case #%d: ", __case);
        char s[MAXN]; scanf("%s", s + 1);
        int a[MAXN];
        int n = strlen(s + 1);
        for (int i = 1; i <= n; i++) a[i] = s[i] - '0';
        a[0] = a[n + 1] = 0;
        for (int i = 1; i <= n + 1; i++) {
            if (a[i] > a[i - 1]) {
                for (int j = a[i - 1] + 1; j <= a[i]; j++) printf("(");
            } else {
                for (int j = a[i] + 1; j <= a[i - 1]; j++) printf(")");
            }
            if (i != (n + 1))printf("%d", a[i]);
        }
        puts("");
    }
    return 0;
}