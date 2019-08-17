/* Nowcoder Contest 890
 * Problem E
 * Au: SJoshua
 */
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
struct cord {
    int x, y;
    unsigned long long int dis;
};
 
bool inRange(unsigned long long int n, unsigned long long int a, unsigned long long int b) {
    return a <= n && n <= b;
}
//LURD
unsigned long long int calc(int x, int y, unsigned long long int base, int size, int mode = 2) {
    // cout << x << ", " << y << ": " << base << "(" << size << ")"<<mode<< endl;
    if (!size) {
        return base;
    }
    int half = 1 << (size - 1);
    unsigned long long int block = (unsigned long long int) half * half;
    if (inRange(x, 1, half) && inRange(y, 1, half)) {
        switch (mode) {
            case 1: return calc(x, y, base + block * 0, size - 1, 2);
            case 2: return calc(x, y, base + block * 0, size - 1, 1);
            case 3: return calc(x, y, base + block * 2, size - 1, 3);
            case 4: return calc(x, y, base + block * 2, size - 1, 4);
        }
    } else if (inRange(x, 1, half) && inRange(y, 1 + half, half + half)) {
        switch (mode) {
            case 1: return calc(x, y - half, base + block * 1, size - 1, 1);
            case 2: return calc(x, y - half, base + block * 3, size - 1, 3);
            case 3: return calc(x, y - half, base + block * 3, size - 1, 2);
            case 4: return calc(x, y - half, base + block * 1, size - 1, 4);
        }
    } else if (inRange(x, 1 + half, half + half) && inRange(y, 1, half)) {
        switch (mode) {
            case 1: return calc(x - half, y, base + block * 3, size - 1, 4);
            case 2: return calc(x - half, y, base + block * 1, size - 1, 2);
            case 3: return calc(x - half, y, base + block * 1, size - 1, 3);
            case 4: return calc(x - half, y, base + block * 3, size - 1, 1);
        }
    } else if (inRange(x, 1 + half, half + half) && inRange(y, 1 + half, half + half)) {
        switch (mode) {
            case 1: return calc(x - half, y - half, base + block * 2, size - 1, 1);
            case 2: return calc(x - half, y - half, base + block * 2, size - 1, 2);
            case 3: return calc(x - half, y - half, base + block * 0, size - 1, 4);
            case 4: return calc(x - half, y - half, base + block * 0, size - 1, 3);
        }
    }
    return 0;
}
 
int main(void) {
    int n, k;
    cin >> n >> k;
    vector <cord> pos(n);
    for (int i = 0; i < n; i++) {
        cin >> pos[i].x >> pos[i].y;
        pos[i].dis = calc(pos[i].x, pos[i].y, 0, k);
    }
    sort(pos.begin(), pos.end(), [](cord &a, cord &b)->bool {
        return a.dis < b.dis;
    });
    for (auto e: pos) {
        cout << e.x << " " << e.y /* << "->" << e.dis*/ << endl;
    }
    return 0;
}
