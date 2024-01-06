#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    vector<string> vecs;
    string s;
    while (cin >> s)
        vecs.push_back(s);
    cout << vecs.size();
    s.clear();
    for (auto i : vecs)
        s += i;
    stack<bool> stk;
    bool now = false;
    for (int i = 0; i <= s.length(); ++i)
    {
        stk.push(s[i] - '0');
        if (now != s[i] - '0')
        {
            stk.pop();
            cout << " " << stk.size();
            while (!stk.empty())
                stk.pop();
            stk.push(s[i]);
            now = !now;
        }
    }
}
