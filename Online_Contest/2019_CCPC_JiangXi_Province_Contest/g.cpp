#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ff first
#define ss second

int a[1010], b[1010], vis[3010];
int main() {
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= 1000; i++)vis[i] = 0;
        for (int i = 1; i <= n; i++)scanf("%d", &a[i]), vis[a[i]]++;
        for (int i = 1; i <= m; i++)scanf("%d", &b[i]);
        for (int i = 0; i <= 1010; i++) {
            int ok = 1;
            for (int j = 1; j <= m; j++)
                if (vis[b[j] + i]) {
                    ok = 0;
                    break;
                }
            if (ok) {
                printf("%d\n", i);
                break;
            }
        }
    }
}