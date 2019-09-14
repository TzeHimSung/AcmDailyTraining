/* Contest shenyang_2019_online
 * Problem H
 * Team: Make One For Us
 */
#include <bits/stdc++.h>

using namespace std;

struct info {
    string name, deck;
    int value(void) const {
        vector <int> cards;
        for (auto ch : deck) {
            if (ch == '1') {
                cards.emplace_back(10);
            } else if (ch == 'J') {
                cards.emplace_back(11);
            } else if (ch == 'Q') {
                cards.emplace_back(12);
            } else if (ch == 'K') {
                cards.emplace_back(13);
            } else if (ch == 'A') {
                cards.emplace_back(1);
            } else if (ch != '0') {
                cards.emplace_back(ch - '0');
            }
        }
        sort(cards.begin(), cards.end());

        int sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += cards[i];
        }

        bool flag = cards[0] == 1;
        for (int i = 1; i <= 4; i++) {
            if (cards[i] != 9 + i) {
                flag = false;
            }
        }
        if (flag) {
            return 900000000;
        }

        flag = true;
        for (int i = 0; i < 4; i++) {
            if (cards[i] + 1 != cards[i + 1]) {
                flag = false;
            }
        }
        if (flag) {
            return 800000000 + cards[4];
        }

        if (cards[0] == cards[3] || cards[1] == cards[4]) {
            return 700000000 + cards[2] * 100 + (sum - 4 * cards[2]);
        }

        if ((cards[0] == cards[2] && cards[3] == cards[4]) || (cards[0] == cards[1] && cards[2] == cards[4])) {
            return 600000000 + cards[2] * 10000 + (cards[0] ^ cards[2] ^ cards[4]);
        }

        if (cards[0] == cards[2] || cards[1] == cards[3] || cards[2] == cards[4]) {
            return 500000000 + cards[2] * 10000 + (sum - cards[2] * 3);
        }

        vector <int> pairs;

        for (int i = 0; i < 4; i++) {
            if (cards[i] == cards[i + 1]) {
                pairs.emplace_back(cards[i]);
            }
        }
        // Two pairs
        if (pairs.size() == 2) {
            return 400000000 + pairs[1] * 10000 + pairs[0] * 100 + (sum - 2 * pairs[1] - 2 * pairs[0]);
        }

        // Pair
        if (pairs.size() == 1) {
            return 300000000 + pairs[0] * 10000 + (sum - 2 * pairs[0]);
        }

        // High Card
        return sum;
    }
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector <info> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i].name >> data[i].deck;
    }
    sort(data.begin(), data.end(), [&] (const info & a, const info & b) {
        int va = a.value(), vb = b.value();
        return va == vb ? a.name < b.name : va > vb;
    });
    for (auto e : data) {
        cout << e.name << endl;
    }
    return 0;
}
