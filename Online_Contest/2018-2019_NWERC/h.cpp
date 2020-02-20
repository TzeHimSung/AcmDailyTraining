#include <bits/stdc++.h>
using namespace std;
bool z[1000001];
int main() {
    int n, c, b;
    scanf("%d%d%d", &n, &c, &b);
    for (int i = 0; i < b; ++i) {
        int t;
        scanf("%d", &t);
        z[t - 1] = true;
    }
    int now = 0;
    if (c & 1) {
        now = 1;
        c++;
    }
    for (int i = 0; i < n; ++i) {
        if (z[i] || !c) printf("0");
        else {
            printf("%d", now);
            c--;
            now = 1 - now;
        }
    }
}