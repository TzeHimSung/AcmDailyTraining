#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);
struct Point
{
	double x,y;
	double len;
};

double Distant(Point a,Point b)
{
	return sqrt(pow(a.x - b.x,2) + pow(a.y - b.y,2));
}
double ang(Point a,Point b)
{
	return acos((a.x * b.x + a.y * b.y)/(a.len*b.len));
}
int main()
{
	int T;
	cin >> T;
	for(int kass = 1;kass <= T;kass++){
		int n;
		cin >> n;
		vector<Point> A(n);
		for(int i = 0;i <= n-1;i++){
			cin >> A[i].x >> A[i].y;
		}
		vector<Point> Vec(n);
		for(int i = 0;i <= n-2;i ++){
			Vec[i].x = A[i+1].x - A[i].x;
			Vec[i].y = A[i+1].y - A[i].y;
			Vec[i].len = Distant(A[i+1],A[i]);
			// cout << Vec[i].x << " "<< Vec[i].y << " "<< Vec[i].len << endl;
		}
		// for(int i = 0;i <= n-1;i++){
		// 	cout << Vec[i].x << " "<< Vec[i].y << " "<< Vec[i].len << endl;
		// }
		Vec[n-1].x = A[0].x - A[n-1].x;
		Vec[n-1].y = A[0].y - A[n-1].y;
		Vec[n-1].len = Distant(A[0],A[n-1]);
		// for(int i = 0;i <= n-1;i++){
		// 	cout << Vec[i].x << " "<< Vec[i].y << " "<< Vec[i].len << endl;
		// }
		Point G;
		cin >>G.x >> G.y;
		double ans = 0.0;
		double r = Distant(G,A[0]);
		// cout << "r = " << r << endl;
		// cout << "ang = " << ang(Vec[0],Vec[n-1]) << endl;
		ans += abs(ang(Vec[n-1],Vec[0])*r);
		for(int i = 0;i <= n-2;i++){
			double r = Distant(G,A[i+1]);
			ans += abs(r * ang(Vec[i],Vec[i+1]));
			// cout << "r = " << r << endl;
			// cout << "ang = " << ang(Vec[i],Vec[i+1]) << endl;
		}
		printf("Case #%d: %.3lf\n",kass,ans);
	}

	return 0;
}include<bits/stdc++.h>

using namespace std;

const double PI = acos(-1);
struct Point
{
	double x,y;
	double len;
};

double Distant(Point a,Point b)
{
	return sqrt(pow(a.x - b.x,2) + pow(a.y - b.y,2));
}
double ang(Point a,Point b)
{
	return acos((a.x * b.x + a.y * b.y)/(a.len*b.len));
}
int main()
{
	int T;
	cin >> T;
	for(int kass = 1;kass <= T;kass++){
		int n;
		cin >> n;
		vector<Point> A(n);
		for(int i = 0;i <= n-1;i++){
			cin >> A[i].x >> A[i].y;
		}
		vector<Point> Vec(n);
		for(int i = 0;i <= n-2;i ++){
			Vec[i].x = A[i+1].x - A[i].x;
			Vec[i].y = A[i+1].y - A[i].y;
			Vec[i].len = Distant(A[i+1],A[i]);
			// cout << Vec[i].x << " "<< Vec[i].y << " "<< Vec[i].len << endl;
		}
		// for(int i = 0;i <= n-1;i++){
		// 	cout << Vec[i].x << " "<< Vec[i].y << " "<< Vec[i].len << endl;
		// }
		Vec[n-1].x = A[0].x - A[n-1].x;
		Vec[n-1].y = A[0].y - A[n-1].y;
		Vec[n-1].len = Distant(A[0],A[n-1]);
		// for(int i = 0;i <= n-1;i++){
		// 	cout << Vec[i].x << " "<< Vec[i].y << " "<< Vec[i].len << endl;
		// }
		Point G;
		cin >>G.x >> G.y;
		double ans = 0.0;
		double r = Distant(G,A[0]);
		// cout << "r = " << r << endl;
		// cout << "ang = " << ang(Vec[0],Vec[n-1]) << endl;
		ans += abs(ang(Vec[n-1],Vec[0])*r);
		for(int i = 0;i <= n-2;i++){
			double r = Distant(G,A[i+1]);
			ans += abs(r * ang(Vec[i],Vec[i+1]));
			// cout << "r = " << r << endl;
			// cout << "ang = " << ang(Vec[i],Vec[i+1]) << endl;
		}
		printf("Case #%d: %.3lf\n",kass,ans);
	}

	return 0;
}nclude<bits/stdc++.h>

using namespace std;

const double PI = acos(-1);
struct Point
{
	double x,y;
	double len;
};

double Distant(Point a,Point b)
{
	return sqrt(pow(a.x - b.x,2) + pow(a.y - b.y,2));
}
double ang(Point a,Point b)
{
	return acos((a.x * b.x + a.y * b.y)/(a.len*b.len));
}
int main()
{
	int T;
	cin >> T;
	for(int kass = 1;kass <= T;kass++){
		int n;
		cin >> n;
		vector<Point> A(n);
		for(int i = 0;i <= n-1;i++){
			cin >> A[i].x >> A[i].y;
		}
		vector<Point> Vec(n);
		for(int i = 0;i <= n-2;i ++){
			Vec[i].x = A[i+1].x - A[i].x;
			Vec[i].y = A[i+1].y - A[i].y;
			Vec[i].len = Distant(A[i+1],A[i]);
			// cout << Vec[i].x << " "<< Vec[i].y << " "<< Vec[i].len << endl;
		}
		// for(int i = 0;i <= n-1;i++){
		// 	cout << Vec[i].x << " "<< Vec[i].y << " "<< Vec[i].len << endl;
		// }
		Vec[n-1].x = A[0].x - A[n-1].x;
		Vec[n-1].y = A[0].y - A[n-1].y;
		Vec[n-1].len = Distant(A[0],A[n-1]);
		// for(int i = 0;i <= n-1;i++){
		// 	cout << Vec[i].x << " "<< Vec[i].y << " "<< Vec[i].len << endl;
		// }
		Point G;
		cin >>G.x >> G.y;
		double ans = 0.0;
		double r = Distant(G,A[0]);
		// cout << "r = " << r << endl;
		// cout << "ang = " << ang(Vec[0],Vec[n-1]) << endl;
		ans += abs(ang(Vec[n-1],Vec[0])*r);
		for(int i = 0;i <= n-2;i++){
			double r = Distant(G,A[i+1]);
			ans += abs(r * ang(Vec[i],Vec[i+1]));
			// cout << "r = " << r << endl;
			// cout << "ang = " << ang(Vec[i],Vec[i+1]) << endl;
		}
		printf("Case #%d: %.3lf\n",kass,ans);
	}

	return 0;
}
