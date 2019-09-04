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

const int maxn = 2e5 + 10;
int n;
char s[maxn];

int main() {
    scanf("%d", &n);
    scanf("%s", s + 1);
    if (n & 1) return puts("No"), 0;
    stack<int>st;
    while (!st.empty()) st.pop();
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(') st.push(0);
        if (s[i] == ')') {
            if (!st.empty() && st.top() == 0) st.pop();
            else st.push(1);
        }
    }
    if (st.empty()) return puts("Yes"), 0;
    else {
        if ((int)st.size() != 2) return puts("No"), 0;
        int tmp1 = st.top(), tmp2;
        st.pop();
        tmp2 = st.top();
        if (tmp1 != tmp2) return puts("Yes"), 0;
        else return puts("No"), 0;
    }
    return 0;
}
