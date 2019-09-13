#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int>a(10);

int check(int &x, int &y, int &z) {
    for (int i = 0; i < 3; i++) x = x * 10 + a[i];
    for (int i = 3; i < 5; i++) y = y * 10 + a[i];
    for (int i = 5; i < 10; i++) z = z * 10 + a[i];
    return x * y == z ? 1 : 0;
}

int main() {
    iota(a.begin(), a.end(), 0);
    do {
        int x = 0, y = 0, z = 0;
        check(x, y, z) ? printf("x = %d, y = %d, z = %d\n", x, y, z) : 0;
    } while (next_permutation(a.begin(), a.end()));
    return 0;
}
