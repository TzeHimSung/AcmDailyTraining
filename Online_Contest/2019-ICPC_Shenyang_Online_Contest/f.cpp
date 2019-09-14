/* Contest shenyang_2019_online
 * Problem F
 * Team: Make One For Us
 */
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    long long int n, k;
    while (scanf("%lld %lld", &n, &k) != EOF) {
        vector <long long int> arr(n);
        map <long long int, int> cnt;
        long long int sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &arr[i]);
            cnt[arr[i]]++;
            sum += arr[i];
        }
        vector <pair <long long int, int>> vec;
        for (auto e : cnt) {
            vec.emplace_back(make_pair(e.first, e.second));
            // cerr << e.first << ", " << e.second << endl;
        }
        // array: less to more
        long long int n_min = vec.front().first, n_max = vec.back().first, rem = k;
        int cur = 0;
        for (unsigned int i = 0; i < vec.size() - 1; i++) {
            cur += vec[i].second;
            auto delta = (vec[i + 1].first - vec[i].first) * cur;
            if (rem >= delta) {
                rem -= delta;
                n_min = vec[i + 1].first;
            } else {
                n_min = vec[i].first + rem / cur;
                break;
            }
        }
        cur = 0;
        rem = k;
        for (unsigned int i = vec.size() - 1; i > 0; i--) {
            cur += vec[i].second;
            auto delta = (vec[i].first - vec[i - 1].first) * cur;
            if (rem >= delta) {
                rem -= delta;
                n_max = vec[i - 1].first;
            } else {
                n_max = vec[i].first - rem / cur;
                break;
            }
        }
        printf("%lld\n", n_min < n_max ? n_max - n_min : ((sum % n) ? 1 : 0));
    }
    return 0;
}
