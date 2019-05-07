#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define sot(a,b) sort(a+1,a+1+b)
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define eps 1e-8
#define int_inf (1<<30)-1
#define ll_inf (1LL<<62)-1
#define lson curPos<<1
#define rson curPos<<1|1

using namespace std;

const int maxn=110;
int cnt[27];

int main()
{
    int t; scanf("%d",&t);
    while(t--){
        int flag=1;
        for (int i=1;i<=26;i++) cnt[i]=0;
        char s[maxn]; scanf("%s",s+1);
        int len=strlen(s+1);
        for (int i=1;i<=len;i++) cnt[s[i]-'a'+1]++;
        int st=0,ed=0;
        for (int i=1;i<=26;i++){
            if (!cnt[i] && !st) continue;
            if (!cnt[i] && st) {
                ed=1; continue;
            }
            if (cnt[i]>1) flag=0;
            if (cnt[i]==1 && !st) st=1;
            if (ed && cnt[i]) flag=0;
        }
        if (flag) puts("Yes"); else puts("No");
    }
    return 0;
}

