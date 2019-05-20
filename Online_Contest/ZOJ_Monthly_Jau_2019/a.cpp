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
#define ll long long 
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

int t;
unsigned long long x;

int main()
{
    cin>>t;
    while (t--)
    {
        cin>>x;
        unsigned long long ans=1;
        for (int k=62;k>=0;k--)
        {
            unsigned long long t1=1ull<<k, t2=t1<<1;
            if (t1<x && x<t2) ans<<=1, x-=t1;
            if (t1==x){ ans*=t1; break;}
        }
        cout<<ans<<endl;
    }
    return 0;
}