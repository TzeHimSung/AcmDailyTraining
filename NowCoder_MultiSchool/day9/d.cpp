/* Nowcoder Contest 889
 * Problem D
 * Au: SJoshua
 */
#include <unordered_map>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int n;
    unsigned long long int s;
    cin >> n >> s;
    vector <unsigned long long int> nums(n);
    unordered_map <unsigned long long int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int half = n / 2;
    for (int i = 0; i < (1 << half); i++) {
        unsigned long long int cur = 0;
        for (int j = 0; j < half; j++) {
            cur += ((i >> j) & 1) * nums[j];
        }
        mp[cur] = i;
    }
    for (int i = 0; i < (1 << (n - half)); i++) {
        unsigned long long int cur = 0;
        for (int j = 0; j < n - half; j++) {
            cur += ((i >> j) & 1) * nums[half + j];
        }
        if (cur <= s) {
            if (mp.count(s - cur)) {
                int a = mp[s - cur];
                for (int j = 0; j < half; j++) {
                    cout << ((a >> j) & 1);
                }
                for (int j = half; j < n; j++) {
                    cout << ((i >> (j - half)) & 1);
                }
                cout << endl;
                return 0;
            }
        }
    }
    return 0;
}