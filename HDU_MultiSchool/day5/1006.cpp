#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

const int maxn = 2000000;
char s[maxn];
int Next[maxn];
typedef long long ll;
void pre_EKMP(int m) {
    Next[0] = m;
    int j = 0;
    while (j + 1 < m && s[j] == s[j + 1]) j++;
    Next[1] = j;
    int k = 1;
    for (int i = 2; i < m; i++) {
        int p = Next[k] + k - 1;
        int L = Next[i - k];
        if (i + L < p + 1) {
            Next[i] = L;
        } else {
            j = max(0, p - i + 1);
            while (i + j < m && s[i + j] == s[j]) j++;
            Next[i] = j;
            k = i;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> s;
        int len = strlen(s);
        pre_EKMP(len);
        ll ans = 0;
        for (int i = 1; i < len; i++) {
            ans += Next[i];
            if (i + Next[i] < len) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}