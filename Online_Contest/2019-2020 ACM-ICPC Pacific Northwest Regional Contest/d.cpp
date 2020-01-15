#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define ff first
#define ss second

int main() {
    int a, b, ans = 0; scanf("%d%d", &a, &b);
    while (a != b) {
        if (a % 2)a++;
        else if (a < b) {
            ans += b - a;
            break;
        } else a = a / 2;
        ans++;
    }
    printf("%d\n", ans);
}