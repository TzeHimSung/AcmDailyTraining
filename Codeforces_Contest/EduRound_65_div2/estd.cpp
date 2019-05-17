#include <bits/stdc++.h>

using namespace std;

const int N = int(1e6) + 10;
int n, x;
int a[N];
vector <int> pos[N]; //数字i出现过的所有位置
int prefMax[N]; //递增序列

int main()
{
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", a + i);
        pos[a[i]].push_back(i);
        prefMax[i] = max(a[i], (i > 0 ? prefMax[i - 1] : a[i]));
    }
    int p = 1, lst = n + 5; //lst是上一个数在数组出现的最左端的下标
    for (int i = x; i >= 1; --i)
    {
        if (pos[i].empty()) //没出现过这个数
        {
            p = i;
            continue;
        }
        if (pos[i].back() > lst) break; //不能有交错的区间
        p = i; //p是符合条件的最小数字
        lst = pos[i][0];
    }
    long long ans = 0;
    lst = -1;
    for (int l = 1; l <= x; ++l)
    {
        int r = max(l, p - 1); //符合条件的最小数字和当前数字比较
        if (lst != -1) r = max(r, prefMax[lst]);
        ans += x - r + 1;
        if (!pos[l].empty())
        {
            if (pos[l][0] < lst) break;
            lst = pos[l].back();
        }
    }
    cout << ans << endl;
    return 0;
}