#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const ll maxn = 1e6;
int m, sumx, sumy;
int x[6], y[6], round = 0;
bool flag;
void print(int a, int b)
{
    printf("%d:%d", a, b);
}
void run(int a, int b, bool sw) //a win
{
    int f = sumx, k = sumy;
    if(a + b == 5)
    {
        x[1] = 25;
        x[2] = 25;
        x[3] = 15;
        y[4] = 25;
        y[5] = 25;
        f -= 65;
        k -= 50;
    }
    else
    {
        int now = 0;
        int t = a;
        while(t--)
        {
            now++;
            x[now] = 25;
            f -= 25;
        }
        t = b;
        while(t--)
        {
            now++;
            y[now] = 25;
            k -= 25;
        }
    }
    if(f < 0 || k < 0) return;
    if(f > k)
    {
        int j = f - k;
        if(j > b * 23) return;
        if(j > 23)
        {
            x[4] = 23;
            x[5] = j - 23;
        }
        else x[4] = j;
        f -= j;
    }
    if(k > f)
    {
        int j = k - f;
        if(a + b == 5)
        {
            if(j > 59) return;
            k = f;
            if(j >= 23)
            {
                y[1] = 23;
                j -= 23;
            }
            else
            {
                y[1] = j;
                j = 0;
            }
            if(j >= 23)
            {
                y[2] = 23;
                j -= 23;
            }
            else
            {
                y[2] = j;
                j = 0;
            }
            y[3] = j;
        }
        else
        {
            if(j > (a) * 23)return;
            if(j >= 23)
            {
                y[1] = 23;
                j -= 23;
            }
            else
            {
                y[1] = j;
                j = 0;
            }
            if(j >= 23)
            {
                y[2] = 23;
                j -= 23;
            }
            else
            {
                y[2] = j;
                j = 0;
            }
            y[3] = j;
            k = f;
        }
    }
    if(k == f)
    {
        x[1] += k;
        y[1] += f;
        flag = true;
        if(sw)
        {
            swap(x, y);
            swap(a, b);
        }
        printf("%d:%d\n", a, b);
        printf("%d:%d ", x[1], y[1]);
        printf("%d:%d ", x[2], y[2]);
        if(sw)swap(a, b);
        if(b >= 1)printf("%d:%d ", x[4], y[4]);
        if(b >= 2)printf("%d:%d ", x[5], y[5]);
        printf("%d:%d ", x[3], y[3]);
        puts("");
        flag = true;
    }
}
void mem()
{
    memset(x, 0, sizeof x);
    memset(y, 0, sizeof y);
}
int main()
{
    freopen("input.txt", "r", stdin);
    scanf("%d", &m);
    flag = false;
    while(m--)
    {
        scanf("%d%d", &sumx, &sumy);
        if(!flag) run(3, 0, false); mem();
        if(!flag) run(3, 1, false); mem();
        if(!flag) run(3, 2, false); mem();
        swap(sumx, sumy);
        if(!flag) run(3, 2, true); mem();
        if(!flag) run(3, 1, true); mem();
        if(!flag) run(3, 0, true); mem();
        if(!flag)
            puts("Impossible");
        flag = false;
    }
    fclose(stdin);
    return 0;
}
