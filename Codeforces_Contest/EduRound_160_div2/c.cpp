#include <bits/stdc++.h>

using namespace std;

map<int, int> cnt;

bool check(int x)
{
    int available = 0;
    for (int i = 0; i < 30; i++)
    {
        available += cnt[i];
        if (x & (1 << i))
        {
            if (!available)
                return false;
            available--;
        }
        available /= 2;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int op, x;
        cin >> op >> x;
        if (op == 1)
        {
            cnt[x]++;
        }
        else
        {
            if (check(x))
                puts("YES");
            else
                puts("NO");
        }
    }

    return 0;
}