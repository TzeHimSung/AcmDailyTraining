#include <bits/stdc++.h>
#define exp 1e-7

using namespace std;

double n, p, s, v;
double f(double c)
{
	return n * pow(log2(n), sqrt(2)*c) / p / 1e9 + s * (1 + 1 / c) / v;
}

int main()
{
	while (~scanf("%lf%lf%lf%lf", &n, &p, &s, &v))
	{
		double mid, mmid, high, low;
		low = 0, high = 100;
		while (high - low>exp)
		{
			mid = (high + low) / 2;
			mmid = (high + mid) / 2;
			if (f(mid) < f(mmid))
				high = mmid;
			else low = mid;
		}
		double ans = low;
		printf("%lf %lf\n", f(ans), ans);
	}
}