; class Solution {
public:
    bool hasGroupsSizeX(vector<int> &deck) {
        map<int, int>cnt;
        for (auto i : deck) cnt[i]++;
        int gcd = cnt.begin()->second;
        for (auto i : cnt) gcd = __gcd(gcd, i.second);
        return gcd != 1;
    }
};
