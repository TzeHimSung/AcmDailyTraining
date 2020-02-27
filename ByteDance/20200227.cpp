/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define pb emplace_back
#define mp make_pair
#define eps 1e-8
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

struct ChessBoard {
    int a[4][4];
    string op;

    void init() {
        cin >> op;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                cin >> a[i][j];
    }

    void up() {
        for (int j = 0; j < 4; j++) {
            stack<int>st;
            while (st.size()) st.pop();
            for (int i = 3; i >= 0; i--) {
                if (a[i][j]) st.push(a[i][j]);
                a[i][j] = 0;
            }
            int i = 0;
            while (st.size()) {
                int k = st.top(); st.pop();
                if (st.empty()) {
                    a[i++][j] = k;
                    break;
                }
                if (k == st.top()) {
                    a[i++][j] = k + st.top();
                    st.pop();
                } else {
                    a[i++][j] = k;
                }
            }
        }
    }

    void down() {
        for (int j = 0; j < 4; j++) {
            stack<int>st;
            while (st.size()) st.pop();
            for (int i = 0; i < 4; i++) {
                if (a[i][j]) st.push(a[i][j]);
                a[i][j] = 0;
            }
            int i = 3;
            while (st.size()) {
                int k = st.top(); st.pop();
                if (st.empty()) {
                    a[i--][j] = k;
                    break;
                }
                if (k == st.top()) {
                    a[i--][j] = k + st.top();
                    st.pop();
                } else {
                    a[i--][j] = k;
                }
            }
        }
    }

    void left() {
        for (int i = 0; i < 4; i++) {
            stack<int>st;
            while (st.size()) st.pop();
            for (int j = 3; j >= 0; j--) {
                if (a[i][j]) st.push(a[i][j]);
                a[i][j] = 0;
            }
            int j = 0;
            while (st.size()) {
                int k = st.top(); st.pop();
                if (st.empty()) {
                    a[i][j++] = k;
                    break;
                }
                if (k == st.top()) {
                    a[i][j++] = k + st.top();
                    st.pop();
                } else {
                    a[i][j++] = k;
                }
            }
        }
    }

    void right() {
        for (int i = 0; i < 4; i++) {
            stack<int>st;
            while (st.size()) st.pop();
            for (int j = 0; j < 4; j++) {
                if (a[i][j]) st.push(a[i][j]);
                a[i][j] = 0;
            }
            int j = 3;
            while (st.size()) {
                int k = st.top(); st.pop();
                if (st.empty()) {
                    a[i][j--] = k;
                    break;
                }
                if (k == st.top()) {
                    a[i][j--] = k + st.top();
                    st.pop();
                } else {
                    a[i][j--] = k;
                }
            }
        }
    }

    void solve() {
        for (auto i : op) {
            switch (i) {
                // up
                case '1':
                    up();
                    break;
                // down
                case '2':
                    down();
                    break;
                // left
                case '3':
                    left();
                    break;
                // right
                case '4':
                    right();
                    break;
            }
        }
    }

    void print() {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                printf("%d%c", a[i][j], j == 3 ? '\n' : ' ');
    }

} chessBoard;

int main() {
    chessBoard.init();
    chessBoard.solve();
    chessBoard.print();
    return 0;
}