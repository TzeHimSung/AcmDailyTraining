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

queue<int>tower[3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int totNum = 0;
    ll ans = 0;
    for (int i = 0; i < 3; i++) {
        int num; cin >> num;
        while (num--) {
            int x; cin >> x;
            tower[i].push(x);
            totNum = max(totNum, x);
        }
    }

    function<int(int, int, int, int)> solve = [&](int remain, int from, int through, int to)->int{
        if (!remain) return 1;
        if (!tower[from].empty() && tower[from].front() == remain) {
            ans += 1LL << (remain - 1);
            tower[from].pop();
            return solve(remain - 1, from, to, through);
        }
        if (!tower[to].empty() && tower[to].front() == remain) {
            tower[to].pop();
            return solve(remain - 1, through, from, to);
        }
        return 0;
    };

    if (!solve(totNum, 0, 1, 2)) cout << "No" << endl;
    else cout << ans << endl;

    return 0;
}