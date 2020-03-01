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

const int maxn = 1e5 + 10;
int n, ans = -INT_MAX;
vector<int>a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for (auto &i : a) cin >> i;
    ans = a[0];
    int currSum = 0;
    for (auto i : a) {
        if (currSum < 0) {
            currSum = i;
        } else {
            currSum += i;
        }
        ans = max(ans, currSum);
    }
    cout << ans << endl;
    return 0;
}

/*
8
1 -2 3 10 -4 7 2 -5
 */