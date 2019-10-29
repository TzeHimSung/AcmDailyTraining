// problem 1009 std
#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long

using namespace std;

const int maxn = 1010;
struct Vector {
    ll x, y;
    Vector() {}
    Vector(int a, int b): x(a), y(b) {}
    // 重载<号。定义不同向量如何比较大小，通过斜率判断优先级
    // atan2这个函数返回方位角的弧度，取值范围为(-pi,pi]
    bool operator<(const Vector &rhs)const {
        return atan2(y, x) < atan2(rhs.y, rhs.x);
    }
};
Vector a[maxn];

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll ans = 0;
        int n, p = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int x, y; cin >> x >> y;
            if (x || y) a[++p] = Vector(x, y);
            // 为什么不能x和y同为0，因为待会要利用atan2这个函数进行排序，当x和y同为0时atan2返回undefined
        }
        n = p;
        // 排序，因为Vector重载了<号，所以直接sort即可
        sort(a + 1, a + 1 + n);
        // 依次枚举每个向量作为本次扫描的起点
        for (int start_position = 1; start_position <= n; start_position++) {
            int current_position = start_position;
            ll current_x = 0, current_y = 0;
            for (int i = 1; i <= n; i++) {
                // 更新当前zzy的坐标(x,y)并更新答案
                current_x += a[current_position].x, current_y += a[current_position].y;
                ans = max(ans, current_x * current_x + current_y * current_y);
                // 如果扫到数组尾部，记得回到数组头部
                if (++current_position > n) current_position = 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}