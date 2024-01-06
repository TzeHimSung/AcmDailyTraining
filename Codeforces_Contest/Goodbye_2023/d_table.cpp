#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool check(ll x, ll y)
{
    map<int, int> a, b;
    while (x)
    {
        a[x % 10]++;
        x /= 10;
    }
    while (y)
    {
        b[y % 10]++;
        y /= 10;
    }
    for (int i = 0; i < 10; i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    map<ll, vector<ll>> mp;

    for (int i = 1; i * i < pow(10, n); i++)
    {
        if (i * i < pow(10, n - 1))
            continue;
        int flag = 0;
        for (auto k : mp)
        {
            if (check(k.first, i * i))
            {
                mp[k.first].emplace_back(i * i);
                flag = 1;
                break;
            }
        }
        if (!flag)
            mp[i * i].emplace_back(i * i);
    }

    for (auto k : mp)
    {
        if (k.second.size() < n)
            continue;
        cout << k.first << ": ";
        for (auto i : k.second)
        {
            cout << i << ' ';
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

// 3
// 169: 169 196 961

// 5
// 10609: 10609 16900 19600 61009 90601 96100
// 16384: 16384 31684 36481 38416 43681

// 7
// 1006009: 1006009 1060900 1690000 1960000 6100900 9006001 9060100 9610000
// 1046529: 1046529 1695204 1946025 4052169 5294601 6215049 9641025
// 1048576: 1048576 1056784 1085764 5740816 5764801 6754801 7845601
// 1236544: 1236544 1532644 1643524 3254416 3452164 4456321 4532641
// 1493284: 1493284 3214849 3912484 4239481 4293184 4932841 9132484
// 1638400: 1638400 3168400 3648100 3806401 3841600 4036081 4368100