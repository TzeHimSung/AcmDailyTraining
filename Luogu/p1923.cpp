#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, k; cin >> n >> k;
    priority_queue<int, vector<int>, greater<int>>q;
    while (n--) {
        int x; cin >> x;
        q.push(x);
    }
    while (k--) q.pop();
    cout << q.top() << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}