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

int n, r;

// 10-n=r/100

int main() {
    cin >> n >> r;
    if (n >= 10) cout << r << endl;
    else cout << r + 100 * (10 - n) << endl;
    return 0;
}