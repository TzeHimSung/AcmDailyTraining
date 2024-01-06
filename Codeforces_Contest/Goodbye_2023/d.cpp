#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        puts("1");
        return;
    }
    if (n == 3)
    {
        puts("169");
        puts("196");
        puts("961");
        return;
    }
    if (n == 5)
    {
        puts("16384");
        puts("31684");
        puts("36481");
        puts("38416");
        puts("43681");
        return;
    }
    string p = "196";
    while (p.length() < n)
        p += '0';
    cout << p << endl;
    for (int i = 1; i <= n / 2; ++i)
    {
        string s;
        s += '1';
        for (int j = 1; j < i; ++j)
            s += '0';
        s += '6';
        for (int j = 1; j < i; ++j)
            s += '0';
        s += '9';
        while (s.length() < n)
            s += '0';
        cout << s << endl;
    }

    for (int i = 1; i <= n / 2; ++i)
    {
        string s;
        s += '9';
        for (int j = 1; j < i; ++j)
            s += '0';
        s += '6';
        for (int j = 1; j < i; ++j)
            s += '0';
        s += '1';
        while (s.length() < n)
            s += '0';
        cout << s << endl;
    }
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