#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    long long ans = 0;
    cin >> n;
    vector<long long> a(n + 1), b(n + 1);
    b[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = b[i - 1] + a[i];
    }
    for (int k = 1; k < n; k++)
    {
        if (n % k)
            continue;
        long long max_sum = 0, min_sum = LONG_LONG_MAX;
        for (int j = k; j <= n; j += k)
        {
            long long curr = b[j] - b[j - k];
            max_sum = max(max_sum, curr);
            min_sum = min(min_sum, curr);
        }
        ans = max(ans, max_sum - min_sum);
    }
    cout << ans << '\n';
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}