#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;

char s[10010];
int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    vector<ll> ans, noteql;
    for (int i = 1; i < n; i++)
        if (s[i] != s[i + 1])
            noteql.push_back(2 * i + 1);
    printf("%d\n", noteql.size());
    if (noteql.size() == 0) {
        if (s[1] == 'A')
            printf("-1\n");
        else
            printf("1\n");
        return 0;
    }
    ans.push_back(1), ans.push_back(-noteql.back()), noteql.pop_back();

    for (auto i : noteql) {
        vector<ll> tmp = ans;
        tmp.push_back(0);
        for (int j = 1; j < tmp.size(); j++)
            tmp[j] -= i * ans[j - 1];
        ans = tmp;
    }
    ll f = 1;
    if (((noteql.size() + 1) % 2 == 0 && s[1] == 'A') || ((noteql.size() + 1) % 2 == 1 && s[1] == 'H'))
        f = -1;
    // for (auto i : ans)
    // printf("%d ", f * i);
    for (int i = 0; i < (int)ans.size(); i++) {
        printf("%lld%c", f * ans[i], i == (int)ans.size() - 1 ? '\n' : ' ');
    }
    return 0;
}