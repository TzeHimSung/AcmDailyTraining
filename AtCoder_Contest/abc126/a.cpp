/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;++i)
#define rep0(i,a,b) for(int i=a;i<b;++i)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

int n, k;
string s;

int main()
{
    cin >> n >> k >> s;
    for (int i = 0; i < n; i++)
        if (i != k - 1) cout << s[i];
        else cout << (char)(s[i] + 'a' - 'A');
    cout << endl;
    return 0;
}