#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a, b;
    cin >> n >> a >> b;
    n *= 60;
    int ans = 0;
    if (a > b)
        ans = (n - b) / a;
    else
        ans = (n - a) / b;
    ans = max(ans, 0);
    cout << ans << endl;
}