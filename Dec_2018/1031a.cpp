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
#define eps 1e-8
#define i32 int32_t
#define i64 int64_t
//namespace
using namespace std;
//header end

i32 w,h,k,ans;

int main()
{
    cin>>w>>h>>k;
    for (int i=1;i<=k;i++)
    {
        ans+=2*w+2*h-4;
        w-=4,h-=4;
    }
    printf("%d\n",ans);
    return 0;
}