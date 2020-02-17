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

vector<int>a;

int main() {
    int x;
    while (~scanf("%1d", &x)) a.pb(x);
    if ((int)a.size() == 1) return puts("YES"), 0;
    int firstOne = a[0], back = 0;
    for (int i = 1; i < (int)a.size(); i++) back ^= a[i];
    if (firstOne == back) puts("YES"); else puts("NO");
    return 0;
}