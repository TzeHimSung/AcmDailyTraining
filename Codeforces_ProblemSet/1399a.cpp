#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> q;
    while (n--){
        int x; cin >> x;
        q.push(x);
    }
    int last = q.top();
    q.pop();
    while (!q.empty()) {
        if (q.top() - last > 1) {
            cout << "NO\n";
            return;
        }
        last = q.top();
        q.pop();
    }
    cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}