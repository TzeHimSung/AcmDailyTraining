#include <iostream>
#include <cmath>

using namespace std;

const int lim = 1000000;

int main() {
    freopen("./Newbie_Cup_Problem/data/6.in", "r", stdin);

    int n, flag = 1; scanf("%d", &n);
    while (n--) {
        int x, y; scanf("%d%d", &x, &y);
        if (abs(x) > lim || abs(y) > lim) flag = 0;
    }

    if (!flag) cout << "error" << endl; else cout << "correct" << endl;

    fclose(stdin);
    return 0;
}