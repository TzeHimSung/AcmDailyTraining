#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[10];
int main() {
    int T, t;
    scanf("%d", &T);
    for (int ii = 1; ii <= T; ii++) {
        int f = 0, l = 0, nl = 0;
        for (int i = 1; i <= 8; i++) {
            a[i] = 0;
            for (int j = 1; j <= 16; j++) {
                scanf("%1d", &t);
                a[i] = a[i] * 2 + t; // 转成10进制存起来
            }
            if (!a[i]) nl++; // nl记录当前连续的全0段个数
            else { // 如果遇到全1段，维护答案
                if (nl >= l && nl > 1) { // l是最长全0段有多长，要注意>=
                    f = i - nl; l = nl;  // f是最长全0段的开始位置
                }
                nl = 0;
            }
            if (i == 8 && nl > 1) { // 如果全0段一直到末尾
                if (nl > l) { // 如果是最长全0段，开始位置要记成i-nl+1
                    f = i - nl + 1; l = nl;
                }
                if (nl == l && f == 1) {
                    f = i - nl + 1; l = nl;
                }
            }
        }
        printf("Case #%d: ", ii);
        if (f == 1) printf(":"); // 如果全0段从头开始
        for (int i = 1; i <= 8; i++) {
            if (i == f) {
                printf(":");
                i += l;
            }
            if (i > 8) puts("");
            else printf("%x%c", a[i], ":\n"[i == 8]);
        }
    }
    return 0;
}