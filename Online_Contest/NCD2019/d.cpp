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

int t;

int main() {
    scanf("%d", &t);
    while (t--) {
        int x, y; scanf("%d%d", &x, &y);
        if (x > y) puts("Bashar");
        else if (x < y) puts("Hamada");
        else puts("Iskandar");
    }
    return 0;
}