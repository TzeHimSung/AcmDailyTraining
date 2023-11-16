#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int cnt = -1;
    vector<int> ans;
    while (n){
        cnt++;
        int k = n % 10;
        n /= 10;
        if (k) {
            ans.emplace_back(k * pow(10, cnt));
        }
    }
    cout << int(ans.size()) << '\n';
    for (auto i: ans) {
        cout << i << ' ';
    }
    cout << '\n';
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