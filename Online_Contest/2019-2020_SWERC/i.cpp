#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int n1, n2, n12;
    cin >> n1 >> n2 >> n12;
    cout << (int)floor(1.0 * (n1 + 1) * (n2 + 1) / (n12 + 1) - 1);
}