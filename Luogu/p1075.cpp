#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        for (int j=1;j<=n;j++) {
            cout << setw(2) << setfill('0') << i * n + j;
        }
        cout << '\n';
    }
    cout << '\n';
    int cnt = 0;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n-i;j++) cout << "  ";
        for (int j=1;j<=i;j++) {
            cout << setw(2) << setfill('0') << ++cnt;
        }
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}