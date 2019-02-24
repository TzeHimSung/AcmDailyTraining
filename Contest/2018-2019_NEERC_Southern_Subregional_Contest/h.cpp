#include <bits/stdc++.h>
/* define */
#define int int32_t
#define ll int64_t
#define dou double
#define pb emplace_back
#define mp make_pair
#define fir first
#define sec second
#define init(a,b) fill(begin(a),end(a),b)
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;i++)
#define rep0(i,a,b) for(int i=a;i<b;i++)
#define repa(i,a) for(auto &i:a)
#define eps 1e-8
#define inf 0x3f3f3f3f
#define lson curr<<1
#define rson curr<<1|1
/* namespace */
using namespace std;
/* header end */

map<string, int>ans, has;
map<string, string>str;
int n, q;

int main()
{
    cin >> n;
    rep1(i, 1, n)
    {
        has.clear();
        string s; cin >> s;
        int len = s.size();
        rep0(i, 0, len)
        for (int j = 1; j + i <= len; j++)
        {
            string tmp = s.substr(i, j);
            if (has.count(tmp)) continue;
            has[tmp] = 1;
            ans[tmp]++;
            str[tmp] = s;
        }
    }
    cin >> q;
    while (q--)
    {
        string s; cin >> s;
        if (ans.count(s))
            cout << ans[s] << " " << str[s] << endl;
        else
            puts("0 -");
    }
    return 0;
}