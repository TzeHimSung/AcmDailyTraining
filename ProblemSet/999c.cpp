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

int n,k,cnt[50],top=0;
const int maxn=4e5+10;
char s[maxn],ans[maxn];

int main()
{
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    rep1(i,1,n) cnt[s[i]-'a']++;
    int ed=-1;
    rep1(i,0,25)
    {
        if (k<=cnt[i])
        {
            ed=i;
            break;
        }
        k-=cnt[i];
    }
    rep1(i,1,n)
    {
        if (s[i]-'a'<ed) continue;
        if (s[i]-'a'==ed && k)
        {
            k--;
            continue;
        }
        ans[++top]=s[i];
    }
    printf("%s\n",ans+1);
    return 0;
}