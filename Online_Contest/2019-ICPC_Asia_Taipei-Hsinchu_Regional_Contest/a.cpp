#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
struct board {
    int arr[6][6];
    board() {
        memset(arr, 0, sizeof(arr));
    }
};
//EW:1 NS:2
int towards[11];
int len[11];
struct state {
    int x[11];
    int y[11];
    bool operator==(const state &b)const {
        for (int i = 1; i <= 10; ++i) if (x[i] != b.x[i] || y[i] != b.y[i]) return false;
        return true;
    }
};
struct myHash {
    size_t operator()(state State) const {
        size_t hash = 0;
        for (int i = 1; i <= 10; ++i) {
            hash = hash * 7 + size_t(State.x[i]);
            hash = hash * 7 + size_t(State.y[i]);
        }
        return hash;
    }
};
board st;
state st_state;
queue< pair<int, state> > que;
unordered_set<state, myHash> Set;
board generateBoard(state State) {
    board rnt;
    for (int i = 1; i <= 10; ++i)
        if (towards[i] > 0) {
            int dx = 0, dy = 0;
            int x = State.x[i];
            int y = State.y[i];
            if (towards[i] == 1) dy = 1;
            else dx = 1;
            for (int j = 0; j < len[i]; ++j) {
                rnt.arr[x][y] = i;
                x += dx; y += dy;
            }
        }
    return rnt;
}
void output(int s, state State) {
    //return;
    cout << "s=" << s << endl;
    board Board = generateBoard(State);
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) cout << Board.arr[i][j] << ' ';
        cout << endl;
    }
    system("pause");
}
int bfs() {
    que.push(pair<int, state>(0, st_state));
    Set.insert(st_state);
    while (!que.empty()) {
        auto tmp = que.front();
        int nows = tmp.first;
        state nowstate = tmp.second;
        que.pop();
        if (nows == 10) continue;
        board nowboard = generateBoard(nowstate);
        for (int i = 1; i <= 10; ++i) {
            //positive
            if (towards[i] == 0) continue;
            state tmpstate = nowstate;
            int dx = 0, dy = 0;
            if (towards[i] == 1) dy = 1;
            else dx = 1;
            for (int j = 1; j <= 1; ++j) {
                //positive
                if (nowstate.x[i] + dx * (len[i] + j - 1) < 6 &&
                        nowstate.y[i] + dy * (len[i] + j - 1) < 6 &&
                        nowboard.arr[nowstate.x[i] + dx * (len[i] + j - 1)][nowstate.y[i] + dy * (len[i] + j - 1)] == 0) {
                    tmpstate.x[i] = nowstate.x[i] + dx * j;
                    tmpstate.y[i] = nowstate.y[i] + dy * j;
                    if (Set.find(tmpstate) == Set.end()) {
                        if (tmpstate.y[1] + len[1] - 1 == 5) {
                            //output(nows+1,tmpstate);
                            if (nows + 1 + len[1] <= 10) return nows + 1 + len[1];
                            return -1;
                        }
                        //output(nows+1,tmpstate);
                        que.push(pair<int, state>(nows + 1, tmpstate));
                        Set.insert(tmpstate);
                    }
                } else break;
            }
            for (int j = 1; j <= 1; ++j) {
                if (nowstate.x[i] - dx * j >= 0 &&
                        nowstate.y[i] - dy * j >= 0 &&
                        nowboard.arr[nowstate.x[i] - dx * j][nowstate.y[i] - dy * j] == 0) {
                    tmpstate.x[i] = nowstate.x[i] - dx * j;
                    tmpstate.y[i] = nowstate.y[i] - dy * j;
                    if (Set.find(tmpstate) == Set.end()) {
                        if (tmpstate.y[1] + len[1] - 1 == 5) {
                            //output(nows+1,tmpstate);
                            if (nows + 1 + len[1] <= 10) return nows + 1 + len[1];
                            return -1;
                        }
                        //output(nows+1,tmpstate);

                        que.push(pair<int, state>(nows + 1, tmpstate));
                        Set.insert(tmpstate);
                    }
                } else break;
            }
        }
    }
    return -1;
}
int main() {
    for (int i = 0; i < 6; ++i)
        for (int j = 0; j < 6; ++j) scanf("%d", &st.arr[i][j]);
    for (int i = 0; i < 6; ++i)
        for (int j = 0; j < 6; ++j)
            if (st.arr[i][j] > 0) {
                int t = st.arr[i][j];
                if (towards[t] > 0) continue;
                st_state.x[t] = i;
                st_state.y[t] = j;
                int dx = 0, dy = 0;
                if (j + 1 < 6 && st.arr[i][j + 1] == t) {
                    towards[t] = 1;
                    dy = 1;
                } else {
                    towards[t] = 2;
                    dx = 1;
                }
                int x = i, y = j;
                len[t] = 0;
                while (st.arr[x][y] == t) {
                    len[t]++;
                    x += dx; y += dy;
                }
            }
    if (st_state.x[1] != 2 || towards[1] != 1) {
        printf("-1\n");
        return 0;
    }
    printf("%d", bfs());
}