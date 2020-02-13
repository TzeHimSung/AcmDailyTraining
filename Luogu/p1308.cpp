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

string a, b;

int main() {
    getline(cin, a); getline(cin, b);
    a = ' ' + a + ' ', b = ' ' + b + ' ';
    for (auto &i : a) i = tolower(i);
    for (auto &i : b) i = tolower(i);
    if (b.find(a) == string::npos) {
        return puts("-1"), 0;
    }
    int pos = b.find(a), tmp = pos, cnt = 0;
    while (tmp != string::npos) {
        cnt++;
        tmp = b.find(a, tmp + 1);
    }
    printf("%d %d\n", cnt, pos);
}