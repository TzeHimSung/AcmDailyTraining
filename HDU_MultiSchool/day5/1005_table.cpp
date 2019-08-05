#include<iostream>
#include<queue>
#include<algorithm>
#include<queue>
#include<cstdlib>

using namespace std;

const int maxn = 20;
int n;
struct Node {
    int a[maxn];
    int v[maxn];
    bool operator < (Node rhs) const {
        for (int i = 0; i < n - 1; i++) {
            if (v[i] != rhs.v[i]) {
                return v[i] < rhs.v[i];
            }
        }
    }
} A[maxn * 2000];

bool Cmp(Node a, Node b) {
    for (int i = 0; i < n - 1; i++) {
        if (a.v[i] != b.v[i]) {
            return a.v[i] < b.v[i];
        }
    }
}
int cnt = 0;
int main() {
    cin >> n;
    int Now[200];
    for (int i = 0; i < n; i++) Now[i] = i + 1;
    do {
        for (int i = 0; i < n; i++)
            A[cnt].a[i] = Now[i];
        for (int i = 1; i < n; i++)
            A[cnt].v[i - 1] = Now[i] - Now[i - 1];
        cnt++;
    } while (next_permutation(Now, Now + n));
    sort(A, A + cnt);
    for (int i = 0; i < cnt; i++) {
        cout << "Case # " << i + 1 << " ";
        // for (int j = 0; j < n; j++)
        //     cout << A[i].a[j] << " ";
        // cout << endl;
        for (int j = 0; j < n - 1; j++)
            cout << A[i].v[j] << " ";
        cout << endl;
    }
    return 0;
}