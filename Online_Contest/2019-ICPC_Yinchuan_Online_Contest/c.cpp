/* Contest yinchuan_2019_online
 * Problem C
 * Team: Make One For Us
 */
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        int n, m;
        cin >> n >> m;
        string a, b, c;
        cin >> a >> b >> c;
        int delta = (b[0] - a[0] + 26) % 26;
        for (auto e : c) {
            char k = e - delta;
            if (k < 'A')
                k += 26;
            cout << k;
        }
        cout << endl;
    }
    return 0;
}
