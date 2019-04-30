#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b;
    while (cin >> a >> b)
    {
        int flag = 1;
        map<char, int>m;
        for (auto i : b) m[i]++;
        for (auto i : a)
        {
            if (!m[i])
            {
                puts("false");
                flag = 0;
                break;
            }
            else m[i]--;
        }
        if (flag) puts("true");
    }
    return 0;
}