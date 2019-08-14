/* Codeforces Contest 2019_mutc_08
 * Problem J
 * Au: SJoshua
 */
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

struct info {
    string name;
    int score, penalty;
};

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, d;
        cin >> n >> d;
        vector <info> board(n);
        for (int i = 0; i < n; i++) {
            cin >> board[i].name >> board[i].score >> board[i].penalty;
        }
        sort(board.begin(), board.end(), [](info & a, info & b)->bool {
            return a.score == b.score ? a.penalty < b.penalty : a.score > b.score;
        });
        d *= 10;
        if ((n * d) % 100 == 50) {
            cout << board[(n * d) / 100].name << endl;
        } else {
            cout << "Quailty is very great" << endl;
        }
    }
    return 0;
}