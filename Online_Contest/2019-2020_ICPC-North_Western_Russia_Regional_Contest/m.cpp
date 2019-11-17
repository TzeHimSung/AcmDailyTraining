#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int a[10001];
map<int, int> M;
int main() {
    int T;
    long long ans = 0;
    scanf("%d", &T);
    while (T--) {
        int n;
        M.clear();
        ans = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            M[a[i]]++;
        }
        for (int j = 0; j < n; ++j) {
            M[a[j]]--;
            if (M[a[j]] == 0) M.erase(a[j]);
            for (int i = 0; i < j; ++i) {
                int k = 2 * a[j] - a[i];

                if (M.find(k) != M.end()) ans += M[k];
            }
        }
        printf("%lld\n", ans);
    }
}