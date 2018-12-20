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
#define mem(a,b) memset(a,b,sizeof(a))
#define init(a,b) fill(begin(a),end(a),b)
#define eps 1e-8
#define i32 int32_t
#define i64 int64_t
//namespace
using namespace std;
//header end

const i32 maxn=1e3+10;
i32 n,a[maxn],ans=0,num=0,flag=1;

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        ans+=a[i];
    }
    for (int i=1;i<=n;i++)
    {
        if (a[i] && flag) num++,flag=0;
        else if (!a[i]) flag=1;
    }
    printf("%d\n",ans+num-(!num?0:1));
    return 0;
}