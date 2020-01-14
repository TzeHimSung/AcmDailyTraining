#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define ff first
#define ss second

const int MAXSTRLEN = 500010;
int maxlen0 = 0, maxlen1 = 0;
char ch[2 * MAXSTRLEN];
int p[2 * MAXSTRLEN];
void manacher(char str[], int len) {
    for (int i = 0; i < len; i++) {
        ch[2 * i + 1] = '#';
        ch[2 * i + 2] = str[i];
    }
    ch[0] = '$';
    ch[2 * len + 1] = '#';
    ch[2 * len + 2] = '\0';
    len = len * 2 + 2;
    p[0] = p[1] = 1;
    int id = 1, mx = 2;
    for (int i = 2; i < len; i++) {
        int j = min(p[2 * id - i], mx - i);
        while (ch[i - j] == ch[i + j])
            j++;
        p[i] = j;
        if (i + p[i] > mx) {
            id = i;
            mx = i + p[i];
        }
        if ((p[i] - 1) % 2 == 0)
            maxlen0 = max(maxlen0, p[i] - 1);
        else
            maxlen1 = max(maxlen1, p[i] - 1);
    }
}
char s[MAXSTRLEN];
int main() {
    int n, m;
    scanf("%d%d%s", &n, &m, s);
    manacher(s, n);
    if ((m % 2 == 0 && maxlen0 >= m) || (m % 2 == 1 && maxlen1 >= m)) {
        printf("Accept\n");
    } else
        printf("Reject\n");
}