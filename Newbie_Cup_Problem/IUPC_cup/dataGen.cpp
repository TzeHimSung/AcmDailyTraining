#include <iostream>
#include <random>

using namespace std;

const int n_lim = 1e5;
mt19937 rnd(time(0));

void makeRandomData() {
    int n = rnd() % n_lim + 1;
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        int curr = rnd() % 2;
        if (!curr) cout << 1;
        else cout << rnd() % 2 + 2;
    }
    cout << endl;
}

void makeExtreData() {
    cout << n_lim << endl;

}

int main() {
    freopen("./Newbie_Cup_Problem/IUPC_cup/data/2.in", "w", stdout);

    int t = 10;
    cout << t << endl;
    while (t--) {
        makeRandomData();
    }

    fclose(stdout);
    return 0;
}