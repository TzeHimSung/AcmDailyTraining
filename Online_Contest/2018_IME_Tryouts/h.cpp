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

double n, a, p;

int main() {
    scanf("%lf%lf%lf", &n, &a, &p);
    printf("%.8f\n", (a * p - a * (100.0 - p)) / 100.0 + n);
    return 0;
}