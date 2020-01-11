#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ff first
#define ss second

int main() {
    int n;
    while (~scanf("%d", &n)) {
        double ans = 0;
        for (int i = 1; i <= n; i++) {
            char s[20]; scanf("%s", s + 1);
            int len = strlen(s + 1);
            if (s[len] >= '5')ans += 0.001 * ('9' - s[len] + 1);
            else ans -= 0.001 * (s[len] - '0');
        }
        printf("%.3lf\n", ans);
    }
}