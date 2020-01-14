#include <bits/stdc++.h>
using namespace std;
int li[] = {6, 28, 496, 8128};
int len = 4;
inline int read() {
    int rnt = 0;
    int sign = 0;
    char ch = 0;
    while (!isdigit(ch)) {
        sign |= ch == '-';
        ch = getchar();
    }
    while (isdigit(ch)) rnt = (rnt << 3) + (rnt << 1) + (ch ^ 48), ch = getchar();
    return sign ? -rnt : rnt;
}
inline void print(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
int main() {
    int n = read();
    while (n--) {
        int k = read();
        int ans;
        for (ans = len - 1; ans >= 0; --ans)
            if (li[ans] <= k) break;
        if (ans < 0) print(-1);
        else print(li[ans]);
        putchar('\n');
    }
}