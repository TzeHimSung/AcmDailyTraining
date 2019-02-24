#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
struct node
{
    int x, y;
} tmp;
struct nod
{
    int a, b, c, d;
};
nod ac[2000];
queue<node>q;
int f[10][10][10][10], num;
int u[8] = {1, 2, -1, -2, -1, 2, 1, -2};
int v[8] = {2, 1, -2, -1, 2, -1, -2, 1};
int vis[10][10];
void bfs(int x, int y)
{
    f[x][y][x][y] = 1;
    tmp.x = x, tmp.y = y;
    q.push(tmp);
    while(!q.empty())
    {
        tmp = q.front(), q.pop();
        int ux = tmp.x, uy = tmp.y;
        for(int i = 0; i < 8; i++)
        {
            int vx = ux + u[i], vy = uy + v[i];
            if(vx > 0 && vx < 9 && vy > 0 && vy < 9 && !f[x][y][vx][vy])
            {
                f[x][y][vx][vy] = f[x][y][ux][uy] + 1;
                tmp.x = vx, tmp.y = vy;
                q.push(tmp);
            }
        }
    }
}
char s[10];
void mov(int a, int b, int c, int d)
{
    if(a == c && b == d)
        return;
    for(int i = 0; i < 8; i++)
    {
        int vx = a + u[i], vy = b + v[i];
        if(vx > 0 && vx < 9 && vy > 0 && vy < 9 && f[a][b][c][d] - 1 == f[vx][vy][c][d])
        {
            if(vis[vx][vy])
            {
                mov(vx, vy, c, d);
                num++;
                ac[num].a = a, ac[num].b = b, ac[num].c = vx, ac[num].d = vy;
            }
            else
            {
                num++;
                ac[num].a = a, ac[num].b = b, ac[num].c = vx, ac[num].d = vy;
                mov(vx, vy, c, d);
            }
            break;
        }
    }
}
int main()
{
    for(int i = 1; i <= 8; i++)
        for(int j = 1; j <= 8; j++)
            bfs(i, j);
    int n;
    scanf("%d", &n);
    int nx = 1, ny = 1;
    for(int i = 1; i <= n; i++)
    {
        scanf("%s", s);
        int x = s[0] - 'a' + 1, y = s[1] - '0';
        vis[x][y] = 1;
    }
    while(vis[nx][ny])
    {
        nx++;
        if(nx == 9)
            nx = 1, ny++;
        if(ny > 8)
        {
            printf("0\n");
            return 0;
        }
    }
    int flag = 0;
    for(int y = 1; y <= 8; y++)
    {
        for(int x = 1; x <= 8; x++)
            if(vis[x][y] && (y > ny || (y == ny && x > nx)))
            {
                mov(x, y, nx, ny);
                vis[x][y] = 0, vis[nx][ny] = 1;
                while(vis[nx][ny])
                {
                    nx++;
                    if(nx == 9)
                        nx = 1, ny++;
                    if(ny > 8)
                    {
                        flag = 1;
                        break;
                    }
                }
                if(flag)
                    break;
            }
        if(flag)
            break;
    }
    printf("%d\n", num);
    for(int i = 1; i <= num; i++)
        printf("%c%c-%c%c\n", ac[i].a + 'a' - 1, ac[i].b + '0', ac[i].c + 'a' - 1, ac[i].d + '0');
    return 0;
}