/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define ull unsigned long long 
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(a,b) sort(a+1,a+1+b)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int maxn=4e4+10, base=133;
int n,len,pos,res;
ull p[maxn],_hash[maxn];
unordered_map<ull,int>ma;
string name;

void init(){
	p[0]=1;
	for (int i=1;i<maxn;i++) p[i]=p[i-1]*base;
}

ull get(int left,int right,ull g[]){
	return g[right]-g[left-1]*p[right-left+1];
}

int check(int currLen){
	ma.clear();
	int ans=-1;
	for (int i=1;i<=len-currLen+1;i++){
		int pos=get(i,i+currLen-1,_hash);
		ma[pos]++;
		if (ma[pos]>=n) ans=i;
	}
	return ans;
}

bool binarySearch(int left,int right){
	pos=-1, res=-1;
	while (left<=right){
		int mid=left+right>>1;
		int num=check(mid);
		if (num!=-1){
			res=mid, pos=num;
			left=mid+1;
		} else right=mid-1;
	}
	return res!=-1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	while (cin>>n && n){
		cin>>name;
		_hash[0]=0;
		len=name.size();
		name=" "+name;
		for (int i=1;i<=len;i++) _hash[i]=_hash[i-1]*base+name[i]-'a';
		bool flag=binarySearch(1,len-n+1);
		if (!flag) cout<<"none"<<endl;
		else cout<<res<<" "<<pos-1<<endl;
	}
    return 0;
}

