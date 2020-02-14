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

const int maxn = 310;
int n;
struct Student {
    int id, yu, shu, ying, sum;
    bool operator<(const Student &rhs)const {
        return sum != rhs.sum ? sum > rhs.sum : yu != rhs.yu ? yu > rhs.yu : id < rhs.id;
    }
} a[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &a[i].yu, &a[i].shu, &a[i].ying);
        a[i].id = i; a[i].sum = a[i].yu + a[i].shu + a[i].ying;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= 5; i++) printf("%d %d\n", a[i].id, a[i].sum);
    return 0;
}

