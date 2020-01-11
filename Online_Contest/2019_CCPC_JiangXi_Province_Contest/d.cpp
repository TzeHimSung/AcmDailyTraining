#include <iostream>
using namespace std;
int a[500001];
int Max[1001];
int bin[1001];
int main() {
    int n, c;
    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int ans = 0;
    for (int j = 1; j <= c; ++j) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == j) ++cnt;
            else {
                if (Max[a[i]] < cnt) {
                    bin[a[i]]++;
                    Max[a[i]] = cnt;
                }
            }
        }
        //cout<<"done";
        for (int i = 1; i <= c; ++i) {
            int s = bin[i] * 2;
            if (s == 0) continue;
            if (Max[i] < cnt) ++s;
            ans = max(ans, s);
            bin[i] = 0;
            Max[i] = 0;
        }
        //cout<<"done2";
    }
    printf("%d\n", ans);
}