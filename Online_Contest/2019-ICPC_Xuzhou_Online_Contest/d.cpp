#include<bits/stdc++.h>

using namespace std;
const int maxn = 200000;

void getFail(char *p, int *nxt) {
    int m = strlen(p);
    nxt[0] = 0; nxt[1] = 0;
    for (int i = 1; i < m; i++) {
        int j = nxt[i];
        while (j && p[i] != p[j]) j = nxt[j];
        nxt[i + 1] = p[i] == p[j] ? j + 1 : 0;
    }
}

bool find(char *T, char *P, int *f) {
    int n = strlen(T), m = strlen(P);
    getFail(P, f);
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j && P[j] != T[i]) j = f[j];
        if (P[j] == T[i]) j++;
        if (j == m) {
            return true;
        }
    }
    return false;
}
int nxt[maxn];
void init(int n) {
    for (int i = 0; i <= n; i++) {
        nxt[i] = 0;
    }
}


int main() {
    char T[maxn];
    scanf("%s", T);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        char s[maxn];
        scanf("%s", s);
        int len1 = strlen(T);
        int len2 = strlen(s);
        init(max(len1, len2));
        if (len1 > len2) {
            if (find(T, s, nxt)) {
                printf("my child!\n");
            } else {
                printf("oh, child!\n");
            }
        } else if (len1 == len2) {
            if (find(T, s, nxt)) {
                printf("jntm!\n");
            } else {
                printf("friend!\n");
            }
        } else {
            if (find(s, T, nxt)) {
                printf("my teacher!\n");
            } else {
                printf("senior!\n");
            }
        }
    }
    return 0;
}