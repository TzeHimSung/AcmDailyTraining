#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define sot(a,b) sort(a+1,a+1+b)
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define eps 1e-8
#define int_inf (1<<30)-1
#define ll_inf (1LL<<62)-1
#define lson curPos<<1
#define rson curPos<<1|1

using namespace std;

map<char, int>m;
int n;
string s;

int main()
{
    m.clear();
    cin >> n;
    while (n--)
    {
        cin >> s;
        m[s[0]]++;
    }
    int ans = 0;
    for (auto i : m)
    {
        if (i.second <= 2) continue;
        int tmp = i.second / 2;
        ans += (tmp - 1) * tmp / 2;
        if (i.second & 1) tmp++;
        ans += (tmp - 1) * tmp / 2;
    }
    cout << ans << endl;
    return 0;
}