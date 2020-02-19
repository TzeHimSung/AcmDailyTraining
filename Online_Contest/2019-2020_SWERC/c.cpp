#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;

char s[110];
int main() {
    int n;
    scanf("%d", &n);
    map<int, int> m;
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        int k = strlen(s + 1);
        if (s[1] != '-' && k <= 7) {
            int x = 0;
            for (int j = 1; j <= k; j++)
                x = x * 10 + s[j] - '0';
            m[x]++;
        }
    }
    int pre = -1;
    for (auto i : m)
        if (pre + 1 == i.ff)
            pre++;
        else {
            printf("%d\n", pre + 1);
            return 0;
        }
    printf("%d\n", pre + 1);
}