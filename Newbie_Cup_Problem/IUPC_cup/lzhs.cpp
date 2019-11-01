#include<iostream>
#include<algorithm>
using namespace std;
char s[100010];
int a[100010];
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n >> s + 1;
        int cur = 1, cnt = 1;
        if (s[1] != '1')a[cnt++] = 0;
        for (int i = 2; i <= n; i++)
            if ((s[i - 1] == '1' && s[i] != '1') || (s[i - 1] != '1' && s[i] == '1')) {
                a[cnt++] = cur;
                cur = 1;
                a[cnt] = 0;
            } else cur++;
        a[cnt] = cur;
        //for(int i=1;i<=cnt;i++)cout<<a[i]<<" ";cout<<endl;
        int ans = 0, another1 = 0, another2 = 0;
        if ((cnt == 3 && a[1] > 0) || cnt >= 5)another1 = 1;
        //if((cnt==5&&a[1]>0)||cnt>=7)another2=1;
        for (int i = 1; i <= cnt; i++) {
            if (i & 1)ans = max(ans, a[i] + another1);
            else if (i + 1 <= cnt && a[i] == 1 && a[i - 1] > 0) {
                /*if(another2)*/ans = max(ans, a[i - 1] + a[i + 1] + 1);
                //else ans=max(ans,a[i-1]+a[i+1]);
            }
        }
        cout << ans << endl;
    }
}