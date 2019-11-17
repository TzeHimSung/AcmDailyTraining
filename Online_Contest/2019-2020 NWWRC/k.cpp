#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, char> pic;
typedef pair<int, int> pii;
char s[1010][1010], ans[1010][1010];
pii p[30];
vector<pic> v[1010];
int pt[1010];
void solve(pii l, pii r) {
    for (int i = 1; i <= 1000; i++)v[i].clear(), pt[i] = 0;
    for (int i = 2; i <= 26; i++)
        if (l.first <= p[i].first && p[i].first <= r.first &&
                l.second <= p[i].second && p[i].second <= r.second)
            v[p[i].first].push_back(make_pair(p[i].second, i + 'a' - 1));

    for (int i = l.first; i <= r.first; i++)
        sort(v[i].begin(), v[i].end());

    for (int i = l.first; i <= r.first; i++)
        if (v[i].size() == 0 && pt[i - 1]) {
            for (int j = l.second; j <= r.second; j++)ans[i][j] = ans[i - 1][j];
            pt[i] = 1;
        } else if (v[i].size() == 1) {
            for (int j = l.second; j <= r.second; j++)ans[i][j] = v[i][0].second;
            pt[i] = 1;
        } else if (v[i].size() > 1) {
            pt[i] = 1;
            int pre = l.second;
            for (auto j : v[i]) {
                for (; pre <= j.first; pre++)ans[i][pre] = j.second;
            }

            for (; pre <= r.second; pre++)ans[i][pre] = ans[i][pre - 1];
        }

    for (int i = r.first; i >= l.first; i--)
        if (!pt[i])
            for (int j = l.second; j <= r.second; j++)
                ans[i][j] = ans[i + 1][j];
}
int main() {
    int n, m; scanf("%d%d", &n, &m);
    pii A;
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= m; j++)
            if (s[i][j] != '.') {
                if (s[i][j] != 'A') {
                    p[s[i][j] - 'A' + 1] = make_pair(i, j);
                    v[i].push_back(make_pair(j, s[i][j] + 'a' - 'A'));
                } else A = make_pair(i, j);
            }
    }

    int tmp = 0;
    pii L, R;
    for (int i = 1; i <= n; i++) {
        priority_queue<int>l;
        priority_queue<int, vector<int>, greater<int>>r;
        l.push(0);
        r.push(m + 1);
        for (int j = i; j <= n; j++) {
            int gg = 0;
            for (int k = 2; k <= 26; k++)
                if (i <= p[k].first && p[k].first <= j) {
                    if (p[k].second == A.second) {
                        gg++; break;
                    } else if (p[k].second < A.second)l.push(p[k].second);
                    else r.push(p[k].second);
                }
            if (gg)break;
            if (i <= A.first && A.first <= j && l.top() < A.second && A.second < r.top()
                    && (j - i + 1) * (r.top() - l.top() - 1) > tmp) {
                tmp = (j - i + 1) * (r.top() - l.top() - 1);
                L = make_pair(i, l.top() + 1);
                R = make_pair(j, r.top() - 1);
            }
        }
    }
    if (L.first != 1)solve(make_pair(1, 1), make_pair(L.first - 1, m));
    if (R.first != n)solve(make_pair(R.first + 1, 1), make_pair(n, m));
    if (L.second != 1)solve(make_pair(L.first, 1), make_pair(R.first, L.second - 1));
    if (R.second != m)solve(make_pair(L.first, R.second + 1), make_pair(R.first, m));

    for (int i = 2; i <= 26; i++)ans[p[i].first][p[i].second] = 'A' + i - 1;
    for (int i = L.first; i <= R.first; i++)
        for (int j = L.second; j <= R.second; j++)
            ans[i][j] = 'a';
    ans[A.first][A.second] = 'A';

    for (int i = 1; i <= n; i++, printf("\n"))
        for (int j = 1; j <= m; j++)
            printf("%c", ans[i][j]);
}