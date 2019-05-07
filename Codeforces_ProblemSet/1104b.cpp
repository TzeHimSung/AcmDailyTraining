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

const int maxn=1e5+10;
char s[maxn];
int len,cnt=0;
stack<char>st;

int main()
{
    scanf("%s",s+1); len=strlen(s+1);
    while (!st.empty()) st.pop();
    for (int i=1;i<=len;i++){
        if (st.empty()) st.push(s[i]);
        else{
            char ch=st.top();
            if (ch==s[i]) cnt++, st.pop();
                else st.push(s[i]);
        }
    }
    if (cnt&1) puts("Yes"); else puts("No");
    return 0;
}

