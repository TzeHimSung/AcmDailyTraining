#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;
const int maxn = 1500;

int M[maxn][maxn];
int Link[maxn], Left[maxn], Right[maxn];
string s;
vector<int> ans;

bool CMP(int a, int b) {
    return a > b;
}

int main() {
    int n, m;
    int fmax = 0, smax = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 1; j <= m; j++) {
            M[i][j] = s[j - 1] - '0';
        }
    }
    for (int i = 1; i <= m; i++) {
        Link[i] = 0;
        Left[i] = 1;
        Right[i] = m ;
    }
    int hight, width;
    for (int i = 1; i <= n; i++) {
        int nowl = 0;
        for (int j = 1; j <= m; j++) {
            if (M[i][j] == 0) {
                Link[j] = 0;
                nowl = j;
                Left[j] = 1;
            } else {
                Left[j] = max(Left[j], nowl + 1);
                Link[j] ++;
            }
        }
        int nowr = m + 1 ;
        set<int> S;
        S.clear();
        for (int j = m; j >= 1; j--) {
            if (M[i][j] == 0) {
                nowr = j ;
                Right[j] = m;
                S.clear();
            } else {
                Right[j] = min(nowr - 1, Right[j]);
                int s = (Link[j] * (Right[j] - Left[j] + 1));
                if (S.count(s)) {
                    continue;
                }
                S.insert(s);
                if (s >= fmax) {
                    smax = fmax;
                    fmax = s;
                    hight = Link[j];
                    width = (Right[j] - Left[j] + 1);
                } else if (s > smax) {
                    smax = s;
                }
            }
        }
    }
    cout << max(smax, max(hight * (width - 1), (hight - 1) * width)) << endl;
    return 0;
}