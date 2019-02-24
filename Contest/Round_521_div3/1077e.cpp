//basic
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <climits>
#include <algorithm>
#include <cmath>
#include <array>
#include <cstdint>
#include <iterator>
//STL
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
//define
#define ll long long 
#define pb push_back
#define mp make_pair 
#define init(a,b) fill(begin(a),end(a),b)
#define sot(a,b) sort(a+1,a+1+b)
#define eps 1e-8
#define i32 int32_t
#define i64 int64_t
//namespace
using namespace std;
//header end

const i32 maxn=2e5+10;

i32 n,numOfqu=0,ans=0,x,ques[maxn];
map<i32,i32>m;

int main()
{
    m.clear(); init(ques,0);
    scanf("%d",&n); 
    for (i32 i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if (!m.count(x)) m[x]=++numOfqu;
        ques[m[x]]++;
    }
    sot(ques,numOfqu);
    for (i32 i=1;i<=n;i++)
    {
        i32 tmp=0,sign=1;
        for (i32 j=i;j<=n;j*=2)
        {
            i32 pos=lower_bound(ques+sign,ques+numOfqu+1,j)-ques;
            if (pos==numOfqu+1) break;
            tmp+=j;
            sign=pos+1;
        }
        ans=max(ans,tmp);
    }
    printf("%d\n",ans);
    return 0;
}