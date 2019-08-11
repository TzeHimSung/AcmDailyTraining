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
#define lson curpos<<1
#define rson curpos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e5 + 10;
int n;
string s[maxn];
map<pair<int, int>, vector<int> >m;
vector<pair<int, int> >fir, sec;
vector<pair<pair<int, char>, int> >in;

int isVowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
    return 0;
}

int main() {
    scanf("%d", &n);
    rep0(i, 0, n) {
        // scanf("%s", s[i].c_str());
        cin >> s[i];
        pair<pair<int, char>, int> tmp = mp(mp(0, 'z'), i);
        rep0(j, 0, s[i].size()) {
            if (isVowel(s[i][j])) {
                tmp.first.first++;
                tmp.first.second = s[i][j];
            }
        }
        m[tmp.first].pb(i);
    }
    for (auto it : m) {
        vector<int>r = it.second;
        for (int j = 0; j < r.size(); j += 2)
            if (j + 1 < r.size())
                sec.pb(mp(r[j], r[j + 1]));
            else
                in.pb(mp(it.first, r[j]));
    }
    sort(in.begin(), in.end());
    rep0(i, 0, (int)in.size()) {
        pair<pair<int, char>, int>tmp = in[i];
        if (i + 1 < in.size()) {
            if (in[i + 1].first.first == tmp.first.first) {
                fir.pb(mp(in[i + 1].second, tmp.second));
                i++;
            } else continue;
        } else break;
    }
    int r = 0;
    rep1(i, 1, sec.size()) {
        int rem = sec.size() - i + fir.size();
        if (i <= rem) r = i;
    }
    rep0(i, r, sec.size()) fir.pb(sec[i]);
    printf("%d\n", r);
    rep0(i, 0, r) {
        printf("%s %s\n", s[fir[i].first].c_str(), s[sec[i].first].c_str());
        printf("%s %s\n", s[fir[i].second].c_str(), s[sec[i].second].c_str());
    }
    return 0;
}
