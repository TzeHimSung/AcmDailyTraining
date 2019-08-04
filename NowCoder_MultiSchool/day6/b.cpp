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

const int maxn = 10;
int a[maxn];

int main() {
    int t; scanf("%d", &t);
    for (int caseNum = 1; caseNum <= t; caseNum++) {
        int startPos = 0, maxLen = 0, currLen = 0;
        for (int i = 1; i <= 8; i++) {
            a[i] = 0;
            for (int j = 1; j <= 16; j++) {
                int x; scanf("%1d", &x);
                a[i] = a[i] * 2 + x;
            }
            if (!a[i]) currLen++; // currLen记录当前连续的全0段个数
            else { // 如果遇到全1段，维护答案
                if (currLen >= maxLen && currLen > 1) {
                    startPos = i - currLen;
                    maxLen = currLen;
                }
                currLen = 0;
            }
            if (i == 8 && currLen > 1) { // 如果全0段延续到末尾
                if (currLen > maxLen) // 如果是最长，照常处理
                    startPos = i - currLen + 1, maxLen = currLen;
                if (currLen == maxLen && startPos == 1) // 否则判断开头有长度跟最大长度相同的全0段
                    startPos = i - currLen + 1;
            }
        }
        printf("Case #%d: ", caseNum);
        if (startPos == 1) printf(":");
        for (int i = 1; i <= 8; i++) {
            if (i == startPos) {
                printf(":"); i += maxLen;
            }
            if (i > 8) puts("");
            else printf("%x%c", a[i], ":\n"[i == 8]);
        }
    }
    return 0;
}