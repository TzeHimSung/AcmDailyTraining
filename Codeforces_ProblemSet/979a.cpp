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

#define ll long long 
#define pb push_back
#define mp make_pair 

using namespace std;

ll n;

int main()
{
    scanf("%lld",&n); n++;
    if (n==1) puts("0");
    else if (n%2==0) printf("%lld\n",n/2);
    else printf("%lld\n",n);
    return 0;
}