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
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

string s, a = "";
int sum = 0;

int main() {
    cin >> s;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] != '-') a += s[i];
    }
    for (int i = 0; i < 9; i++) {
        sum += (i + 1) * (a[i] - '0');
    }
    sum %= 11;
    if (sum == (s[s.size() - 1] - '0') || sum == 10 && s[s.size() - 1] == 'X') puts("Right");
    else {
        if (sum < 10) s[s.size() - 1] = char('0' + sum);
        else s[s.size() - 1] = 'X';
        cout << s << endl;
    }
    return 0;
}