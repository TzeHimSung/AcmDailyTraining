#include<bits/stdc++.h>
using namespace std;
typedef pair<double,double>pdd;
#define ff first
#define ss second
const double pi=acos(-1.0);
bool solve(int a,int b,int w,int h,int c) {
	double beta=0;
	pdd x,y;
	if(a<=h){
		x.ff=0;
		x.ss=a;
	}
	else {
		x.ff=sqrt(a*a-h*h);
		x.ss=h;
		beta=acos(1.0*h/(a));
	}
	double afa=acos(1.0*(a*a+b*b-c*c)/(2*a*b));
	afa=pi/2-beta-afa;
	y.ff=cos(afa)*b;
	y.ss=sin(afa)*b;
	if(y.ff-w>0||y.ss-h>0||y.ff<0||y.ss<0)return false;
	return true;
}
int w,h,a,b,c;
bool find(){
	if(solve(b,c,w,h,a)||solve(c,b,w,h,a)){
		return true;
	}
	if(solve(a,c,w,h,b)||solve(c,a,w,h,b)){
		return true;
	}
	if(solve(a,b,w,h,c)||solve(b,a,w,h,c)){
		return true;
	}
	return false;
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d%d%d%d",&w,&h,&a,&b,&c);
		if(find())puts("jumao nb!");
		else puts("jumao laji!");
	}
}