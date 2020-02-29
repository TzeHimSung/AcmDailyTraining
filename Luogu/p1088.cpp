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

const int maxn = 1e4 + 10;
int n, m;
vector<int>a;

int main() {
    scanf("%d%d", &n, &m);
    a.resize(n);
    for (auto &i : a) scanf("%d", &i);
    while (m--) next_permutation(a.begin(), a.end());
    for (auto i : a) printf("%d ", i);
    puts("");
    return 0;
}