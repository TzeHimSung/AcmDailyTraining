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

i32 n,s,ans=-1,x,y;

int main()
{
    cin>>n>>s;
    while (n--)
    {
        cin>>x>>y;
        if (x<s || (x==s && !y)) 
            ans=max(ans,!y?0:100-y);
    }
    cout<<ans<<endl;
    return 0;
}