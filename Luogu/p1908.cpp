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

const int maxn = 5e5 + 10;
int n, a[maxn], c[maxn];
ll ans = 0;

void mergeSort(int l, int r) {
    if (l == r) return;
    int mid = l + r >> 1, i = l, j = mid + 1, k = l;
    mergeSort(l, mid), mergeSort(mid + 1, r);
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) c[k++] = a[i++];
        else c[k++] = a[j++], ans += mid - i + 1;
    }
    while (i <= mid) c[k++] = a[i++];
    while (j <= r) c[k++] = a[j++];
    for (int i = l; i <= r; i++) a[i] = c[i];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    mergeSort(1, n);
    printf("%lld\n", ans);
    return 0;
}