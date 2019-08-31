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

int n, p, q, m;
ll ans;
stack<ll> st;
unsigned int SA, SB, SC;

unsigned int rng61() {
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1;
    unsigned int t = SA;
    SA = SB;
    SB = SC;
    SC ^= t ^ SA;
    return SC;
}

void gen() {
    scanf("%d%d%d%d%u%u%u", &n, &p, &q, &m, &SA, &SB, &SC);
    for (int i = 1; i <= n; i++) {
        if (rng61() % (p + q) < p) {
            int x = rng61() % m + 1;
            if (!(int)st.size()) st.push(x);
            else if (x > st.top()) st.push(x);
            else st.push(st.top());
        } else {
            if ((int)st.size()) st.pop();
            else continue;
        }
        if ((int)st.size()) ans ^= i * st.top();
    }
}

int main(void) {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        while ((int)st.size()) st.pop();
        ans = 0;
        gen();
        printf("Case #%d: %lld\n", i, ans);
    }
    return 0;
}
