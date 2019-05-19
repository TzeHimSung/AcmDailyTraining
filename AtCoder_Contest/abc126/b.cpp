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

string s;

int hefa(int x, int y)
{
    if ((x * 10 + y) <= 12 && (x * 10 + y) > 0) return 1; else return 0;
}

int main()
{
    cin >> s;
    int a = s[0] - '0', b = s[1] - '0', c = s[2] - '0', d = s[3] - '0';
    if (hefa(a, b) && hefa(c, d)) puts("AMBIGUOUS");
    else if (hefa(a, b) && !hefa(c, d)) puts("MMYY");
    else if (!hefa(a, b) && hefa(c, d)) puts("YYMM");
    else puts("NA");
    return 0;
}