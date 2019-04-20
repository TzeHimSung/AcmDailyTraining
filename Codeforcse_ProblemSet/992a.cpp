//basic
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <climits>
#include <algorithm>
#include <cmath>
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
int n,x;

int main()
{
    scanf("%d",&n);
    while (n--)
    {
        scanf("%d",&x);
        if (x) s.insert(x);
    }
    printf("%d\n",s.size());
    return 0;
}