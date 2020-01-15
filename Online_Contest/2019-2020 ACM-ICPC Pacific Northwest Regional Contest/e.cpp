#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define ff first
#define ss second

char s[100010];
int a[30];
int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++)a[s[i] - 'a' + 1]++;
    ll ans = 1;
    ll mod = 11092019;
    for (int i = 1; i <= 26; i++)ans = ans * (a[i] + 1) % mod;
    printf("%d\n", ans);
}