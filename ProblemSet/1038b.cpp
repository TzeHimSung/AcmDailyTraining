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

int n;

int main()
{
    scanf("%d",&n);
    if (n==1 || n==2)
        puts("No");
    else
    {
        puts("Yes");
        printf("1 %d\n",n);
        printf("%d ",n-1);
        for (int i=1;i<n;i++) printf("%d ",i);
    }
    return 0;
}