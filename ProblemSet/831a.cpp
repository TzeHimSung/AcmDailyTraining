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

const i32 maxn=1e2+10;
i32 a[maxn],n;

int main()
{
    init(a,0);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    int inc=0,dec=0,fla=0;
    for (int i=1;i<n;i++)
        if (a[i]<a[i+1])
        {
            if (dec || fla) return 0*puts("NO");
            else if (!inc) inc=1;
        }
        else if (a[i]==a[i+1])
        {
            if (dec) return 0*puts("NO");
            fla=1;
        }
        else if (a[i]>a[i+1]) dec=1;
    puts("YES");
    return 0;
}