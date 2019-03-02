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

const int maxn=10;
int a[maxn];
int n,curr=0;

int main()
{
    scanf("%d",&n);
    for (int i=0;i<7;i++) scanf("%d",&a[i]);
    int i;
    for (i=0;curr<n;i++) curr+=a[i%7];
    if (i%7==0) puts("7"); else printf("%d\n",i%7);
    return 0;
}