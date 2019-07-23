#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
typedef pair<int, int> pii;
int a[110], b[110], c[110];
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d%d%d", &a[i], &b[i], &c[i]);
        int ok = 0;
        for (int p = 1; p <= 1500; p++) {
            int w1 = 2 * rand() - RAND_MAX, w2 = 2 * rand() - RAND_MAX;
            ll minb = -1e18, maxb = 1e18;
            for (int i = 1; i <= n; i++) {
                ll s = w1 * a[i] + w2 * b[i];
                if (c[i] == 1)minb = max(minb, 1 - s);
                else maxb = min(maxb, 1 - s);
            }
            if (minb <= maxb) {
                ok++; break;
            }
        }
        if (!ok)printf("Infinite loop!\n");
        else printf("Successful!\n");
    }
}