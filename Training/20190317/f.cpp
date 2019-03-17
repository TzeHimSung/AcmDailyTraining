#include <bits/stdc++.h>

using namespace std;

// const int maxn = 1e4 + 10;
const int maxn = 20;
const int py[] = {0, -3, -3, +3, +3};
const int px[] = {0, -1, +1, +1, -1};
char a[maxn][maxn]; //empty is 0, + is 1, - is 2, \ is 3, / is 4
int vis[maxn][maxn];
int t, ans = INT_MAX, rsize, csize;

int check(int x, int y)
{
    if (x <= 0 || x > rsize || y <= 0 || y > csize || a[x][y] == 3 || a[x][y] == 4) return 0;
    return 1;
}

void solve(int sx, int sy, int ex, int ey)
{
    queue<pair<pair<int, int>, int> >q;
    while (!q.empty()) q.pop();
    q.push(make_pair(make_pair(sx, sy), 1));
    while (!q.empty())
    {
        int curx = q.front().first.first, cury = q.front().first.second, curstep = q.front().second;
        q.pop();
        for (int i = 1; i <= 4; i++)
        {
            int nx = curx + px[i], ny = cury + py[i];
            if (nx + px[i] == ex && ny + py[i] == ey)
            {
                ans = min(ans, curstep + 1);
                continue;
            }
            if (check(nx, ny))
            {
                if (vis[nx + px[i]][ny + py[i]]) continue;
                else
                {
                    vis[nx + px[i]][ny + py[i]] = 1;
                    q.push(make_pair(make_pair(nx + px[i], ny + py[i]), curstep + 1));
                }
            }
        }
    }
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        ans = INT_MAX;
        int sx, sy, ex, ey;
        int r, c; scanf("%d%d", &r, &c);
        csize = c * 5 + c + 1 + 2; rsize = r * 2 + 1 + r * 2 + 1 + 1;
        for (int i = 1; i <= rsize; i++)
            for (int j = 1; j <= csize; j++)
                vis[i][j] = 0;
        cin.get();
        for (int cnt = 1; cnt <= 4 * r + 3; cnt++)
        {
            string s;
            getline(cin, s);
            int len = s.size();
            for (int i = 0; i < len; i++)
            {
                if (s[i] == ' ') a[cnt][i + 1] = 0;
                else if (s[i] == '+') a[cnt][i + 1] = 1;
                else if (s[i] == '-') a[cnt][i + 1] = 2;
                else if (s[i] == '\\') a[cnt][i + 1] = 3;
                else if (s[i] == '/') a[cnt][i + 1] = 4;
                else
                {
                    if (s[i] == 'S') sx = cnt, sy = i + 1;
                    else if (s[i] == 'T') ex = cnt, ey = i + 1;
                }
            }
        }
        vis[sx][sy] = 1;
        solve(sx, sy, ex, ey);
        printf("%d\n", ans);
    }
    return 0;
}
