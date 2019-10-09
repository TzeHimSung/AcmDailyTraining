#include <iostream>
#include <iomanip>

using namespace std;

const int maxn = 5, maxx = 0x3f3f3f3f;
int dis[maxn][maxn], closure[maxn][maxn];

void print() {
    cout << "The result of warshall algorithm is:" << endl;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            cout << setw(4) << closure[i][j];
        }
        cout << endl;
    }
    cout << "The result of floyd algorithm is:" << endl;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            cout << setw(4) << dis[i][j];
        }
        cout << endl;
    }
}

void buildGraph() {
    // init distance matrix
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            dis[i][j] = i == j ? 0 : maxx;
    // add edge
    dis[1][2] = 2, dis[1][3] = 6, dis[1][4] = 4;
    dis[2][3] = 3;
    dis[3][1] = 7, dis[3][4] = 1;
    dis[4][1] = 5, dis[4][3] = 12;
    // closure matrix init
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            closure[i][j] = (dis[i][j] || i == j) ? 1 : 0;
}

void warshall() {
    // warshall
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            for (int k = 1; k <= 4; k++) {
                closure[k][j] = (closure[i][j] && closure[k][i]) ? 1 : 0;
            }
        }
    }
}

void floyd() {
    // floyd
    for (int k = 1; k <= 4; k++) {
        for (int i = 1; i <= 4; i++) {
            for (int j = 1; j <= 4; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}

int main() {
    // build graph
    buildGraph();
    // solve
    warshall();
    floyd();
    // print answer
    print();
    return 0;
}