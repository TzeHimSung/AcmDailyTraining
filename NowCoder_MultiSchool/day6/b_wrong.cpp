/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;++i)
#define rep0(i,a,b) for(int i=a;i<b;++i)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

int t, ip[33];
const int maxn = 129;
char s[maxn];

void tran(int startPos) {
    const int len = 16;
    ll tmp = 0, power = 0;
    for (int i = startPos + 15; i >= startPos; i--)
        tmp += (ll)(s[i] - '0') * pow(2, power++);
    for (int i = startPos / 4 + 3; i >= startPos / 4; i--) {
        ip[i] = tmp % 16;
        tmp /= 16;
    }
}

void output() {
    int allZero[8] = {0};
    for (int i = 7; i >= 0; i--) {
        int findNotZero = 0;
        for (int j = 0; j < 4; j++)
            if (ip[i * 4 + j]) {
                findNotZero = 1;
                break;
            }
        if (!findNotZero) allZero[i] = 1;
    }
    int zeroIntervalLen = 0, startPos = -1, pos = 7, cnt = 0;
    while (pos >= 0) {
        cnt = 0;
        while (!allZero[pos]) pos--;
        while (pos >= 0 && allZero[pos] == 1) cnt++, pos--;
        pos++;
        if ((cnt >= zeroIntervalLen && cnt >= 2 && pos) || (pos == 0 && cnt == 8)) {
            zeroIntervalLen = cnt;
            startPos = pos;
        }
        pos--;
    }
    int i = 0;
    for (; i < 8;) {
        if (i == startPos) {
            printf("::");
            i += zeroIntervalLen;
        } else {
            if (allZero[i]) {
                printf("0");
                if (i != 7) printf(":");
                i++;
                continue;
            }
            int meetNotZero = 0;
            for (int j = 0; j < 4; j++) {
                if (ip[i * 4 + j] == 0 && !meetNotZero) continue;
                meetNotZero = 1;
                if (ip[i * 4 + j] < 10) printf("%d", ip[i * 4 + j]);
                else printf("%c", (char)(ip[i * 4 + j] + 87));
            }
            if (i != 7 && !(startPos == i + 1)) printf(":");
            i++;
        }
    }
    puts("");
}

int main() {
    scanf("%d", &t);
    for (int ca = 1; ca <= t; ca++) {
        for (int i = 0; i < 33; i++) ip[i] = 0;
        scanf("%s", s);
        for (int i = 0; i < 128; i += 16) tran(i);
        printf("Case #%d: ", ca);
        output();
    }
    return 0;
}