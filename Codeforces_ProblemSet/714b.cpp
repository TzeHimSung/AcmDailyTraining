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
#define eps 1e-8

using namespace std;

set<int>s;
const int maxn=1e5+10;
int a,n;
ll sum=0;

int main()
{
    s.clear();
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {scanf("%d",&a); s.insert(a);}
    if (s.size()>3 || sum%n!=0)
        puts("NO");
    else if(s.size()<3)
        puts("YES");
    else
    {
        auto it=s.begin();
        sum+=*it;
        it++; it++; sum+=*it;
        it--;
        if (sum!=*it*2) puts("NO"); else puts("YES");
    }
    return 0;
}