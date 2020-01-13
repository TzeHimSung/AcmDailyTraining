#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define ff first
#define ss second

int a[100];
int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++)scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                if (i != j && i != k && j != k) {
                    if (abs(a[i] - a[j]) % a[k] != 0) {
                        printf("no\n"); return 0;
                    }
                }
    printf("yes\n");
}