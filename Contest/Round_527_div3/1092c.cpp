//basic
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <climits>
#include <cmath>
#include <cstdint>
//STL
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <array>
#include <iterator>
//define
#define int int32_t
#define ll int64_t
#define dou double
#define pb push_back
#define mp make_pair 
#define fir first
#define sec second
#define init(a,b) fill(begin(a),end(a),b)
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;i++)
#define rep0(i,a,b) for(int i=a;i<b;i++)
#define repa(i,a) for(auto &i:a)
#define eps 1e-8
#define inf 0x3f3f3f3f
#define lson curr<<1
#define rson curr<<1|1
//namespace
using namespace std;
//header end

const int maxn=3e2+10;
string s[maxn],s1="",s2="",p[maxn];
int n,m,ans[maxn],numid[maxn],a[5];

bool check(string str)
{
    int l=str.size(),k=0;
    rep1(i,2,l)
    {
        k++; p[k]=""; numid[k]=1;
        rep1(j,i,l)
            p[k]+=str[j-1];
    }
    rep0(i,1,l)
    {
        p[++k]=""; numid[k]=2;
        rep1(j,1,i) p[k]+=str[j-1];
    }
    rep1(i,1,2*n-2)
    {
        ans[i]=0;
        rep1(j,1,k)
            if (numid[j]>0 && s[i]==p[j])
            {
                ans[i]=numid[j];
                numid[j]=0;
                break;
            }
        if (!ans[i]) return false;
    }
    return true;
}

int main()
{
    cin>>n;
    rep1(i,1,2*n-2) 
    {
        cin>>s[i];
        if (s[i].size()==n-1 && s1=="") s1=s[i];
        else if (s[i].size()==n-1 && s2=="") s2=s[i];
    }
    if (check(s1+s2[n-2]))
    {
        rep1(i,1,2*n-2)
            if (ans[i]==1) printf("S");
                else printf("P");
        puts("");
        return 0;
    }
    if (check(s2+s1[n-2]))
    {
        rep1(i,1,2*n-2)
            if (ans[i]==1) printf("S");
                else printf("P");
        puts("");
        return 0;
    }
    return 0;
}