#include <stdio.h>
#include <stdlib.h>

int main() {
    while (1) {
        double result = 1.0;
        int n;
        printf("Please input n: ");
        scanf("%d", &n);
        if (n < 0 || n > 100) break;
        for (int i = 1; i <= n; i++) result = result * i;
        printf("%d! == %f\n", n, result);
    }
    return 0;
}