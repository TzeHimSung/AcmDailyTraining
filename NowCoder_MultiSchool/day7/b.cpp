#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;
const int maxn = 2000;
long long  A[maxn];
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i <= n; i++) {
            cin >> A[i];
        }
        if (n >= 3) {
            printf("No\n");
        } else {
            if (n == 2) {
                long long dx = A[1] * A[1] - 4 * A[0] * A[2];
                if (dx < 0) {
                    printf("Yes\n");
                } else {
                    printf("No\n");
                }
            } else {
                printf("Yes\n");
            }
        }
    }


    return 0;
}