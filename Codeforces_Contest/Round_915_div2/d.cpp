#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n * 2);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i + n] = a[i];
    }
    vector<int> v;
    for (int i = n; i < n * 2; i++)
    {
        if (!a[i])
        {
            for (int j = i - n + 1; j <= i; j++)
            {
                v.emplace_back(a[j]);
            }
            break;
        }
    }
    priority_queue<pair<int, long long>> q;
    long long ans = 0, curr = 0;
    for (int i = 0; i < v.size(); i++)
    {
        long long num = 1;
        while (!q.empty() && q.top().first > v[i])
        {
            num += q.top().second;
            curr -= q.top().first * q.top().second;
            q.pop();
        }
        curr += v[i] * num;
        q.push({v[i], num});
        ans = max(ans, curr);
    }
    cout << ans + n << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}