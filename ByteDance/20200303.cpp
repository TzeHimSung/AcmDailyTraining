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
int n, m;
ll ans = 0;
pair<int, int>stone, guard;
vector<pair<int, int>>in, out;
vector<int>dis, disInToStone;

int manhatton(pair<int, int> &p1, pair<int, int> &p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> stone.first >> stone.second >> guard.first >> guard.second;
    in.resize(n);
    out.resize(m);
    for (auto &i : in) {
        cin >> i.first >> i.second;
        disInToStone.push_back(manhatton(i, stone));
    }
    for (auto &i : out) {
        cin >> i.first >> i.second;
        dis.push_back(manhatton(i, guard) - manhatton(i, stone));
    }
    sort(disInToStone.begin(), disInToStone.end());
    for (auto i : dis) {
        ans += 1LL * (upper_bound(disInToStone.begin(), disInToStone.end(), i - 1) - disInToStone.begin());
    }
    cout << ans << endl;
    return 0;
}