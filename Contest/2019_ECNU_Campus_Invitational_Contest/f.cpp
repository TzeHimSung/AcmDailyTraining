#include<bits/stdc++.h>
#define ll long long

using namespace std;

map<string, int> M;
vector<string> v;

int main()
{
    int t;
    cin >> t;
    while (t)
    {
        string x;
        getline(cin, x);
        if (x == "") continue;
        string tmp = "";
        for (int i = 0; i < x.length(); i++)
        {
            if ('A' <= x[i] && x[i] <= 'Z')
            {
                tmp += x[i];
            }
        }
        M[tmp] ++ ;
        if (M[tmp] == 1)
        {
            v.push_back(tmp);
        }
        t--;
    }
    ll ans = 0;
    for (int i = 0; i  < v.size(); i++)
    {
        ll x = M[v[i]];
        ans += x * (x - 1) / 2ll;
    }
    cout << ans << endl;
    return 0;
}