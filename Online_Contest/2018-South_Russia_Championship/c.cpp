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

const int MAXN = 1e5 + 10;
int n, k, ans = 0;
int a[MAXN], nextPos[MAXN];
vector<int>pos[MAXN];
set<int>nums, used;

int main() {
    for (int i = 0; i < MAXN; i++) nextPos[i] = -1;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
        nums.insert(a[i]);
    }
    for (auto num : nums) {
        for (int i = (int)pos[num].size() - 2; i >= 0; i--) {
            nextPos[pos[num][i]] = pos[num][i + 1];
            // cout << nextPos[pos[num][i]] << endl;
        }
    }
    for (int i = 0; i < n; i++) {
        if (used.find(i) != used.end()) used.erase(i);
        else {
            ans++;
            if ((int)used.size() >= k) used.erase(*used.rbegin());
        }
        if (nextPos[i] != -1) {
            used.insert(nextPos[i]);
            // cout << nextPos[i] << endl;
        }
    }
    cout << ans << endl;
    return 0;
}