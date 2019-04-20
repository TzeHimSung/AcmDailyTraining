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
#define int int32_t
#define ll int64_t
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
//namespace
using namespace std;
//header end

vector<int>ans;
int n;

int main()
{
    ans.clear();
    scanf("%d",&n);
    int tmp=n,dig=0;
    while (tmp) dig++,tmp/=10;
    rep1(i,n-dig*9,n)
    {
        tmp=i; int sum=i;
        while (tmp) sum+=tmp%10,tmp/=10;
        if (sum==n) ans.pb(i);
    }
    printf("%d\n",ans.size());
    repa(i,ans) printf("%d ",i);
    if (ans.size()) puts("");
    return 0;
}