#include <bits/stdc++.h>
using namespace std;
priority_queue< int, vector<int>, greater<int> > que;
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        que = priority_queue<int, vector<int>, greater<int>>();
        for (int i = 0; i < n; ++i) {
            int t;
            scanf("%d", &t);
            que.push(t);
        }
        int ans = 0;
        while (que.size() > 1) {
            int f1 = que.top();
            que.pop();
            int f2 = que.top();
            que.pop();
            ans += f1 + f2;
            que.push(f1 + f2);
        }
        printf("%d\n", ans);
    }
}