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

ll n;
set<ll>ans;
vector<ll>v;

int main()
{
    scanf("%lld",&n);
    ans.clear();
    v.clear(); 
    
    ans.insert((1+n)*n/2);
    ans.insert(1);
    for (int i=2;i<=sqrt(n)+1;i++)
        if (n%i==0)
        {
            v.pb(i);
            if (i*i!=n) v.pb(n/i);
        }
    for (auto i:v)
        ans.insert(1LL*(n/i)+1LL*(n/i-1)*n/2);
    for (auto i:ans) printf("%lld ",i);
    puts("");
    return 0;
}