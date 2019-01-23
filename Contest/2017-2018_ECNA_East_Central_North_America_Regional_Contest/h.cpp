#include <iostream>
#include <cstdio>
#include <cstring>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
int dx[] = {0, 0, -1, -1, -1, 1, 1, 1};
int dy[] = {1, -1, 0, 1, -1, 0, 1, -1};
struct Node
{
    int x; int y;
};
int mp[123][123];
int n, m;
void bfs(int xx, int yy)
{
    queue<Node> q;
    Node a; a.x = xx; a.y = yy;
    mp[xx][yy] = 0;
    q.push(a);
    while(!q.empty())
    {
        Node now = q.front();
        q.pop();
        int x = now.x, y = now.y;
        for(int i = 0; i < 8; i++)
        {
            int nx = dx[i] + x, ny = dy[i] + y;
            if(mp[nx][ny])
            {
                Node aa;
                aa.x = nx; aa.y = ny;
                q.push(aa);
                mp[nx][ny] = 0;
            }
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d\n", &n, &m);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            char ch;
            ch = getchar();
            if(ch == '.')mp[i][j] = 0;
            else mp[i][j] = 1;
        }
        char ch = getchar();
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(mp[i][j])
            {
                ans++;
                bfs(i, j);
            }
    cout << ans;
    return 0;
}