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

const int maxn=60;
char s[maxn];
int len;
string ans="";

int main()
{
    scanf("%d%s",&len,s+1);
    int curr=0,cnt=0,p=0;
    while (curr<len){
        p+=++cnt;
        ans+=s[++curr];
        curr=p;
    }
    cout<<ans<<endl;
    return 0;
}

