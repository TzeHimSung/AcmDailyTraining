#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;

char s[30];
int notuse[30];
const int dd[4][2] = { -1, 0, 1, 0, 0, 1, 0, -1 };
const int C[4][2] = { 0, 1, 1, 0, 2, 3, 3, 2 };
const char fa[] = { "LRUD" };
int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    if (n == 1) {
        if (s[1] == 'L')
            printf("1 0\n0\n");
        else if (s[1] == 'R')
            printf("-1 0\n0\n");
        else if (s[1] == 'U')
            printf("0 -1\n0\n");
        else
            printf("0 1\n0\n");
        return 0;
    }
    for (int j = 0; j <= 4; j += 2) {
        vector<int> tmp;
        for (int i = 1; i <= n; i++)
            if (s[i] == fa[j] || s[i] == fa[j + 1])
                tmp.push_back(i);
        for (int i = tmp.size() - 3; i >= 0; i--)
            if (tmp[i] + 1 == tmp[i + 1] && tmp[i + 1] + 1 == tmp[i + 2])
                notuse[tmp[i]]++;
    }
    for (int j = 0; j <= 4; j += 2) {
        int tmp = 0;
        for (int i = n; i >= 1; i--)
            if (s[i] == fa[j] || s[i] == fa[j + 1])
                tmp++;
            else
                break;
        if (tmp >= 3) {
            printf("impossible\n");
            return 0;
        }
    }

    vector<pii> ans;
    pii cur = { 0, 0 };
    int step = n + 1;
    for (int i = n; i >= 1; i--)
        if (!notuse[i]) {
            for (int j = 0; j < 4; j++)
                if (s[i] == fa[j]) {
                    if (i != n)
                        ans.push_back({ cur.ff + dd[j][0], cur.ss + dd[j][1] });

                    pii tmp = { (1 << step) *(-dd[j][0]), (1 << step) *(-dd[j][1]) };
                    if (tmp.ff)
                        cur.ff += tmp.ff;
                    else
                        cur.ss += tmp.ss;
                }
            step--;
        }
    printf("%d %d\n%d\n", cur.ff, cur.ss, ans.size());
    for (auto i : ans)
        printf("%d %d\n", i.ff, i.ss);
}