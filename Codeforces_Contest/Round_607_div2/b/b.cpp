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
#define lson (minpos<<1)
#define rson (minpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 5e3 + 10;
int t;
string s1, s2;
char minn[maxn];

int main() {
    cin >> t;
    while (t--) {
        cin >> s1 >> s2;
        int len1 = s1.size();
        if (s1 < s2) {
            cout << s1 << endl;
        } else {
            minn[len1 - 2] = s1[len1 - 1];
            for (int i = len1 - 3; i >= 0; i--) {
                minn[i] = min(s1[i], minn[i + 1]);
            }
            int flag = 0;
            for (int i = 0; i < len1; i++) {
                if (minn[i] < s2[i]) {
                    for (int j = i; j < len1; j++) {
                        if (s1[j] == minn[i]) {
                            swap(s1[i], s1[j]);
                            flag = 1;
                            break;
                        }
                    }
                    break;
                }
            }
            if (flag) cout << s1 << endl;
            else cout << "---" << endl;
        }
    }
    return 0;
}
