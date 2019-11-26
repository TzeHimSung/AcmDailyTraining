#include <bits/stdc++.h>

int a[8], n, num, sum, cnt;
int mon[] = {0, 1, 2, 5, 10, 20, 50, 100};

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &num);
        sum = 0;
        for (int i = 1; i <= 7; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        cnt = sum;
        int p = 7;
        int tmp = 0;
        while (tmp < num && sum > 0) {
            if (a[p]) {
                sum--;
                tmp += mon[p];
                a[p]--;
            } else p--;
        }
        if (tmp >= num) printf("%d\n", cnt - sum); else printf("xuewei,ni zhe chou diaosi\n");
    }
    return 0;
}