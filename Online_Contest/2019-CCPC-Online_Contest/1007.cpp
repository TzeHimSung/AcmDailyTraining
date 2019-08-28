/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;++i)
#define rep0(i,a,b) for(int i=a;i<b;++i)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 1025;
char board[11][maxn][maxn];

int main() {
    board[1][0][0] = 'C'; board[1][0][1] = 'C'; board[1][1][0] = 'P'; board[1][1][1] = 'C';
    int t; scanf("%d", &t);
    for (int i = 2; i <= 10; i++) {
        int mid = 1 << (i - 1), cur = 1 << i;
		for (int x=0;x<mid;x++)
			for (int y=0;y<mid;y++)
				board[i][x][y]=board[i-1][x][y];
		for (int x=0;x<mid;x++)
			for (int y=mid;y<cur;y++)
				board[i][x][y]=board[i-1][x][y-mid];
		for (int x=mid;x<cur;x++)
			for (int y=0;y<mid;y++)
				board[i][x][y]=board[i-1][x-mid][y]=='C'?'P':'C';
		for (int x=mid;x<cur;x++)
			for (int y=mid;y<cur;y++)
				board[i][x][y]=board[i-1][x-mid][y-mid];
    }
	while (t--){
		int k; scanf("%d",&k);
		for (int i=0;i<(1<<k);i++)
			printf("%s\n",board[k][i]);
	}
    return 0;
}

