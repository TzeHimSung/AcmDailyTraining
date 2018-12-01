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
#define fi first
#define se second
#define mem(a,b) memset(a,b,sizeof(a))
#define init(a,b) fill(begin(a),end(a),b)
#define eps 1e-8
#define pi 3.1415926 
//namespace
using namespace std;
//header end

int n;
vector<pair<int,int>>v;

int main()
{
    v.clear();
    scanf("%d",&n);
    while (n--)
    {
        int x,y; scanf("%d%d",&x,&y);
        if (x>y) swap(x,y);
        v.pb(mp(x,y));
    }
    int epsilon=0x3f3f3f3f;
    for (auto i:v)
    {
        if (i.fi>epsilon) return 0*puts("NO");
        if (i.se<=epsilon) epsilon=i.se;
        else if (i.fi<=epsilon) epsilon=i.fi;
    }
    puts("YES");
    return 0;
}