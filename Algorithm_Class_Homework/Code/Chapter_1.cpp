#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int main() {
    int l = 0, r = INT_MAX, ans;
    while (l <= r) {
        int mid = l + r >> 1;
        if (1000 * mid * mid <= pow(2, mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}