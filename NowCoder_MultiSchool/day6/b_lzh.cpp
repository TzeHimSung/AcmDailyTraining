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

const int maxn = 200;
char ch[maxn], s[maxn];
int num[40], a[40], b[40];

char getChar(int ch) {
    return ch < 10 ? ch + '0' : ch - 10 + 'a';
}

bool cmp(string a, string b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

int main() {
    int t; scanf("%d", &t);
    for (int caseNum = 1; caseNum <= t; caseNum++) {
        scanf("%s", s + 1);
        printf("Case #%d: ", caseNum);
        for (int i = 1; i <= 32; i++) {
            int tmp = 0;
            for (int j = 4 * i - 3; j <= 4 * i; j++) tmp = tmp * 2 + (s[j] == '1');
            b[i] = tmp;
        }
        for (int i = 1; i <= 8; i++) a[i] = b[4 * i - 3] * 4096 + b[4 * i - 2] * 256 + b[4 * i - 1] * 16 + b[4 * i];
        vector<string>v; v.clear();
        vector<pair<int, int> >st; st.clear(); // zero interval
        a[9] = 1; int zero = 0;
        for (int i = 1; i <= 8; i++) {
            if (a[i]) continue;
            for (int j = i; j <= 9; j++)
                if (a[j]) {
                    if (j - i >= 2) st.pb(mp(i, j - 1)); i = j;
                    break;
                }
        }
        if (st.empty()) {
            printf("%x", a[1]);
            for (int i = 2; i <= 8; i++) printf(":%x", a[i]);
            puts("");
        } else {
            for (auto p : st) {
                int l = p.first, r = p.second;
                string ss = "";
                for (int i = 1; i <= 8; i++) {
                    if (i == l) {
                        if (i == 1) ss += "::";
                        else ss += ":";
                        i = r;
                    } else {
                        int flag = 0;
                        for (int j = 4 * i - 3; j <= 4 * i; j++)
                            if (b[j] || flag) flag++, ss += getChar(b[j]);
                        if (!flag) ss += getChar(0);
                        if (i != 8)ss += ":";
                    }
                }
                v.pb(ss);
            }
            sort(v.begin(), v.end(), cmp);
            printf("%s\n", v[0].c_str());
        }
    }
}