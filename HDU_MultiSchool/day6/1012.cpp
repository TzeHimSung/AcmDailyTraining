#include<cstdio>
#include<queue>
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        priority_queue<int>Q;
        while (!Q.empty()) Q.pop();
        for (int i = 1; i <= n; i++) {
            int x; scanf("%d", &x);
            Q.push(x);
        }
        ll ans[2]; ans[0] = ans[1] = 0LL;
        int fg = 0;
        while (!Q.empty()) {
            ans[fg] += Q.top();
            Q.pop();
            fg = 1 - fg;
        }
        printf("%lld %lld\n", ans[0], ans[1]);
    }
    return 0;
}