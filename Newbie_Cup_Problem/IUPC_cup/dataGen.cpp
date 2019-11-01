#include <iostream>
#include <random>

using namespace std;

const int n_lim = 1e5;
mt19937 rnd(time(0));

void makeAllOne(int n) {
    cout << n << endl;
    for (int i = 1; i <= n; i++) cout << "1";
    cout << endl;
}

void makeNoOne(int n) {
    cout << n << endl;
    for (int i = 1; i <= n; i++) cout << rnd() % 2 + 2;
    cout << endl;
}

void makeIntensiveData() {
    int n = rnd() % n_lim + 1;
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        int curr = rnd() % 2;
        if (!curr) cout << 1;
        else cout << rnd() % 2 + 2;
    }
    cout << endl;
}

void makeSparseData() {
    int n = rnd() % n_lim + 1;
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        int curr = rnd() % 4;
        if (!curr) cout << 1;
        else cout << rnd() % 2 + 2;
    }
    cout << endl;
}

void makeExtreData() {
    makeAllOne(1);
    makeAllOne(n_lim);
    makeNoOne(1);
    makeNoOne(n_lim);
    for (int i = 1; i <= 6; i++) {
        if (i & 1) makeIntensiveData();
        else makeSparseData();
    }
}

int main() {
    freopen("./Newbie_Cup_Problem/IUPC_cup/data/3.in", "w", stdout);

    // int t = 10;
    // cout << t << endl;
    // while (t--) {
    //     if (t & 1) makeIntensiveData();
    //     else makeSparseData();
    // }
    // makeExtreData();
    cout << n_lim << endl;
    for (int i = 1; i < n_lim; i++) cout << 2;
    cout << 1 << endl;

    fclose(stdout);
    return 0;
}