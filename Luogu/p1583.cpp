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

const int maxn = 2e4 + 10;
int n, k, e[11];
struct Person {
    int w, d, c;
    bool operator<(const Person &rhs)const {
        return w != rhs.w ? w > rhs.w : d < rhs.d;
    }
} a[maxn];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= 10; i++) scanf("%d", &e[i]);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i].w);
        a[i].d = i;
    } 
	sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        a[i].c = (i - 1) % 10 + 1, a[i].w += e[a[i].c];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i < k; i++) printf("%d ", a[i].d);
    printf("%d\n", a[k].d);
    return 0;
}
