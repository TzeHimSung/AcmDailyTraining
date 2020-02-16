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

int main() {
    int a[4];
    cin >> a[1] >> a[2] >> a[3];
    sort(a + 1, a + 1 + 3);
    if (a[1] == a[2] && a[2] != a[3] || a[1] != a[2] && a[2] == a[3]) puts("Yes"); else puts("No");
    return 0;
}