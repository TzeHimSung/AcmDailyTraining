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

int n;
string s;

int main()
{
    cin>>n>>s; int pos=n-1;
    for (int i=0;i<n-1;i++)
        if (s[i]>s[i+1]) {
            pos=i;
            break;
        }
    cout<<s.substr(0,pos)+s.substr(pos+1,n)<<endl;
    return 0;
}

