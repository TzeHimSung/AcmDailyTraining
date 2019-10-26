#include <iostream>
#include <cmath>
#include <random>

using namespace std;

const int mod = 2000001;
const int shift = 1000000;
mt19937 rnd(time(0));

void makeRandomData() {
    int n = rnd() % 1000 + 1;
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        uniform_int_distribution<int> dis(-1000000, 1000000);
        int x = dis(rnd), y = dis(rnd);
        cout << x << " " << y << endl;
    }
}

void makeExtreData() {
    int n = 1000;
    cout << n << endl;
    for (int i = 1; i <= n; i++)
        cout << shift*(rnd() & 1 ? 1 : -1) << " " << shift*(rnd() & 1 ? -1 : 1) << endl;
}

int main() {
    freopen("./Newbie_Cup_Problem/data/6.in", "w", stdout);

    // makeRandomData();
    makeExtreData();

    fclose(stdout);
    return 0;
}