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

ll k,l;

ll jc(int n,int times)
{
	ll re=1;
	rep1(i,1,times) re*=n;
	return re;
}

int main()
{
	scanf("%lld%lld",&k,&l);
	if (k==l)
	{
		printf("YES\n0\n");
		return 0;
	}
	int t=1,sign=0;
	while (1)
	{
		ll tmp=jc(k,t+1);
		if (l==tmp) {sign=1; break;}
		else if (l<jc(k,t+1)) break;
		else t++;
	}
	if (sign) printf("YES\n%d\n",t);
	else puts("NO");
	return 0;
}