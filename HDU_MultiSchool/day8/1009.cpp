/* Codeforces Contest 2019_mutc_08
 * Problem I
 * Au: SJoshua
 */
#include <set>
#include <unordered_map>
#include <queue>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

bool board[20][20];

const int movement[4][2] = {
    {0, -1}, {0, 1}, {1, 0}, {-1, 0}
};

struct node {
    int x, y;
};

struct rect {
    int x1, y1, x2, y2;
    void fill(void) {
        for (int x = x1; x <= x2; x++) {
            board[x][y1] = board[x][y2] = true;
        }
        for (int y = y1; y <= y2; y++) {
            board[x1][y] = board[x2][y] = true;
        }
    }
};

void init(void) {
    memset(board, 0, sizeof(board));
}

int calc(void) {
    int ans = 0;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (!board[i][j]) {
                queue <node> info;
                info.push({i, j});
                while (!info.empty()) {
                    auto t = info.front();
                    info.pop();
                    if (board[t.x][t.y]) {
                        continue;
                    }
                    board[t.x][t.y] = true;
                    for (int k = 0; k < 4; k++) {
                        int nx = t.x + movement[k][0], ny = t.y + movement[k][1];
                        if (0 <= nx && nx < 20 && 0 <= ny && ny < 20 && !board[nx][ny]) {
                            info.push({nx, ny});
                        }
                    }
                }
                ans++;
            }
        }
    }
    return ans;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        vector <int> vec(8);
        set <int> hash;
        unordered_map <int, int> mp;
        for (int i = 0; i < 8; i++) {
            cin >> vec[i];
            hash.insert(vec[i]);
        }
        int cur = 1;
        for (auto e : hash) {
            mp[e] = cur;
            cur += 2;
        }
        rect A = {mp[vec[0]], mp[vec[1]], mp[vec[2]], mp[vec[3]]};
        rect B = {mp[vec[4]], mp[vec[5]], mp[vec[6]], mp[vec[7]]};
        init();
        A.fill();
        B.fill();
        cout << calc() << endl;
    }
    return 0;
}