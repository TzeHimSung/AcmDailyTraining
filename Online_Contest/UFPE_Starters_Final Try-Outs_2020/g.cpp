#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define ff first
#define ss second

map<string, int>name, prob;
char strname[50010][25];
int pts[50010];
set<int>submit[50010];
int main() {
    int c, p, s; scanf("%d%d%d", &c, &p, &s);
    int cname = 0, cprob = 0;
    char str[50];
    for (int i = 1; i <= c; i++) {
        scanf("%s", strname[i]);
        name[strname[i]] = ++cname;
    }
    for (int i = 1; i <= p; i++) {
        int x;
        scanf("%s%d", str, &x);
        prob[str] = ++cprob; pts[cprob] = x;
    }
    for (int i = 1; i <= s; i++) {
        int numname = -1, numprob = -1;
        scanf("%s", str);
        numname = name[str];
        scanf("%s", str);
        numprob = prob[str];
        scanf("%s", str);
        if (strlen(str) == 2 && str[0] == 'A' && str[1] == 'C') {
            if (numname && numprob) {
                submit[numname].insert(numprob);
            }
        }
    }
    for (int i = 1; i <= c; i++) {
        int ans = 0;
        for (auto j : submit[i])ans += pts[j];
        printf("%s %d\n", strname[i], ans);
    }
}