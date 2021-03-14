#include <bits/stdc++.h>
using namespace std;
#define pa pair<int ,string >  
string cc[26] = { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z" };
struct cmd1 {
	bool operator ()(pa &t1, pa &t2) {
		return t1.first < t2.first;
	}
};
int a[1005][30];
inline bool cherk(string st, int x)
{
	bool flag = true;
	for (int j = 0; j<st.length(); j++) a[x][st[j] - 64]--;
	for (int j = 1; j <= 26; j++)
		if (a[x][j]<0) flag = false;
	for (int j = 0; j<st.length(); j++) a[x][st[j] - 64]++;
	return flag;
}
int main()
{
	int n, m, t;
	bool flag;
	string s, last, ss, sk[1005];
	while (scanf("%d%d", &n, &m) == 2)
	{
		memset(a,0,sizeof(a));
		for (int i = 1; i <= m; i++)
		{
			cin >> sk[i];
			for (int j = 0; j<sk[i].length(); j++) a[i][sk[i][j] - 64]++;
		}
		priority_queue<pa, vector<pa>, cmd1 >q;
		last = "";
		t = 1;
		for (int i = 1; i <= 26; i++)
		{
			int d = 0;
			for (int j = 1; j <= m; j++)
			{
				if (cherk(cc[i - 1], j))
					d++;
			}
			q.push(make_pair(d, cc[i - 1]));
		}
		while (t <= n)
		{
			flag = true;
			int ttt = q.top().first;
			ss = q.top().second;
			q.pop();
			last = ss;
			for (int i = 1; i <= m; i++)
			{
				if (ss == sk[i])
				{
					flag = false;
				}
			}
			for (int i = 1; i <= 26; i++)
			{
				int d = 0;
				s = last + cc[i - 1];
				for (int j = 1; j <= m; j++)
					if (cherk(s, j))
						d++;
				q.push(make_pair(d, s));
			}
			if (flag == false) continue;
			t++;
			cout << ss << endl;
		}
	}
	return 0;
}