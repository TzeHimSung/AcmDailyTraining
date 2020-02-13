/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;++i)
#define rep0(i,a,b) for(int i=a;i<b;++i)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e5 + 10;
int n, a[maxn];

void qsort(int curl, int curr) {
    int mid = a[curl + curr >> 1];
    int l = curl, r = curr;
    do {
        while (a[l] < mid) l++;
        while (a[r] > mid) r--;
        if (l <= r) {
            swap(a[l], a[r]);
            l++, r--;
        }
    } while (l <= r);
    if (curl < r) qsort(curl, r);
    if (l < curr) qsort(l, curr);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    qsort(1, n);
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    puts("");
    return 0;
}