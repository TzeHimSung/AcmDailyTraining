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
// #define int int32_t
// #define ll int64_t
#define ll long long 
#define dou double
#define pb push_back
#define mp make_pair 
#define fir first
#define sec second
#define init(a,b) fill(begin(a),end(a),b)
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;i++)
#define rep0(i,a,b) for(int i=a;i<b;i++)
#define repa(i,a) for(auto &i:a)
#define eps 1e-8
//namespace
using namespace std;
//header end

const int maxn=1e6;
int n,a[maxn];

void preTask()
{
	a[0]=a[1]=1;
	rep1(i,2,maxn)
	{
		a[i]=a[i-1]+a[i-2];
		if (a[i]>1e9) break;
	}
}

int main()
{
	preTask();
	scanf("%d",&n);
	if (n<=2) printf("0 0 %d\n",n);
	else
	{
		int i;
		for (i=1;i<n;i++)
			if (a[i]==n) break;
		printf("%d %d %d\n",a[i-2],a[i-2],a[i-3]);
	}
	return 0;
}