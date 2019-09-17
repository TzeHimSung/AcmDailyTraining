#include <iostream>

using namespace std;

const int maxn = 1024 + 10;
long long n = 1, k;

void output(int a[][maxn]) {
    for (int i = 1; i <= n; i++) {
        if (i == 1) cout << "Ball team: ";
        else cout << "    Day " << i - 1 << ": ";
        for (int j = 1; j <= n; j++) cout << a[i][j] << " ";
        cout << endl;
    }
}

void solve(int a[][maxn], long long n, int x, int y) {
    if (n == 2) {
        a[x + 1][y + 1] = a[x][y];
        a[x + 1][y] = a[x][y + 1];
        return;
    }
    solve(a, n / 2, x, y); solve(a, n / 2, x, y + n / 2);
    for (int i = x; i < x + n / 2; i++)
        for (int j = y; j < y + n / 2; j++) {
            a[i + n / 2][j + n / 2] = a[i][j];
        }
    for (int i = x + n / 2; i < x + n; i++)
        for (int j = y; j < y + n / 2; j++) {
            a[i][j] = a[i - n / 2][j + n / 2];
        }
}

int main() {
    cout << "The k is: ";
    cin >> k;
    for (int i = 1; i <= k; i++) n <<= 1;
    cout << "The n is: " << n << endl;
    int a[n + 1][maxn];
    for (int i = 1; i <= n; i++) a[1][i] = i;
    solve(a, n, 1, 1);
    output(a);
    return 0;
}