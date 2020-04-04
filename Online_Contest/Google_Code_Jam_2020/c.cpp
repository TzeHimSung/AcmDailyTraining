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

const int maxn = 110;
int t1[1500], t2[1500], T, n, ans[maxn];
pair<int, int>a[maxn];

int main() {
    scanf("%d", &T);
    for (int __case = 1; __case <= T; __case++) {
        for (int i = 0; i < 1500; i++) t1[i] = t2[i] = 0;
        scanf("%d", &n);
        int flag = 1;
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &a[i].first, &a[i].second);
            a[i].second--;
        }
        for (int i = 1; i <= n; i++) {
            // check t1
            int flag2 = 1;
            for (int j = a[i].first; j <= a[i].second; j++) {
                if (t1[j]) {
                    flag2 = 0;
                    break;
                }
            }
            if (flag2) {
                for (int j = a[i].first; j <= a[i].second; j++) t1[j] = 1;
                ans[i] = 1;
                continue;
            }
            flag2 = 1;
            for (int j = a[i].first; j <= a[i].second; j++) {
                if (t2[j]) {
                    flag2 = 0;
                    break;
                }
            }
            if (flag2) {
                for (int j = a[i].first; j <= a[i].second; j++) t2[j] = 1;
                ans[i] = 2;
            } else {
                flag = 0;
                break;
            }
        }
        printf("Case #%d: ", __case);
        if (!flag) printf("IMPOSSIBLE");
        else {
            for (int i = 1; i <= n; i++) {
                if (ans[i] == 1) printf("C");
                else printf("J");
            }
        }
        puts("");
    }
    return 0;
}