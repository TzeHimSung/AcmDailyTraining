/* basic header */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <climits>
#include <cmath>
#include <cstdint>
/* STL */
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <array>
#include <iterator>
/* define */
#define int int32_t
#define ll int64_t
#define dou double
#define pb emplace_back
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
/* namespace */
using namespace std;
/* header end */

const int maxn=5e5+10;
char s[maxn];

int main()
{
    scanf("%[^\n]",&s);
    int len=strlen(s),st=-1,ed=-1,stm=-1,edm=-1;
    rep0(i,0,len) 
        if (s[i]=='[')
        {
            st=i;
            break;
        }
    for (int i=len-1;i>=0;i--)
        if (s[i]==']')
        {
            ed=i;
            break;
        }
    if (ed-st<3) return cout<<"-1"<<endl,0;
    rep1(i,st+1,ed-1)
        if (s[i]==':')
        {
            stm=i;
            break;
        }
    for (int i=ed-1;i>=st+1;i--)
        if (s[i]==':' && i!=stm)
        {
            edm=i;
            break;
        }
    if (st==-1 || ed==-1 || stm==-1 || edm==-1)
        return cout<<"-1"<<endl,0;
    int ans=0;
    rep1(i,stm+1,edm-1)
        if (s[i]=='|') ans++;
    printf("%d\n",ans+4);
    return 0;
}