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

struct Chap{
    int l,r;
    Chap(){}
    Chap(int a,int b):l(a),r(b){}

    bool operator<(const Chap& rhs)const{
        return l<rhs.l;
    }
};

vector<Chap>v;
int n,ans=0;

int main()
{
    scanf("%d",&n);
    while (n--){
        int l,r; scanf("%d%d",&l,&r);
        if (l>r) swap(l,r);
        v.pb(Chap(l,r));
    }
    int k; scanf("%d",&k);
    sort(v.begin(),v.end());
    for (auto i:v){
        if (i.l<=k && i.r>=k) ans++;
        else if (k<i.l) ans++;
    }
    printf("%d\n",ans);
    return 0;
}

