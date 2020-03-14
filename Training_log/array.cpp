#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> A{5, 4, 3, 2, 1};

int main() {
    next_permutation(A.begin(), A.end());
    for (auto i : A) cout << i << " ";
}