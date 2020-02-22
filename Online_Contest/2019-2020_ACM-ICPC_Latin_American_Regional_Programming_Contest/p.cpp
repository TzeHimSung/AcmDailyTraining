#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;

int a[1010];
int main() {
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        int tmp = 1;
        for (int j = i + 1; j <= n; j++)
            if (a[j] - a[j - 1] <= x)
                tmp++;
            else
                break;
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}